#include "GenerateService.h"
#include "Tasks/PrimeGenerator.h"
#include "Tasks/PrimeSync.h"
#include "Tasks/TaskQueue.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"

#include <Arithm/RsaEngine.h>
#include <ArithmInjector.h>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>
#include <ranges>
#include <thread>

GenerateService::GenerateService() : _logger(Logger::getInstance()) {}

std::string GenerateService::help() {
  return "Generate RSA key pair and save it to file\n"
         "Usage: RsaDemo generate [-n | --size (size of key)] [-o | --output "
         "(path to key file)] [-v | --verbose]\n"
         "For debugging purposes run with -v or --verbose flag";
}

int GenerateService::run(std::unordered_map<std::string, std::string> &args) {
  if (int result = IService::run(args)) {
    return result;
  }

  readData(args);

  auto [prime1, prime2] = generatePrimes();
  auto [prv, pub, mod] = createKey(prime1, prime2);

  _logger.info("prv", prv);
  _logger.info("pub", pub);
  _logger.info("mod", mod);

  RsaKey privateKey(prv, mod);
  RsaKey publicKey(pub, mod);

  std::ofstream publicFile(_outputFile + ".pub");
  std::ofstream privateFile(_outputFile + ".prv");

  publicKey.save(publicFile);
  privateKey.save(privateFile);

  return 0;
}

std::tuple<KCrypt::Numeric, KCrypt::Numeric, KCrypt::Numeric>
GenerateService::createKey(KCrypt::Numeric &prime1, KCrypt::Numeric &prime2) {

  KCrypt::RsaEngine rsa(KCrypt::ArithmInjector::getInstance());

  KCrypt::Numeric prv(_keySize);
  KCrypt::Numeric pub(_keySize);
  KCrypt::Numeric mod(_keySize);

  rsa.generateKey(prime1.getBuffer(), prime2.getBuffer(), prv.getBuffer(),
                  pub.getBuffer(), mod.getBuffer());

  return std::make_tuple(pub, prv, mod);
}

void GenerateService::readData(
    std::unordered_map<std::string, std::string> &args) {

  std::string defaultThreadCount =
      std::to_string(std::thread::hardware_concurrency());

  _keySize = std::atoi(fromArgs("length", "16", args).c_str());
  _coreCount =
      std::atoi(fromArgs("core-count", defaultThreadCount, args).c_str());
  _outputFile = fromArgs("output", "id_rsa", args);
}

std::tuple<KCrypt::Numeric, KCrypt::Numeric> GenerateService::generatePrimes() {

  size_t genTaskCount = std::max((size_t)2, _coreCount);

  TaskQueue &queue = TaskQueue::getInstance();

  PrimeSync sync(genTaskCount);

  auto primeGenerators = splitTasks(genTaskCount, _keySize / 2, sync);

  for (int i = 0; i < genTaskCount; ++i) {
    queue.push(primeGenerators[i]);
  }

  sync.waitForSearchOver();

  auto primeRange = primeGenerators |
                    std::views::filter([](const PrimeGenerator *generator) {
                      return generator->isDone();
                    }) |
                    std::views::take(2) |
                    std::views::transform([](const PrimeGenerator *gen) {
                      return gen->candidate;
                    });

  auto primes = std::make_tuple(*primeRange.begin(), *++primeRange.begin());

  dispose(primeGenerators);

  return primes;
}

std::vector<PrimeGenerator *> GenerateService::splitTasks(size_t taskCount,
                                                          size_t primeSize,
                                                          PrimeSync &sync) {

  auto timeSinceEpoch = std::chrono::system_clock::now().time_since_epoch();

  size_t timeInMillis =
      std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch)
          .count();

  _logger.debug("Seed", timeInMillis);

  std::vector<PrimeGenerator *> primeGenerators;

  for (size_t i = 0; i < taskCount; ++i) {
    primeGenerators.push_back(
        new PrimeGenerator(primeSize, timeInMillis + i, sync));
  }
  return primeGenerators;
}

void GenerateService::dispose(const std::vector<PrimeGenerator *> tasks) {
  for (auto &generator : tasks) {
    delete generator;
  }
}

GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {{"length", "n", false},
          {"help", "h", true},
          {"output", "o", false},
          {"entropy-source", "e", false},
          {"core-count", "c", false}};
}

GenerateService::~GenerateService() {}
