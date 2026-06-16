#include <iostream>

// function overloading for member functions.
class A {
public:
  void func(const int &) { std::cout << "L value passed\n"; }
  void func(int &&) { std::cout << "R value passed\n"; }
};

class B {
public:
  // function overloading
  void foo(const B &) { std::cout << "const B&\n"; }
  void foo(B &&) { std::cout << "B &&\n"; }
};

int main() {

  A ax;
  ax.func(12); // void func(int &&);

  int x{};
  ax.func(x); // void func(const int&);

  B b1, b2;
  b1.foo(b2); // L value call

  b1.foo(B{}); // R value call

  return 0;
}
