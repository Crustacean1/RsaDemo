#ifndef ENCRYPTION_TASK
#define ENCRYPTION_TASK

#include "Task.h"
#include <Numeric.h>

class RsaKey;
class Logger;
class EncodeSync;
class ExecutionContext;

class EncodeTask : public Task {
  RsaKey &_key;
  Logger &_logger;

  EncodeSync &_sync;

  unsigned char *_source;
  size_t _sourceSize;

  unsigned char *_output;
  size_t _outputSize;

public:
  EncodeTask(RsaKey &key, EncodeSync &sync, unsigned char *source,
             size_t sourceSize, unsigned char *output);
  void run(ExecutionContext &context) override;
};

#endif /*ENCRYPTION_TASK*/
