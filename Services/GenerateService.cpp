#include "GenerateService.h"
#include "../Tasks/Executor.h"
#include "../Tasks/Orchestrator.h"
#include "../Tasks/PrimeGenerator.h"
#include "../Tasks/PrimeSync.h"
#include "../Tasks/TaskQueue.h"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

GenerateService::GenerateService() {}

std::string GenerateService::help() {
  return "Generate RSA key pair and save it to file\n"
         "Usage: RsaDemo generate [-n | --size (size of key)] [-o | --output "
         "(path to key file)] [-v | --verbose]\n"
         "For debugging purposes run with -v or --verbose flag";
}

int GenerateService::run(std::unordered_map<std::string, std::string> &args) {
  if (IService::run(args)) {
    return 0;
  }

  std::cout << "Starting key generation of length: "
            << fromArgs("length", "-1", args) << std::endl;

  _keySize = std::atoi(fromArgs("length", "16", args).c_str());

  generateKey();

  return -1;
}

void GenerateService::generateKey() {
  size_t primeSize = _keySize / 2;

  std::vector<PrimeGenerator *> primeGenerators;

  size_t genTaskCount = Orchestrator::getInstance().getWorkerCount();

  std::cout<<"Prime tasks = "<<genTaskCount<<std::endl;
  PrimeSync sync(genTaskCount);

  auto timeSinceEpoch = std::chrono::system_clock::now().time_since_epoch();
  size_t timeInMillis =
      std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch)
          .count();

  for (size_t i = 0; i < genTaskCount; ++i) {
    primeGenerators.push_back(
        new PrimeGenerator(primeSize, timeInMillis + i, sync));
  }

  TaskQueue &queue = TaskQueue::getInstance();

  for (int i = 0; i < genTaskCount; ++i) {
    std::cout<<"Pushing to queue"<<std::endl;
    queue.push(primeGenerators[i]);
  }

  sync.waitForSearchOver();
  std::cout<<"Wait over"<<std::endl;

  for (auto &generator : primeGenerators) {
    delete generator;
  }
}

GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {
      {"length", "n"}, {"help", "h"}, {"output", "o"}, {"entropy-source", "e"}, {"core-count","c"};
}

GenerateService::~GenerateService(){

}
