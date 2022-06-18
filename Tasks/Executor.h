#ifndef EXECUTOR
#define EXECUTOR

#include "TaskQueue.h"
#include <thread>

class Logger;

class Executor {
  Logger & _logger;

  TaskQueue & _queue;
  std::thread _thread;
  std::mutex _runMutex;

  void run();

public:
  Executor();

  Executor(Executor &&ex);
  Executor(const Executor &) = delete;
  Executor &operator=(Executor &&e) = delete;
  Executor &operator=(const Executor &) = delete;

  ~Executor();
};

#endif /*EXECUTOR*/
