#ifndef TASK_QUEUE
#define TASK_QUEUE

#include "Task.h"
#include <mutex>
#include <queue>
#include <condition_variable>

class TaskQueue {
  std::queue<Task *> _taskQueue;
  std::mutex _queueMutex;
  std::condition_variable _cVar;

public:
  TaskQueue();
  TaskQueue(const TaskQueue &) = delete;
  TaskQueue &operator=(const TaskQueue &) = delete;

  void push(Task *task);
  Task *pop();
};

#endif /*TASK_QUEUE*/
