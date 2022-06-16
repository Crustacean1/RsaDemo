#include "Executor.h"
#include <iostream>

Executor::Executor(TaskQueue &queue)
    : _active(true), _thread(Executor::run, std::ref(queue)) {
  std::cout << "Constructing thread: " << _thread.get_id() << std::endl;
}

Executor::Executor(Executor &&exec)
    : _active(true), _thread(std::move(exec._thread)) {
  exec._active = false;
}

void Executor::run(TaskQueue &queue) {
  auto threadId = std::this_thread::get_id();

  for (;;) {
    auto *task = queue.pop();
    if (task == nullptr) {
      return;
    }
    task->run(threadId);
  }
}

Executor::~Executor() {
  if (_active) {
    auto threadId = _thread.get_id();
    std::cout << "Ending thread: " << threadId << std::endl;
    _thread.join();
    std::cout << "Ended thread: " << threadId << std::endl;
  }
}
