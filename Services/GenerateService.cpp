#include "GenerateService.h"
#include "../Utility/TaskQueue.h"
#include <iostream>
#include <random>

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

  return -1;
}

GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {
      {"length", "n"}, {"help", "h"}, {"output", "o"}, {"entropy-source", "e"}};
}
