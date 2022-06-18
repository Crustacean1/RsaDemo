#include "Executor.h"
#include "../Utility/Logger.h"
#include <iostream>

Executor::Executor()
    : _thread(&Executor::run, this), _queue(TaskQueue::getInstance()),
      _logger(Logger::getInstance()) {

  _logger.debug("Constructing thread", _thread.get_id());
}

Executor::Executor(Executor &&exec)
    : _thread(std::move(exec._thread)), _queue(exec._queue),
      _logger(exec._logger) {}

void Executor::run() {
  auto threadId = std::this_thread::get_id();

  for (;;) {
    auto *task = _queue.pop();
    if (task == nullptr) {
      return;
    }
    task->run(threadId);
  }
}

Executor::~Executor() {
  _logger.debug("Destroying thread", _thread.get_id());

  if (_thread.joinable()) {
    auto threadId = _thread.get_id();
    _thread.join();
  }
}
