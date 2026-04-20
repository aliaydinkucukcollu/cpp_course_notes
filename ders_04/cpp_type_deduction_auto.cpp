#include <iostream>

// 3 KATEGORİ MEVCUT
// 1. KULLANIM   ===>    auto x   = expr;

int foo(int);

int main() {
  // auto ile default initialization geçerli değil.
  int x = 5;
  auto val = x;

  // ilk değer veren ifadenin türü neyse auto'ya karşılık gelen ifsdenin türü
  // odur.
  auto uval = 5u;     // unsigned int
  auto lval = 5L;     // long
  auto llval = 5LL;   // long long
  auto ullval = 5ULL; // unsigned long long
  auto dval = 5.;     // double
  auto fval = 5.f;    // float

  // integral promotion
  char c = 3;
  auto ch = c;       // char
  auto cval = c + c; // int
  auto y = +c;       // int

  // C and C++ type differences
  int a = 5, b = 3;
  auto z = x > y; // bool in C++, int in C
  auto v = 'A';   // char in C++, int in C

  // const and auto
  const int kval = 10;
  auto ival = kval; // int

  // bir değişkenin decleration type'ı ile ifadenin type'ı aynı şey
  // değil.
  int ivar = 5;
  int &r = ivar;

  int g = 4;
  const int &gref = g;
  auto ag = gref; // int

  // auto and arrays

  // bir dizi ismi initializer olarak kullanıldığında ve auto type deduction
  // kullanıdığında önce ARRAY DECAY uygulanır. ARRAY DECAY: diz isminin bir
  // ifade içinde kullanılmasında dizinin ilk elemnanının adresine
  // dönüştürülmesi.
  int ar[5]{};
  auto aa = ar; // int*

  const int kar[5]{};
  auto akar = kar; // const int*

  // string literals
  auto str = "cavit"; // "cavit" : const char[6]
  // ARRAY DECAY: auto ===> "const char *"

  // function pointers : FUNCTION DECAY
  auto fres = &foo; // int (*)(int)

  auto xx = foo; // int (*)(int)

  return 0;
}