#include <iostream>

// ---- özel durumlar ----

// example-1
void foo(void *);
void foo(bool);

// example-2
int buz(int *);
int buz(double);
// int buz(int); // bu fonksiyon da dahil olursa ERROR ortadan kalkıyor ancak
// istenilen bir durum değil. bunun için nullptr kullanıyoruz.

int foo(std::nullptr_t); // nullptr için ayrı bir implementasyon istiyorsam bu
                         // şekilde tanımlayabilirim

int main() {
  int x{};
  foo(&x); // calls void foo(void*);

  // buz(0); // ERROR
  buz(nullptr); // LEGAL

  return 0;
}