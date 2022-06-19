#ifndef DECODE_SERVICE
#define DECODE_SERVICE

#include "CodeService.h"

class DecodeService : public CodeService {
  size_t _originalSize;

protected:
  std::tuple<unsigned char *, size_t>
  processInput(unsigned char *source, size_t sourceSize, RsaKey &key) override;

  std::tuple<unsigned char *, size_t>
  processOutput(unsigned char *output, size_t outputSize, RsaKey &key) override;

public:
  DecodeService();

  std::string help() override;
};

#endif /*DECODE_SERVICE*/
