#ifndef TASK
#define TASK

#include <thread>

class ExecutionContext;

class Task {
public:
  virtual void run(ExecutionContext &context) = 0;
  virtual ~Task(){};
};

#endif /*TASK*/
