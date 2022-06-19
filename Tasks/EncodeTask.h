#ifndef ENCRYPTION_TASK
#define ENCRYPTION_TASK

#include "Task.h"
#include <Numeric.h>

class RsaKey;
class Logger;
class EncodeSync;
class ExecutionContext;

namespace KCrypt {
class ArithmInjector;
}

class EncodeTask : public Task {
  RsaKey &_key;
  Logger &_logger;

  EncodeSync &_sync;

  unsigned char *_data;
  size_t _outputSize;

public:
  EncodeTask(RsaKey &key, EncodeSync &sync, unsigned char *data);
  void run(ExecutionContext &context) override;
};

#endif /*ENCRYPTION_TASK*/
