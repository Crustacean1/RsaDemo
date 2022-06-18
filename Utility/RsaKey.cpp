#include "RsaKey.h"

RsaKey::RsaKey() {}

RsaKey::RsaKey(const KCrypt::Numeric &exponent, const KCrypt::Numeric &modulus)
    : _exponent(exponent), _modulus(modulus) {}

void RsaKey::save(std::ostream &stream) {
  stream << _keyStart << "\n";
  stream << _exponent << "\n";
  stream << _modulus << "\n";
  stream << _keyEnd << std::flush;
}

void RsaKey::load(std::istream &stream) {
  std::string buffer;
  stream >> buffer;
  if (buffer != std::string(_keyStart)) {
    throw std::runtime_error("Invalid start of key file: " + buffer);
  }
  stream >> _exponent;
  stream >> _modulus;

  stream >> buffer;
  if (buffer != std::string(_keyEnd)) {
    throw std::runtime_error("Invalid end of key file: " + buffer);
  }
}
