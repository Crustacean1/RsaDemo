#ifndef TASK_QUEUE
#define TASK_QUEUE

#include "Task.h"
#include <mutex>
#include <queue>

class TaskQueue {
  std::queue<Task *> _taskQueue;
  std::mutex _queueMutex;

public:
  TaskQueue();
  TaskQueue(const TaskQueue &) = delete;
  TaskQueue &operator=(const TaskQueue &) = delete;

  void push(Task *task);
  Task *pop();
};

#endif /*TASK_QUEUE*/
