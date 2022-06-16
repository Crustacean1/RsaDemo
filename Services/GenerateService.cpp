#include "GenerateService.h"
#include "../Tasks/Executor.h"
#include "../Tasks/PrimeGenerator.h"
#include "../Tasks/TaskQueue.h"
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

  std::default_random_engine engine(2137);

  size_t primeLength = 16;
  PrimeGenerator generatorTasks[] = {{primeLength, 1}, {primeLength, 2}, {primeLength, 3}, {primeLength, 4},
                                     {primeLength, 5}, {primeLength, 6}, {primeLength, 7}, {primeLength, 8}};

  TaskQueue queue;

  std::vector<Executor> executors;
  size_t threadCount = std::thread::hardware_concurrency();
  threadCount  = 1;
  std::cout << "thread count: " << threadCount << std::endl;

  for (size_t i = 0; i < threadCount; ++i) {
    executors.emplace_back(queue);
  }

  for (int i = 0; i < 8; ++i) {
    queue.push(generatorTasks + i);
  }

  queue.terminate();

  return -1;
}

GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {
      {"length", "n"}, {"help", "h"}, {"output", "o"}, {"entropy-source", "e"}};
}
