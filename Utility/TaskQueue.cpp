#include "TaskQueue.h"

TaskQueue::TaskQueue() {}

void TaskQueue::push(Task *task) {
  std::lock_guard<std::mutex> lock(_queueMutex);
  _taskQueue.push(task);
}
Task *TaskQueue::pop() {
  std::lock_guard<std::mutex> lock(_queueMutex);
  auto front = _taskQueue.front();
  _taskQueue.pop();
  return front;
}
