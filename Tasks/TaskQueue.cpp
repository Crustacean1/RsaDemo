#include "TaskQueue.h"
#include <iostream>

TaskQueue::TaskQueue() : _active(true) {
}

void TaskQueue::push(Task *task) {
  std::unique_lock<std::mutex> lock(_queueMutex);
  _taskQueue.push(task);
  lock.unlock();
  _cVar.notify_one();
}

Task *TaskQueue::pop() {
  std::unique_lock<std::mutex> lock(_queueMutex);

  if (_taskQueue.size() == 0) {
    if (!_active) {
      return nullptr;
    }

    _cVar.wait(lock, [this]() { return (_taskQueue.size() != 0 || !_active); });

    if (!_active) {
      return nullptr;
    }
  }

  auto front = _taskQueue.front();
  _taskQueue.pop();
  return front;
}

void TaskQueue::terminate() {
  std::unique_lock<std::mutex> lock(_queueMutex);
  _active = false;
  _cVar.notify_all();
}
