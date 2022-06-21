#include "Executor.h"
#include "../Utility/Logger.h"
#include <iostream>

Executor::Executor(ExecutionContext context)
    : _thread(&Executor::run, std::ref(TaskQueue::getInstance()), context) {

  auto &logger = Logger::getInstance();
  logger.debug("Created thread with context:", context.threadNo);
}

Executor::Executor(Executor &&exec) : _thread(std::move(exec._thread)) {}

void Executor::run(TaskQueue &queue, ExecutionContext context) {
  auto &logger = Logger::getInstance();

  for (;;) {
    auto *task = queue.pop();
    if (task == nullptr) {
      return;
    }
    task->run(context);
  }
}

Executor::~Executor() {

  if (_thread.joinable()) {
    auto &logger = Logger::getInstance();
    logger.debug("Destroying thread", _thread.get_id());
    auto threadId = _thread.get_id();
    _thread.join();
  }
}
