#ifndef ORCHESTRATOR
#define ORCHESTRATOR

#include "../Utility/Singleton.h"
#include "Executor.h"
#include "TaskQueue.h"

class Logger;

class Orchestrator : public Singleton<Orchestrator> {
  friend Singleton<Orchestrator>;
  Logger &_logger;

  volatile const size_t _executorCount;
  std::vector<Executor> _executors;
  TaskQueue &_taskQueue;

  Orchestrator();

  void initialize();
  void terminate();

public:
  size_t getWorkerCount();
  ~Orchestrator();
};

#endif /*ORCHESTRATOR*/
