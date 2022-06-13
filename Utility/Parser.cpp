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

int Parser::run() { return _currentService->run(_serviceArgs); }

void Parser::parseLiteral(int &pos, int size, char **args) {
  if (!isOption(args[pos])) {
    if (_currentOption == "") {
      throw std::runtime_error(std::string("Unrecognized option: ") +
                               std::string(args[pos]));
    }
    _serviceArgs[_currentOption] = std::string(args[pos]);
    if (++pos < size && !isOption(args[pos])) {
      throw std::runtime_error(
          std::string("Multiple values for one option not allowed: ") +
          _currentOption);
    }
  }
  if (pos < size) {
    _currentOption = getOptionFullName(std::string(args[pos++]));
  }
}

bool Parser::isOption(const std::string &str) {
  if (str.size() == 0) {
    return false;
  }
  const auto &vec = _currentService->getArgumentDescription();
  auto it = std::find_if(
      vec.begin(), vec.end(),
      [&str](const std::tuple<std::string, std::string> &optionPair) {
        return (str.size() > 2 && str[0] == '-' && str[1] == '-' &&
                std::get<0>(optionPair) == str.substr(2)) ||
               (str.size() > 1 && str[0] == '-' &&
                std::get<1>(optionPair) == str.substr(1));
      });
  return it != vec.end();
}

std::string Parser::getOptionFullName(const std::string &str) {

  const auto &vec = _currentService->getArgumentDescription();
  auto it = std::find_if(
      vec.begin(), vec.end(),
      [&str](const std::tuple<std::string, std::string> &optionPair) {
        return std::get<0>(optionPair) == str.substr(2) ||
               (str.size() > 1 && std::get<1>(optionPair) == str.substr(1));
      });
  if (it == vec.end()) {
    throw std::runtime_error(std::string("In: Parser::getOptionFullName: ") +
                             "couldn't retrieve option");
  }
  return std::get<0>(*it);
}
