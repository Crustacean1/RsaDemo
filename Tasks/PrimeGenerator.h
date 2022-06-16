#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR

#include "../Tasks/Task.h"
#include <stddef.h>
#include <mutex>
#include <vector>
#include <Numeric.h>
#include <random>

class PrimeGenerator : public Task{
  size_t _primeLength;
  std::default_random_engine _engine;

  public:
  PrimeGenerator(size_t primeLength, size_t seed);
  void run(std::thread::id id) override;
  KCrypt::Numeric prime;
};

#endif /*PRIME_GENERATOR*/
