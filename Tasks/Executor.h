#ifndef EXECUTOR
#define EXECUTOR

#include "ExecutionContext.h"
#include "TaskQueue.h"
#include <thread>

class Orchestrator;

class Logger;

class Executor {
  friend Orchestrator;

  std::thread _thread;

  static void run(TaskQueue &_queue, ExecutionContext context);

public:
  Executor(ExecutionContext context);
  Executor(Executor &&ex);
  Executor(const Executor &) = delete;
  Executor &operator=(Executor &&e) = delete;
  Executor &operator=(const Executor &) = delete;

  ~Executor();
};

#endif /*EXECUTOR*/
