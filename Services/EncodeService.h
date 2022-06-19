#ifndef ENCODE_SERVICE
#define ENCODE_SERVICE

#include "CodeService.h"

class EncodeService : public CodeService {
protected:
  std::tuple<unsigned char *, size_t>
  processInput(unsigned char *source, size_t sourceSize, RsaKey &key) override;

  std::tuple<unsigned char *, size_t>
  processOutput(unsigned char *output, size_t outputSize, RsaKey &key) override;

public:
  EncodeService();
  std::string help() override;
};

#endif /*ENCODE_SERVICE*/
