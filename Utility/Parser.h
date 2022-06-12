#ifndef PARSER
#define PARSER

#include "./IService.h"
#include <functional>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Parser {
  using ServiceArgument = std::unordered_map<std::string, std::string>;
  using GenericServiceFactory = std::function<IService(ServiceArgument &)>;

  std::unordered_map<std::string, GenericServiceFactory> _serviceFactories;

public:
  Parser();

  template <typename ServiceType> void addService(const std::string &name);

  int parse(int argc, char **argv);
};

template <typename ServiceType>
void Parser::addService(const std::string &name) {
  if (_serviceFactories.find(name) != _serviceFactories.end()) {
    throw new std::runtime_error("Service name already exists");
  }

  _serviceFactories.insert(
      name, [](std::unordered_map<std::string, std::string> &args) -> IService {
        return new ServiceType(args);
      });
}

#endif /*PARSER*/
