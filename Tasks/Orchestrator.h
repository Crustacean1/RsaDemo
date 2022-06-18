#ifndef ORCHESTRATOR
#define ORCHESTRATOR

#include "../Utility/Singleton.h"
#include "Executor.h"
#include "TaskQueue.h"

class Orchestrator : public Singleton<Orchestrator> {
  friend Singleton<Orchestrator>;

  volatile const size_t _executorCount;
  Executor *_executors;
  TaskQueue &_taskQueue;

  Orchestrator();

  void initialize();
  void terminate();
public:
  size_t getWorkerCount();
  ~Orchestrator();
};

#endif /*ORCHESTRATOR*/
