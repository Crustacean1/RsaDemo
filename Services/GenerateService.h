#ifndef GENERATE_SERVICE
#define GENERATE_SERVICE

#include "IService.h"

class PrimeGenerator;
class PrimeSync;
class Logger;

namespace KCrypt {
class Numeric;
}

class GenerateService : public IService {

  Logger &_logger;

  std::string _outputFile;
  size_t _keySize;
  size_t _coreCount;
  bool _verbose;

  std::tuple<KCrypt::Numeric, KCrypt::Numeric> generatePrimes();

  void readData(std::unordered_map<std::string, std::string> &args);

  std::tuple<KCrypt::Numeric, KCrypt::Numeric, KCrypt::Numeric>
  createKey(KCrypt::Numeric &prime1, KCrypt::Numeric &prime2);

  void writeKey();

  std::vector<PrimeGenerator *> splitTasks(size_t taskCount, size_t primeLength,
                                           PrimeSync &sync);

  void dispose(const std::vector<PrimeGenerator *> tasks);

public:
  GenerateService();
  std::string help() override;
  int run(std::unordered_map<std::string, std::string> &args) override;
  ServiceArgumentDescription getArgumentDescription() override;
  ~GenerateService();
};

#endif /*GENERATE_SERVICE*/
