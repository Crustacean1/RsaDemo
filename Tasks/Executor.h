#ifndef EXECUTOR
#define EXECUTOR

#include "TaskQueue.h"
#include <thread>

class Executor {
  bool _active;
  std::thread _thread;

  static void run(TaskQueue &queue);

public:
  Executor(TaskQueue &queue);

  Executor(Executor &&ex);
  Executor(const Executor &) = delete;
  Executor &operator=(Executor &&e) = delete;
  Executor &operator=(const Executor &) = delete;

  ~Executor();
};

#endif /*EXECUTOR*/
