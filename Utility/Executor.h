#ifndef EXECUTOR
#define EXECUTOR

#include "TaskQueue.h"
#include <thread>

class Executor{
  std::thread * _thread;
  TaskQueue & _queue;
  void run();
  public:
  Executor(TaskQueue & queue);
  void start();
  void stop();
  ~Executor();
};

#endif /*EXECUTOR*/
