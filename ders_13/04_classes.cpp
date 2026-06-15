#include <iostream>

// -> copy constructor
// -> move constructor
// -> copy assignment
// -> move assignment

// -> aynı türden sınıf nesnesinden değer alma -> copy ctor and move ctor
// -> aynı türden sınıf nesnesinden atama -> copy as. and move assignment

class Myclass {

public:
  Myclass() { std::cout << "default ctor\n"; }

  Myclass(const Myclass &) { std::cout << "copy ctor\n"; }
};

int main() {

  // copy constructor
  Myclass a;

  // hepsi için de copy constructor çağrılır.
  Myclass b1 = a;
  Myclass b2(a);
  Myclass b3{a};

  return 0;
}
