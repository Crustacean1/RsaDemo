#include "TaskQueue.h"

TaskQueue::TaskQueue() {}

void TaskQueue::push(Task *task) {
  {
    std::unique_lock<std::mutex> lock(_queueMutex);
    _taskQueue.push(task);
  }
  _cVar.notify_one();
}
Task *TaskQueue::pop() {
  std::unique_lock<std::mutex> lock(_queueMutex);
  if (_taskQueue.size() == 0) {
    _cVar.wait(lock, [this]() { return _taskQueue.size() != 0; });
  }

  auto front = _taskQueue.front();
  _taskQueue.pop();
  return front;
}
