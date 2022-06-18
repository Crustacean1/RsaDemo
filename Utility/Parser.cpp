#include "Parser.h"
#include <algorithm>
#include <cstring>
#include <iostream>

IService *Parser::instantiateService(const std::string &serviceName) {
  auto it = _serviceFactories.find(serviceName);
  if (it == _serviceFactories.end()) {
    throw std::runtime_error(serviceName +
                             std::string(": No such service defined"));
  }
  return it->second();
}

void Parser::parse(int argc, char **argv) {
  if (argc == 1) {
    throw std::runtime_error("You must specify command!");
  }
  _serviceArgs.clear();
  _currentService = instantiateService(argv[1]);

  for (int i = 2; i < argc;) {
    parseLiteral(i, argc, argv);
  }
}

int Parser::run() {
  int result = _currentService->run(_serviceArgs);
  delete _currentService;
  return result;
}

void Parser::parseLiteral(int &pos, int size, char **args) {

  auto argument = getArgument(std::string(args[pos++]));

  if (isOption(argument) && pos < size) {
    _serviceArgs[std::get<0>(argument)] = std::string(args[pos++]);
  } else if (isFlag(argument)) {
    _serviceArgs[std::get<0>(argument)] = std::string("");
  }
}

IService::ArgumentDescription Parser::getArgument(const std::string &cliParam) {
  const auto &vec = _currentService->getArgumentDescription();
  auto isLongOrShort = [&cliParam](
                           const IService::ArgumentDescription &optionPair) {
    bool isLong =
        (cliParam.size() > 2 && std::get<0>(optionPair) == cliParam.substr(2));
    bool isShort =
        (cliParam.size() > 1 && std::get<1>(optionPair) == cliParam.substr(1));
    return isLong | isShort;
  };

  auto it = std::find_if(vec.begin(), vec.end(), isLongOrShort);
  if (it == vec.end()) {
    throw std::runtime_error(
        std::string("In Parser::getArgument: unrecognized option: ") +
        cliParam);
  }
  return *it;
}

bool Parser::isOption(const IService::ArgumentDescription &arg) {
  return !std::get<2>(arg);
}

bool Parser::isFlag(const IService::ArgumentDescription &arg) {
  return std::get<2>(arg);
}
