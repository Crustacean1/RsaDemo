#ifndef PARSER
#define PARSER

#include "../Services/IService.h"
#include <functional>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Parser {
  using GenericServiceFactory = std::function<IService *()>;

  std::unordered_map<std::string, GenericServiceFactory> _serviceFactories;

  std::unordered_map<std::string, std::string> _serviceArgs;

  IService *instantiateService(const std::string &serviceName);

  IService *_currentService;

  bool isOption(const IService::ArgumentDescription &desc);
  bool isFlag(const IService::ArgumentDescription &desc);

  void parseLiteral(int &pos, int size, char **args);

  IService::ArgumentDescription getArgument(const std::string &cliParam);

public:
  template <typename ServiceType> void addService(const std::string &name);

  void parse(int argc, char **argv);
  int run();
};

template <typename ServiceType>
void Parser::addService(const std::string &name) {
  if (_serviceFactories.find(name) != _serviceFactories.end()) {
    throw new std::runtime_error("Service name already exists");
  }

  _serviceFactories.insert(
      {name, 
        (std::function<IService*()>)[]() -> IService * 
        { return new ServiceType();
}
});
}

#endif /*PARSER*/
