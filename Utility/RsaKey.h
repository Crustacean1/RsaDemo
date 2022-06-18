#ifndef RSA_KEY
#define RSA_KEY

#include <Numeric.h>
#include <iostream>

class RsaKey {
  KCrypt::Numeric _exponent;
  KCrypt::Numeric _modulus;

  static constexpr const char * _keyStart = "-----BEGIN-KEY-----";
  static constexpr const char * _keyEnd = "-----END-KEY-----";

public:
  RsaKey();
  RsaKey(const KCrypt::Numeric &exponent, const KCrypt::Numeric &modulus);

  void save(std::ostream &stream);
  void load(std::istream &stream);

  size_t size();

  const KCrypt::Numeric &getExponent();
  const KCrypt::Numeric &getModulus();
};

#endif /*RSA_KEY*/
