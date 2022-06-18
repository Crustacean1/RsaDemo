#include "Logger.h"

Logger::Logger(std::ostream &stream, Verbosity verbosity)
    : _stream(stream), _verbosity(verbosity), Singleton() {}
