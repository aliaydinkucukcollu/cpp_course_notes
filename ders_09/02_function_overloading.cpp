#include <iostream>

class Myclass {};

int foo(const Myclass &); // const L value ref
long foo(Myclass &); // L value ref
double foo(Myclass &&); // R value ref

// üretimde karşılaşılan overload pattern:
void buz(const Myclass&);   // Lvalueler  için
void buz(Myclass&&);        // Rvaluelar için

int main() {
  Myclass m;
  const Myclass km;

  auto x = foo(m);
  auto y = foo(km);
  auto z = foo(Myclass{}); // PRvalue ==> R value

  return 0;
}