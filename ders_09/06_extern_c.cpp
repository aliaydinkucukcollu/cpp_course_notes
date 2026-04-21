#include <iostream>

// C'de yazılmış fonksiyonu C++'da kullanmak için.
// derleyici bu komutla beraber bu fonksiyonun C fonksiyonu odluğunu
// anlıyor ve ona göre decore ediyor.
extern "C" int foo(int, int);

// çok sayıda fonksiyon varsa

extern "C" {
void func(int);
void bar(int, int);
void buz(double);
}

int main() {

  int a = 5;
  int b = 3;

  int val = foo(a, b);

  std::cout << "val: " << val << '\n';

  return 0;
}