#ifndef ISERVICE
#define ISERVICE

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

class IService {
protected:
  std::string fromArgs(const std::string &key, const std::string &defaultValue,
                       std::unordered_map<std::string, std::string> &args);

public:
  using ArgumentDescription = std::tuple<std::string, std::string>;
  using ServiceArgumentDescription = std::vector<ArgumentDescription>;

  virtual ServiceArgumentDescription getArgumentDescription() = 0;
  virtual std::string help() = 0;
  virtual int run(std::unordered_map<std::string, std::string> &args);
};

#endif /*ISERVICE*/
