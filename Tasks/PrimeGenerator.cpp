#include "PrimeGenerator.h"
#include <Arithm/IoEngine.h>
#include <Arithm/PrimalityEngine.h>
#include <ArithmInjector.h>
#include <iostream>

PrimeGenerator::PrimeGenerator(size_t primeLength, size_t seed)
    : _engine(seed), _primeLength(primeLength), prime(primeLength) {}

void PrimeGenerator::run(std::thread::id id) {

  std::cout << "Generating primes in thread: " << id << std::endl;
  auto &arithm = KCrypt::ArithmInjector::getInstance();

  KCrypt::PrimalityEngine prim(arithm);
  KCrypt::AddEngine add(arithm);
  KCrypt::IoEngine io(arithm);

  io.randomize(prime.getBuffer(), _engine, KCrypt::IoEngine::Sign::Unsigned);
  prime.getBuffer().data[0] |= 1;

  std::vector<KCrypt::Buffer> witnesses;
  for (size_t i = 0; i < _primeLength; ++i) {
    witnesses.emplace_back(_primeLength);
    io.randomize(witnesses.back(), _engine, KCrypt::IoEngine::Sign::Unsigned);
  }

  size_t j = 0;
  for (size_t i;;) {

    if (prim.fastModuloTest(prime.getBuffer())) {

      prim.setSuspect(prime.getBuffer());

      for (i = 0; i < witnesses.size() && prim.millerRabinTest(witnesses[i]);
           ++i) {
      }

      if (i == witnesses.size()) {
        std::cout<<"Found prime: "<<prime<<std::endl;
        return;
      }
    }
    add.add(prime.getBuffer(), 2);
  }
}
