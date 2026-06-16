#include <iostream>

class A {
public:
  A() = default;

  A(const A &) { std::cout << "copy ctor\n"; }
  A(A &&) { std::cout << "move ctor\n"; }
};

class Myclass {
public:
  Myclass() = default; // default constructor => user decleared deafulted

  Myclass(const Myclass &); // copy constructor

  // Myclass(Myclass &&); // move constructor
};

int main() {

  A a1;
  A a2(a1);

  A a3(A()); // most vexing parse

  A a4(A{}); // neden move ctor çağrılmadı ==> mandatory copy allision

  // sınıfın move ctor'ı yoksa
  // her durumda copy ctor çağrılır. => fall-back
  Myclass m1;
  Myclass m2(m1);
  Myclass m3(
      Myclass{}); // move ctor olmadığı için copy ctor'a fall-back oluyor.

  return 0;
}
