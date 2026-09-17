#include <iostream>

void foo(int = 1, int = 2, int = 3);

int main() {

  foo(12, 45, 67);
  foo(13, 56); // foo(13,56, 3);
  foo(65);     // foo(65,2,3);
  foo();       // foo(1,2,3);

  return 0;
}

void foo(int x, int y, int z) {
  std::cout << x << ' ' << y << ' ' << z << '\n';
}