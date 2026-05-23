#include <iostream>

class Myclass {
public:
  void foo() {
    // fonksiyon içinde x nesnesinin kopyasını oluşturma
    // için de this kullanılabilir.
    auto m = *this;
  }

  // function overloading
  Myclass* baz()
  {
    return this;
  }

  const Myclass* baz() const
  {
    return this;
  }

};

int main() {
  Myclass x;
  x.foo();

  return 0;
}
