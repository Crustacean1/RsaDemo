#ifndef CODE_SERVICE
#define CODE_SERVICE

#include "IService.h"

class Logger;
class RsaKey;

class CodeService : public IService {
  std::string _sourceFilename;
  std::string _keyFilename;
  std::string _outputFilename;

  void initialize(std::unordered_map<std::string, std::string> &args);

  std::tuple<unsigned char *, size_t> load(std::istream &stream);

  void save(unsigned char *data, size_t size, std::ostream &stream);

protected:
  Logger &_logger;

  virtual std::tuple<unsigned char *, size_t>
  processInput(unsigned char *source, size_t sourceSize, RsaKey &key) = 0;

  virtual std::tuple<unsigned char *, size_t>
  processOutput(unsigned char *output, size_t outputSize, RsaKey &key) = 0;

  void encode(unsigned char *data, size_t dataSize, RsaKey &key);

public:
  CodeService();
  int run(std::unordered_map<std::string, std::string> &args) override;
  ServiceArgumentDescription getArgumentDescription() override;
};

#endif /*CODE_SERVICE*/
