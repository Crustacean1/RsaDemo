#include "EncodeSync.h"

EncodeSync::EncodeSync(size_t taskCount)
    : _allTasksDone{static_cast<ptrdiff_t>(taskCount)} {}

void EncodeSync::finishTask() { _allTasksDone.count_down(); }

void EncodeSync::waitForAllTasks() { _allTasksDone.wait(); }
