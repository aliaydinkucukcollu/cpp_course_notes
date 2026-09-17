#include <iostream>

int main() {
  int x{12};
  int y = 56;

  // L value reference
  int &r = x;

  std::cout << "x: " << x << '\n';
  std::cout << "r: " << r << '\n';

  std::cout << "&x: " << &x << '\n';
  std::cout << "&r: " << &r << '\n';

  ++r;

  std::cout << "x: " << x << '\n';

  r = y;

  std::cout << "x: " << x << '\n';

  int &r2 = r;
  int &r3 = r2;


  r3 = 444;
  ++r2;

  std::cout << "x: " << x << '\n'; // 445

  return 0;
}
