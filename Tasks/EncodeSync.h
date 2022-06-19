#ifndef ENCODE_SYNC
#define ENCODE_SYNC

#include <cstddef>
#include <latch>

class EncodeSync {
  std::latch _allTasksDone;

public:
  EncodeSync(size_t taskCount);
  void finishTask();
  void waitForAllTasks();
};

#endif /*ENCODE_SYNC*/
