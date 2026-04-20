#include <iostream>

// traling return type (sonradan gelen)
auto foo() -> int { return 4; }

// auto return type
auto bar() {}

// genrric progralamada kullanımı
template <auto N> class Myclass {};

int main() {

  std::cout << foo() << '\n';

  return 0;
}