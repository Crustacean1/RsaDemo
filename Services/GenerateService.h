#ifndef GENERATE_SERVICE
#define GENERATE_SERVICE

#include "../Utility/IService.h"

class GenerateService : public IService {
  std::string _outputFile;
  size_t _keySize;
  bool _verbose;
  std::string
  fromArgs(const std::string &key,
                    const std::string &defaultValue,
                    std::unordered_map<std::string, std::string> &args);

public:

  GenerateService();
  std::string help() override;
  int run(std::unordered_map<std::string, std::string> &args) override;
  ServiceArgumentDescription getArgumentDescription() override;
};

#endif /*GENERATE_SERVICE*/
