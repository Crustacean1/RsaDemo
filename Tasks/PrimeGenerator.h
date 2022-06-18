#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR

#include "../Tasks/Task.h"

#include <Numeric.h>
#include <vector>

class PrimeSync;
class Logger;

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
  PrimeGenerator(const PrimeGenerator&) = delete;
  PrimeGenerator operator=(const PrimeGenerator&) = delete;

  void run(std::thread::id id) override;
  bool isDone();

  KCrypt::Numeric candidate;
};

#endif /*PRIME_GENERATOR*/
