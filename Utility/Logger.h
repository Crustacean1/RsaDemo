#ifndef LOGGER
#define LOGGER

#include "Singleton.h"
#include <mutex>
#include <ostream>
#include <thread>

enum class Verbosity : unsigned char { Debug = 3, Info = 2, Error = 1 };

class Logger : public Singleton<Logger, std::ostream &, Verbosity> {

  friend Singleton<Logger, std::ostream &, Verbosity>;
  std::mutex _logMutex;

public:
  template <typename... Args> void debug(Args... args);
  template <typename... Args> void info(Args... args);
  template <typename... Args> void error(Args... args);
  template <typename... Args> void progress(Args... args);

private:
  template <typename... Args, typename T> void log(T first, Args... args);

  Logger(std::ostream &stream, Verbosity verbosity);
  Verbosity _verbosity;
  std::ostream &_stream;
};

template <typename... Args, typename T>
void Logger::log(T first, Args... args) {
  std::unique_lock<std::mutex> lock(_logMutex);
  _stream << first;
  ((_stream << "\t" << args), ...);
  _stream<<std::flush;
}

template <typename... Args> void Logger::debug(Args... args) {
  if (_verbosity >= Verbosity::Debug) {
    log("[DEBUG]", std::move(args)..., "\n");
  }
}

template <typename... Args> void Logger::info(Args... args) {
  if (_verbosity >= Verbosity::Info) {
    log("[INFO]", std::move(args)..., "\n");
  }
}

template <typename... Args> void Logger::error(Args... args) {
  if (_verbosity >= Verbosity::Error) {
    log("[ERROR]", std::move(args)..., "\n");
  }
}

template <typename... Args> void Logger::progress(Args... args) {
  if (_verbosity >= Verbosity::Error) {
    log("[PROGRESS]", std::move(args)...,"\r");
  }
}
#endif /*LOGGER*/
