#ifndef ENCODE_SYNC
#define ENCODE_SYNC

#include <cstddef>
#include <latch>
#include <mutex>

class EncodeSync {
  std::latch _allTasksDone;
  std::mutex _keyMutex;

public:
  EncodeSync(size_t taskCount);
  void finishTask();
  std::unique_lock<std::mutex> lockKey();
  void waitForAllTasks();
};

#endif /*ENCODE_SYNC*/
