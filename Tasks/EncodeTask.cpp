#include "EncodeTask.h"
#include "Tasks/EncodeSync.h"
#include "Tasks/ExecutionContext.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"
#include <ArithmInjector.h>

EncodeTask::EncodeTask(RsaKey &key, EncodeSync &sync, unsigned char *source,
                       size_t sourceSize, unsigned char *output)
    : _key(key), _logger(Logger::getInstance()), _sync(sync), _source(source),
      _sourceSize(sourceSize), _output(output),
      _outputSize(key.size() * sizeof(KCrypt::Buffer::BaseInt)) {}

void EncodeTask::run(ExecutionContext &context) {
  /*_logger.debug("In Encryption task", "source size", _sourceSize);
  _logger.debug("In Encryption task", "output size", _outputSize);
  _logger.debug("In Encryption task", "keySize", _key.size());*/
  auto &rsa = KCrypt::ArithmInjector::getInstance().getRsa();

  if (!context.isRsaKeySet) {
    _logger.debug("Setting rsa key in context: ", context.threadNo);
    rsa.setKey(_key.getExponent().getBuffer(), _key.getModulus().getBuffer());
    context.isRsaKeySet = true;
  }

  memset(_output, 0, _outputSize);
  memcpy(_output, _source, _sourceSize);

  KCrypt::BufferView buffer(
      reinterpret_cast<KCrypt::Buffer::BaseInt *>(_output),
      _outputSize / sizeof(KCrypt::Buffer::BaseInt));

  //_logger.debug("In Encryption task", "source buffer", buffer);

  rsa.apply(buffer, buffer);

  //_logger.debug("In Encryption task", "output buffer", buffer);

  _sync.finishTask();
}
