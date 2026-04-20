#include <iostream>

// type-cast operator valid for in C and C++
// example:
//      (int)dval

int main() {
  double dval = 24.835;
  int ival;

  ival = dval; // gerçerli, implicit conversion
  // ondalık kısım kayboluyor
  // ival = 24

  // tür dönüştürme operatörü niyet belirtmek için.
  // geliştirici ben bilerek isteyerek böyle yazdım diyor.

  int x = 10;
  int y = 3;

  auto i = x / y;         // int
  auto d = (double)x / y; // double

  return 0;
}