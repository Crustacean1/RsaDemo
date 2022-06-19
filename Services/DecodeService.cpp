#include "DecodeService.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"
#include <cstring>

DecodeService::DecodeService() : CodeService() {}

std::string DecodeService::help() {
  return "Decode file contents with provided key and save them to output\n"
         "Usage: RsaDemo decode [ --source | -s ] <source_file> [ --key | -k] "
         "<key_file> [ --output | -o] <ouput_file> [ --help | -h ]\n";
}

std::tuple<unsigned char *, size_t>
DecodeService::processInput(unsigned char *source, size_t sourceSize,
                            RsaKey &key) {
  size_t headerSize = sizeof(size_t);

  memcpy(&_originalSize, source, headerSize);

  _logger.debug("Detected original size: ", _originalSize);

  return std::make_tuple(source + headerSize, sourceSize - headerSize);
}

std::tuple<unsigned char *, size_t>
DecodeService::processOutput(unsigned char *input, size_t inputSize,
                             RsaKey &key) {
  size_t inputBlockSize = key.size() * sizeof(KCrypt::Buffer::BaseInt);
  size_t blockCount = inputSize / inputBlockSize;
  size_t outputBlockSize = inputBlockSize - 2;

  unsigned char *output = new unsigned char[blockCount * outputBlockSize];

  for (size_t i = 0, inputPos = 0, outputPos = 0; i < blockCount;
       ++i, inputPos += inputBlockSize, outputPos += outputBlockSize) {
    memcpy(output + outputPos, input + inputPos, outputBlockSize);
  }
  return std::make_tuple(output, _originalSize);
}
