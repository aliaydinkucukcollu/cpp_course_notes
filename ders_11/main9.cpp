#include <iostream>

class Zort {
public:
  void foo() { std::cout << "this: " << this << '\n'; }
};

int main() {

  Zort z;
  z.foo();

  std::cout << "&z:   " << &z << '\n';

  return 0;
}