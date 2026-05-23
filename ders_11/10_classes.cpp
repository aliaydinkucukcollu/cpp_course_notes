#include <iostream>
#include <mutex>
#include <thread>

// mutable -> concurrency example

// internal synchronization
// -> sınıfın kendisi bu senkronizasyondan sorumlu
class Array {
public:
  void foo() const{
    mtx.lock(); // non-const member function

    // code ...

    mtx.unlock(); // non-const member function
  }

private:
  mutable std::mutex mtx;
};

int main() { return 0; }