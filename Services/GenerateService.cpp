#include "GenerateService.h"
#include "../Utility/TaskQueue.h"
#include <iostream>
#include <random>
#include "../Utility/Executor.h"
#include "../Utility/TaskQueue.h"
#include "../Tasks/PrimeGenerator.h"

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

  PrimeGenerator * _pr = new PrimeGenerator(2137);
  TaskQueue queue;

  Executor ex1(queue);
  ex1.start();

  queue.push(_pr);
  std::cin.get();

  return -1;
}

GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {
      {"length", "n"}, {"help", "h"}, {"output", "o"}, {"entropy-source", "e"}};
}
