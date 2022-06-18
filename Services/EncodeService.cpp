#include "EncodeService.h"
#include "../Utility/RsaKey.h"
#include "Utility/Logger.h"
#include <fstream>
#include <stdexcept>

EncodeService::EncodeService() : _logger(Logger::getInstance()) {}

std::string EncodeService::help() {
  return "Encode file contents with provided key and save them to output\n"
         "Usage: RsaDemo encode [ --source | -s ] <source_file> [ --key | -k] "
         "<key_file> [ --output | -o] <ouput_file> [ --help | -h ]\n";
}

int EncodeService::run(std::unordered_map<std::string, std::string> &args) {
  if (auto result = IService::run(args)) {
    return result;
  }
  initialize(args);

  std::ifstream sourceFile(_sourceFilename.c_str(), std::ios::binary);
  std::ifstream keyFile(_keyFilename.c_str());
  std::ofstream outputFile(_outputFilename.c_str(), std::ios::binary);

  RsaKey key;

  key.load(keyFile);

  auto [source, sourceSize] = load(sourceFile);
  _logger.debug("read ", sourceSize, "bytes");
  auto [enc, encSize] = encode(source, sourceSize, key);
  save(enc, encSize, outputFile);

  return 0;
}

std::tuple<unsigned char *, size_t> EncodeService::load(std::istream &stream) {
  size_t length;
  stream.seekg(0,stream.end);
  length = stream.tellg();
  stream.seekg(0,stream.beg);

  _logger.debug("length",length);

  unsigned char *data = new unsigned char[length];

  stream.read(reinterpret_cast<char *>(data), length);
  return std::make_pair(data, length);
}

std::tuple<unsigned char *, size_t>
EncodeService::encode(unsigned char *data, size_t dataSize, RsaKey &key) {
  return std::make_pair(data, dataSize);
}

void EncodeService::save(unsigned char *data, size_t size,
                         std::ostream &stream) {
  stream.write(reinterpret_cast<char *>(data), size);
}

void EncodeService::initialize(
    std::unordered_map<std::string, std::string> &args) {
  _sourceFilename = fromArgs("source", "", args);
  _keyFilename = fromArgs("key", "", args);
  _outputFilename = fromArgs("output", "", args);
  if (_sourceFilename == "" || _keyFilename == "" || _outputFilename == "") {
    throw std::runtime_error("In EncodeService::intialize:"
                             "All 3 parameters must be specified");
  }
}

EncodeService::ServiceArgumentDescription
EncodeService::getArgumentDescription() {
  return {{"source", "s", false},
          {"key", "k", false},
          {"output", "o", false},
          {"help", "h", true}};
}
