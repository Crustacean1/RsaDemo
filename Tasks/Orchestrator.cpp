#include "Orchestrator.h"
#include "../Utility/Logger.h"
#include <ArithmInjector.h>

#include <iostream>

Orchestrator::Orchestrator()
    : _taskQueue(TaskQueue::createInstance()),
      _executorCount((std::thread::hardware_concurrency())),
      _logger(Logger::getInstance()) {
  initialize();
}

void Orchestrator::initialize() {
  for (size_t i = 0; i < _executorCount; ++i) {
    ExecutionContext context{i};
    _executors.emplace_back(context);
  }
}

void Orchestrator::terminate() {
  _logger.debug("Tearing down task queue");
  _taskQueue.terminate();
  _executors.clear();
  KCrypt::ArithmInjector::releaseInstances();
}

size_t Orchestrator::getWorkerCount() { return _executorCount; }

Orchestrator::~Orchestrator() { terminate(); }
