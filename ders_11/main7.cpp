#include <iostream>
#include <mutex>

// concurrency

// internal synchronization
class Array {
public:
  void foo() const {
    mtx.lock(); // non-const function
    // ..
    mtx.unlock(); // non-const function
  }

private:
  mutable std::mutex mtx; // derleyiciye mtx değişkeninin sınıfın elemanıyla
                          // alakası yok diyoruz.
};

// lambda expression ==> mutable farklı anlamda

int main() { return 0; }