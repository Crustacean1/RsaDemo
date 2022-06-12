#ifndef GENERATE_SERVICE
#define GENERATE_SERVICE

#include "../Utility/IService.h"

class GenerateService : IService {
public:
  GenerateService(std::string name);
  std::string help() override;
  void run(std::unordered_map<std::string, std::string> &args) override;
};

#endif /*GENERATE_SERVICE*/