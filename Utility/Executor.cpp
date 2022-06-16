#include "Executor.h"
#include <iostream>

Executor::Executor(TaskQueue &queue) : _queue(queue) {}

void Executor::start() {
  std::cout << "Starting new thread" << std::endl;
  _thread = new std::thread(&Executor::run, *this);
}

void Executor::run() {
  std::cout<<"In thread: "<<std::this_thread::get_id()<<" starting execution"<<std::endl;
  for (;;) {
    auto *task = _queue.pop();
    task->run();
  }
}
// TODO
void Executor::stop() { _thread->join(); }

Executor::~Executor() { stop(); }
