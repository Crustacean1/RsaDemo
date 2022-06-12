#ifndef ISERVICE
#define ISERVICE

#include <string>
#include <unordered_map>

class IService{
public:
  IService(const std::string &name);
  virtual std::string help() = 0;
  virtual void run(std::unordered_map<std::string, std::string> & args) = 0;
};

#endif /*ISERVICE*/
