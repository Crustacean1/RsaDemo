#include "RsaKey.h"

RsaKey::RsaKey() {}

RsaKey::RsaKey(const KCrypt::Numeric &exponent, const KCrypt::Numeric &modulus)
    : _exponent(exponent), _modulus(modulus) {}

void RsaKey::save(std::ostream &stream) {
  stream << _keyStart << "\n";
  stream << _modulus.size() << "\n";
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
  size_t keySize = 0;
  stream >> keySize;
  KCrypt::Numeric _exponentBuffer;
  KCrypt::Numeric _modulusBuffer;

  stream >> _exponentBuffer;
  stream >> _modulusBuffer;

  _exponent = KCrypt::Numeric(keySize);
  _modulus = KCrypt::Numeric(keySize);

  _exponent = _exponentBuffer;
  _modulus = _modulusBuffer;

  stream >> buffer;
  if (buffer != std::string(_keyEnd)) {
    throw std::runtime_error("Invalid end of key file: " + buffer);
  }
}

size_t RsaKey::size() { return _modulus.size(); }

KCrypt::Numeric &RsaKey::getModulus() { return _modulus; }
KCrypt::Numeric &RsaKey::getExponent() { return _exponent; }
