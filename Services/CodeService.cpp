#include "CodeService.h"
#include "Tasks/EncodeSync.h"
#include "Tasks/EncodeTask.h"
#include "Tasks/TaskQueue.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"
#include <Numeric.h>
#include <fstream>

CodeService::CodeService() : _logger(Logger::getInstance()) {}

int CodeService::run(std::unordered_map<std::string, std::string> &args) {
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

  auto [data, dataSize] = processInput(source, sourceSize, key);

  encode(data, dataSize, key);

  auto [outputData, outputSize] = processOutput(data, dataSize, key);

  save(outputData, outputSize, outputFile);

  return 0;
}

std::tuple<unsigned char *, size_t> CodeService::load(std::istream &stream) {
  size_t size;
  stream.seekg(0, stream.end);
  size = stream.tellg();
  stream.seekg(0, stream.beg);

  _logger.debug("CodeService::load", "file size", size);

  unsigned char *data = new unsigned char[size];

  stream.read(reinterpret_cast<char *>(data), size);
  return std::make_pair(data, size);
}

void CodeService::encode(unsigned char *data, size_t dataSize, RsaKey &key) {
  auto &queue = TaskQueue::getInstance();

  std::vector<EncodeTask *> tasks;

  size_t blockSize = key.size() * sizeof(KCrypt::Buffer::BaseInt);
  size_t blockCount = dataSize / blockSize;

  EncodeSync sync(blockCount);

  // TODO: Replace with emplace
  for (size_t i = 0, dataPos = 0; i < blockCount; ++i, dataPos += blockSize) {
    tasks.push_back(new EncodeTask(key, sync, data + dataPos));
    queue.push(tasks.back());
  }

  sync.waitForAllTasks();
  _logger.debug("Encoding finished");

  for (auto &task : tasks) {
    delete task;
  }
}

void CodeService::save(unsigned char *data, size_t size, std::ostream &stream) {
  stream.write(reinterpret_cast<char *>(data), size);
}

void CodeService::initialize(
    std::unordered_map<std::string, std::string> &args) {
  _sourceFilename = fromArgs("source", "", args);
  _keyFilename = fromArgs("key", "", args);
  _outputFilename = fromArgs("output", "", args);
  if (_sourceFilename == "" || _keyFilename == "" || _outputFilename == "") {
    throw std::runtime_error("In EncodeService::intialize:"
                             "All 3 parameters must be specified");
  }
}

CodeService::ServiceArgumentDescription CodeService::getArgumentDescription() {
  return {{"source", "s", false},
          {"key", "k", false},
          {"output", "o", false},
          {"help", "h", true}};
}
