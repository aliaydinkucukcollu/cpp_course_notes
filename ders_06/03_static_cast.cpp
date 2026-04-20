#include <cstdlib>
#include <iostream>

// static_cast
// 1-) aritmetic türdeki bütün dönüşümler
// 2-) void T* ==> T*
// 3-) tamsayı türleri ile enumlar arası dönüşümler

int main() {

  // 1-)
  // example-1
  int x = 10, y = 3;
  double dval = static_cast<double>(x) / y;

  // example-2
  char c = static_cast<char>(x);

  // farklı bir operatör kullanmak hataya neden olur
  // double d = const_cast<double>(y); // illegal

  // 2-) void T* ==> T*
  int *mptr = static_cast<int *>(malloc(100 * sizeof(int)));

  // 3-) tamsayı türleri ile enumlar arası dönüşümler
  enum Color { White, Yellow, Red, Brown, Blue, Black };
  int num = 3;
  // Color mycolor = num; // illegal
  Color mycolor = static_cast<Color>(num);

  // 4-) tersi: enum to tamsayı dönüşümü
  Color color = Brown;
  // int ival = color; // implicit conversion, legal ama önerilmiyor
  int ival;
  ival = static_cast<int>(color);

  return 0;
}