#ifndef ENCODE_SYNC
#define ENCODE_SYNC

#include <cstddef>
#include <latch>
#include <mutex>
#include <cstddef>

class Logger;

class EncodeSync {
  std::latch _allTasksDone;
  size_t _allTaskCount;
  size_t _taskCount;
  Logger &_logger;

public:
  EncodeSync(size_t taskCount);
  void finishTask();
  void waitForAllTasks();
};

#endif /*ENCODE_SYNC*/
