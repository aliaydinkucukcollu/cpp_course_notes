#include <iostream>

int main() {
  int x{12};

  int *ptr = &x;

  int &r = *ptr;

  r = 45;

  std::cout << "x: " << x << '\n'; // 45

  // double *p = &x; // ERROR


  

  return 0;
}
