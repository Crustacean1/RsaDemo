#ifndef TASK
#define TASK

#include <thread>

class Task {
public:
  virtual void run(std::thread::id id) = 0;
};

#endif /*TASK*/
