#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR

#include "../Tasks/Task.h"

#include <Numeric.h>
#include <vector>

class PrimeSync;
class Logger;
class ExecutionContext;

class PrimeGenerator : public Task {
  Logger &_logger;

  bool _done;
  size_t _primeLength;
  std::default_random_engine _engine;

  PrimeSync &_sync;

  void initializeCandidate();
  std::vector<KCrypt::Buffer> getWitnesses();

public:
  PrimeGenerator(size_t primeLength, size_t seed, PrimeSync &sync);
  PrimeGenerator(const PrimeGenerator &) = delete;
  PrimeGenerator operator=(const PrimeGenerator &) = delete;

  void run(ExecutionContext &context) override;
  bool isDone() const;

  KCrypt::Numeric candidate;

  ~PrimeGenerator();
};

#endif /*PRIME_GENERATOR*/
