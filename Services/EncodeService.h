#ifndef ENCODE_SERVICE
#define ENCODE_SERVICE

#include "IService.h"

class RsaKey;
class Logger;

class EncodeService : public IService {
  std::string _sourceFilename;
  std::string _keyFilename;
  std::string _outputFilename;
  void initialize(std::unordered_map<std::string, std::string> &args);
  std::tuple<unsigned char *, size_t> load(std::istream &stream);
  std::tuple<unsigned char *, size_t> encode(unsigned char *data,
                                             size_t dataSize, RsaKey &key);
  void save(unsigned char *data, size_t size, std::ostream &stream);
  Logger &_logger;

public:
  EncodeService();
  std::string help() override;
  int run(std::unordered_map<std::string, std::string> &args) override;
  ServiceArgumentDescription getArgumentDescription() override;
};

#endif /*ENCODE_SERVICE*/
