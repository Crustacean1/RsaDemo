#include "PrimeGenerator.h"
#include "PrimeSync.h"

#include "../Utility/Logger.h"
#include <Arithm/IoEngine.h>
#include <Arithm/PrimalityEngine.h>
#include <ArithmInjector.h>
#include <iostream>

PrimeGenerator::PrimeGenerator(size_t primeLength, size_t seed, PrimeSync &sync)
    : _engine(seed), _done(false), _logger(Logger::getInstance()),
      _primeLength(primeLength), _sync(sync), candidate(primeLength) {}

bool PrimeGenerator::isDone() { return _done; }

void PrimeGenerator::initializeCandidate() {
  auto &io = KCrypt::ArithmInjector::getInstance().getIo();

  io.randomize(candidate.getBuffer(), _engine,
               KCrypt::IoEngine::Sign::Unsigned);
  candidate.getBuffer().data[0] |= 1;
}

std::vector<KCrypt::Buffer> PrimeGenerator::getWitnesses() {
  auto &io = KCrypt::ArithmInjector::getInstance().getIo();
  std::vector<KCrypt::Buffer> witnesses;

  for (size_t i = 0; i < _primeLength; ++i) {
    witnesses.emplace_back(_primeLength);
    io.randomize(witnesses.back(), _engine, KCrypt::IoEngine::Sign::Unsigned);
  }
  return witnesses;
}

void PrimeGenerator::run(std::thread::id id) {

  auto &add = KCrypt::ArithmInjector::getInstance().getAdd();
  KCrypt::PrimalityEngine prim(KCrypt::ArithmInjector::getInstance());

  initializeCandidate();
  auto witnesses = getWitnesses();

  KCrypt::BufferView candidateBuffer = candidate.getBuffer();

  size_t cnt = 0;
  for (size_t i; !_sync.isSearchOver();) {

    if (prim.fastModuloTest(candidate.getBuffer())) {

      prim.setSuspect(candidate.getBuffer());

      for (i = 0; i < witnesses.size() && prim.millerRabinTest(witnesses[i]);
           ++i) {
      }
      if (i == witnesses.size()) {
        _done = true;
        _logger.debug(id, "found prime", candidate);
        _sync.addPrime();
        _sync.endSearch();
        return;
      }
    }
    add.add(candidate.getBuffer(), 2);
  }
  _logger.debug(id, "finished searching");
  _sync.endSearch();
}
