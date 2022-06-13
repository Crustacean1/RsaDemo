#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR

#include "../Utility/Task.h"
#include <stddef.h>
#include <mutex>
#include <vector>
#include <Numeric.h>

class PrimeGenerator : public Task{
  public:
  PrimeGenerator(size_t primeLength, std::mutex & vecMutex, std::vector<KCrypt::Numeric> primes, );
  void run() override;
};

#endif /*PRIME_GENERATOR*/
