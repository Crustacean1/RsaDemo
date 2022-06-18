#include "PrimeSync.h"
#include <iostream>
#include "../Utility/Logger.h"

PrimeSync::PrimeSync(size_t threadCount)
    : _primeCounter(0), _primeLatch(threadCount) {
  Logger::getInstance().debug("Counter:", _primeCounter.load());
}

bool PrimeSync::isSearchOver() { return _primeCounter > 1; }

void PrimeSync::addPrime() { ++_primeCounter; }

void PrimeSync::endSearch() {
  _primeLatch.count_down();
}

void PrimeSync::waitForSearchOver() { _primeLatch.wait(); }
