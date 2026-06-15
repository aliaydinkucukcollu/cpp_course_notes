#include <iostream>

class Myclass {
public:
  // default ctor is implicitly decleared
  void print() const { std::cout << "mx: " << mx << '\n'; }

private:
  int mx;
};

Myclass g_m;

int main() {

  Myclass m; // default initialization
  m.print(); // def. ctor yok ise garbage value

  Myclass m2{}; // value initialization
  m2.print();   // def. ctor sayesinde 0

  // ctor kullanıcı tarafından değil derleyici tarafından yazıldığı için
  // standard garanti ediyor.

  // zero initialization: belirli init. modellerinde ön işleme olarak
  // kullanılır.
  // -> aritmetic türden değişkenler 0 olarak başlar
  // -> pointer ise nullptr
  // -> bool ise false olarak başlar.

  // static storage
  // 1 -> static initialization
  g_m.print();
  // 2 -> zero initialization

  // static yerel değişken
  static Myclass sm;
  sm.print();

  return 0;
}
