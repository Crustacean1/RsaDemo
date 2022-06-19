#ifndef EXECUTION_CONTEXT
#define EXECUTION_CONTEXT

#include <cstddef>

class ExecutionContext {
public:
  size_t threadNo;
  bool isRsaKeySet = false; 
};

#endif /*EXECUTION_CONTEXT*/
