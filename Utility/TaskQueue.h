#ifndef TASK_QUEUE
#define TASK_QUEUE

#include "Task.h"

class TaskQueue {
public:
  TaskQueue();
  void push(Task *task);
  Task *pop();
};

#endif /*TASK_QUEUE*/
