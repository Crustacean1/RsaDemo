#include "EncodeSync.h"
#include "Utility/Logger.h"
#include <iostream>

EncodeSync::EncodeSync(size_t taskCount)
    : _allTaskCount(taskCount), _logger(Logger::getInstance()),
      _taskCount(0), _allTasksDone{static_cast<ptrdiff_t>(taskCount)} {}

void EncodeSync::finishTask() {
  _logger.progress("Encoding progress", _taskCount, "/", _allTaskCount);
  ++_taskCount;
  _allTasksDone.count_down();
}

void EncodeSync::waitForAllTasks() { _allTasksDone.wait(); }
