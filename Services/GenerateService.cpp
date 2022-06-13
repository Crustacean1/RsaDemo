#include "GenerateService.h"
#include <Numeric.h>
#include <iostream>

GenerateService::GenerateService() {}

std::string GenerateService::help() {
  return "Generate RSA key pair and save it to file\n"
         "Usage: RsaDemo generate [-n | --size (size of key)] [-o | --output "
         "(path to key file)] [-v | --verbose]\n"
         "For debugging purposes run with -v or --verbose flag";
}

std::string
GenerateService::fromArgs(const std::string &key,
                          const std::string &defaultValue,
                          std::unordered_map<std::string, std::string> &args) {
  auto it = args.find(key);
  return (it == args.end()) ? defaultValue : it->second;
}

int GenerateService::run(std::unordered_map<std::string, std::string> &args) {
  std::cout << "Starting key generation of length: "
            << fromArgs("length", "-1", args) << std::endl;
  KCrypt::Numeric a("2137");

  std::cout << "Solution: " << a << std::endl;
  std::cout << "Input some number: " << std::endl;

  KCrypt::Numeric b;
  std::cin >> b;
  a *= b;
  std::cout << "Mul: " << a << std::endl;

  return -1;
}
GenerateService::ServiceArgumentDescription
GenerateService::getArgumentDescription() {
  return {{"length", "n"}, {"output", "o"}, {"entropy-source", "e"}};
}
