#include "IService.h"
#include <iostream>

int IService::run(std::unordered_map<std::string, std::string> &args) {
  if (args.find("help") != args.end()) {
    std::cerr << help() << std::endl;
    return 1;
  }
  return 0;
}

std::string
IService::fromArgs(const std::string &key, const std::string &defaultValue,
                   std::unordered_map<std::string, std::string> &args) {
  auto it = args.find(key);
  return (it == args.end()) ? defaultValue : it->second;
}
IService::~IService(){}
