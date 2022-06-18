#ifndef PRIME_SYNC
#define PRIME_SYNC

#include <atomic>
#include <latch>

class PrimeSync {

  std::atomic<size_t> _primeCounter;
  std::latch _primeLatch;

public:
  PrimeSync(size_t threadCount);

  bool isSearchOver();
  void addPrime();
  void waitForSearchOver();
  void endSearch();
};

#endif /*PRIME_SYNC*/
