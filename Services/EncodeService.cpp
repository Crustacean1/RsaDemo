#include "EncodeService.h"
#include "Tasks/EncodeSync.h"
#include "Tasks/EncodeTask.h"
#include "Tasks/TaskQueue.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"

#include <fstream>
#include <latch>
#include <random>

EncodeService::EncodeService() : CodeService() {}

std::string EncodeService::help() {
  return "Encode file contents with provided key and save them to output\n"
         "Usage: RsaDemo encode [ --source | -s ] <source_file> [ --key | -k] "
         "<key_file> [ --output | -o] <ouput_file> [ --help | -h ]\n";
}

std::tuple<unsigned char *, size_t>
EncodeService::processInput(unsigned char *data, size_t dataSize, RsaKey &key) {
  size_t keySize = key.size() * sizeof(KCrypt::Buffer::BaseInt);
  size_t inputBlockSize = keySize - 2;
  size_t outputBlockSize = keySize;

  size_t blockCount = (dataSize + inputBlockSize - 1) / inputBlockSize;
  size_t outputSize = blockCount * outputBlockSize;

  _logger.info("EncodeService:", "key.size", key.size());
  _logger.info("EncodeService:", "keySize", keySize);
  _logger.info("EncodeService:", "inputBlockSize", inputBlockSize);
  _logger.info("EncodeService:", "outputBlockSize", outputBlockSize);
  _logger.info("EncodeService:", "blockCount", blockCount);
  _logger.info("EncodeService:", "outputSize", outputSize);

  size_t outputHeaderSize = sizeof(size_t);
  unsigned char *output = new unsigned char[outputSize + outputHeaderSize];

  memcpy(output, &dataSize, outputHeaderSize);
  output += outputHeaderSize;

  std::default_random_engine engine(2137);
  std::uniform_int_distribution dist(0, 256);

  for (size_t i = 0, inputPos = 0, outputPos = 0; i < blockCount;
       ++i, inputPos += inputBlockSize, outputPos += outputBlockSize) {

    memcpy(output + outputPos, data + inputPos,
           std::min(inputBlockSize, dataSize - inputPos));

    output[outputPos + outputBlockSize - 1] = 0;
    output[outputPos + outputBlockSize - 2] = dist(engine);
  }
  return std::make_tuple(output, outputSize);
}

std::tuple<unsigned char *, size_t>
EncodeService::processOutput(unsigned char *data, size_t dataSize,
                             RsaKey &key) {
  size_t outputHeaderSize = sizeof(size_t);

  return std::make_tuple(data - outputHeaderSize, dataSize + outputHeaderSize);
}
