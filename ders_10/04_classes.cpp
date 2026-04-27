#include <iostream>

class Nec {
public:
  void foo(int);
  void bar() { std::cout << "Nec::bar function\n"; }
  void buz();

private:
  void foo(double);

  int mx;
};

Nec gm;

void bar() { std::cout << "global bar function\n"; }

void Nec::buz() {

  ::bar(); // globaldeki bar
}

void Nec::foo(int) {
  // aşağıdaki 3 ifadenin anlamı aynı
  this->mx = 5;
  mx = 5;
  Nec::mx = 5;

  gm.mx = 44; // LEGAL !
}

int main() {

  Nec mynec;

  // mynec.foo(12u); // ambiguity error

  // mynec.foo(2.4); // access control error

  mynec.buz();

  return 0;
}