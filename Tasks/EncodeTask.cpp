#include "EncodeTask.h"
#include "Tasks/EncodeSync.h"
#include "Tasks/ExecutionContext.h"
#include "Utility/Logger.h"
#include "Utility/RsaKey.h"
#include <ArithmInjector.h>

EncodeTask::EncodeTask(RsaKey &key, EncodeSync &sync, unsigned char *data)
    : _key(key), _logger(Logger::getInstance()), _sync(sync), _data(data),
      _outputSize(key.size() * sizeof(KCrypt::Buffer::BaseInt)) {}

void EncodeTask::run(ExecutionContext &context) {
  auto &rsa = KCrypt::ArithmInjector::getInstance().getRsa();

  if (!context.isRsaKeySet) {
    rsa.setKey(_key.getExponent().getBuffer(), _key.getModulus().getBuffer());
    context.isRsaKeySet = true;
  }

  KCrypt::BufferView buffer(reinterpret_cast<KCrypt::Buffer::BaseInt *>(_data),
                            _outputSize / sizeof(KCrypt::Buffer::BaseInt));

  rsa.apply(buffer, buffer);

  _sync.finishTask();
}
