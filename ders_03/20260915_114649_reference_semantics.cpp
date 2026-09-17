#include <iostream>

int main() {
  int x{11};
  int y{22};

  int *ptr = &x;

  int *&r = ptr;

  std::cout << "ptr: " << ptr << '\n';
  std::cout << "r: " << r << '\n';

  std::cout << "*ptr: " << *ptr << '\n';
  std::cout << "*r: " << *r << '\n';

  *r = 44;
  std::cout << "*ptr: " << *ptr << '\n';

  r = &y;
  std::cout << "*ptr: " << *ptr << '\n';

  *r = 1000;
  std::cout << "y: " << y << '\n';

  return 0;
}
