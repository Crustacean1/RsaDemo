#include "EncodeSync.h"

EncodeSync::EncodeSync(size_t taskCount)
    : _allTasksDone{static_cast<ptrdiff_t>(taskCount)} {}

void EncodeSync::finishTask() { _allTasksDone.count_down(); }

void EncodeSync::waitForAllTasks() { _allTasksDone.wait(); }

std::unique_lock<std::mutex> EncodeSync::lockKey() {
  return std::unique_lock<std::mutex>(_keyMutex);
}
