#ifndef SINGLETON
#define SINGLETON

template <typename T, typename... Args> class Singleton {

  static T *_instance;

protected:
  Singleton() {}

public:
  Singleton(const Singleton &) = delete;
  Singleton operator=(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton operator=(Singleton &&) = delete;

  static T &createInstance(Args... args) {
    static T instance(args...);
    _instance = &instance;
    return instance;
  }
  static T &getInstance() { return *_instance; }
};

template <typename T, typename... Args>
T *Singleton<T, Args...>::_instance = nullptr;

#endif /*SINGLETON*/
