#ifndef TASK_QUEUE
#define TASK_QUEUE

#include "Task.h"
#include "../Utility/Singleton.h"
#include <condition_variable>
#include <mutex>
#include <queue>

class TaskQueue : public Singleton<TaskQueue> {
  friend Singleton<TaskQueue>;

  bool _active;

  std::queue<Task *> _taskQueue;
  std::mutex _queueMutex;
  std::condition_variable _cVar;

  TaskQueue();

public:
  TaskQueue(const TaskQueue &) = delete;
  TaskQueue &operator=(const TaskQueue &) = delete;

  void push(Task *task);

  Task *pop();

  void terminate();
};

#endif /*TASK_QUEUE*/
