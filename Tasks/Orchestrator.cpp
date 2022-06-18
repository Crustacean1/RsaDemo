#include "Orchestrator.h"
#include <ArithmInjector.h>
#include <iostream>

Orchestrator::Orchestrator()
    : _taskQueue(TaskQueue::createInstance()), _executorCount(std::thread::hardware_concurrency()) {
  initialize();
}

void Orchestrator::initialize() {
  _executors = new Executor[_executorCount];
}

void Orchestrator::terminate() {
  std::cout << "Terminating" << std::endl;
  _taskQueue.terminate();
  delete[] _executors;
  KCrypt::ArithmInjector::releaseInstances();
}

size_t Orchestrator::getWorkerCount() { return _executorCount; }

Orchestrator::~Orchestrator(){
  terminate();
}
