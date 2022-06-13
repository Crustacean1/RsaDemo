#ifndef PARSER
#define PARSER

#include "./IService.h"
#include <functional>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Parser {
  using GenericServiceFactory = std::function<IService *()>;

  std::unordered_map<std::string, GenericServiceFactory> _serviceFactories;

  std::unordered_map<std::string, std::string> _serviceArgs;
  std::string _currentOption;

  IService *instantiateService(const std::string &serviceName);

  IService *_currentService;

  bool isOption(const std::string &str);
  std::string getOptionFullName(const std::string &str);

  void parseLiteral(int &pos, int size, char **args);

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
