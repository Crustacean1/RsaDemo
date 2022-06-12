#ifndef EXECUTOR
#define EXECUTOR

#include "TaskQueue.h"

class Executor{
  public:
  Executor();
  void start();
  void stop();
};

#endif /*EXECUTOR*/
