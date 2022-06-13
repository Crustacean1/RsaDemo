#ifndef ISERVICE
#define ISERVICE

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

class IService {
public:
  using ArgumentDescription = std::tuple<std::string, std::string>;
  using ServiceArgumentDescription = std::vector<ArgumentDescription>;

  virtual ServiceArgumentDescription getArgumentDescription() = 0;
  virtual std::string help() = 0;
  virtual int run(std::unordered_map<std::string, std::string> &args) = 0;
};

#endif /*ISERVICE*/
