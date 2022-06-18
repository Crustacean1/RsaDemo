#ifndef GENERATE_SERVICE
#define GENERATE_SERVICE

#include "IService.h"

class GenerateService : public IService {

  std::string _outputFile;
  size_t _keySize;
  size_t _coreCount;
  bool _verbose;

  void generateKey();
  void writeKey();

public:

  GenerateService();
  std::string help() override;
  int run(std::unordered_map<std::string, std::string> &args) override;
  ServiceArgumentDescription getArgumentDescription() override;
  ~GenerateService();
};

#endif /*GENERATE_SERVICE*/
