#include <iostream>

// reinterpret_cast
// 1-) farklı adres türleri arasındaki dönüşümler
//      1.1-) T* ==> char / signed char / unsigned char adres türlerine
//      1.2-) aynı tamsayı türünün signed ve unsigned dönüşümleri
//      1.3-) yapıların adresleri ile ilk elemanlarının adresleri arasındaki
//            dönüşümler

int main() {

  // example-1
  int x = 18;
  char *p = reinterpret_cast<char *>(&x);

  // example-2
  const int a = 14;
  char* cptr = reinterpret_cast<char*>(const_cast<int*>(&a)); // option-1
  char* ptr  = const_cast<char*>(reinterpret_cast<const char*>(&x)); // option-2

  return 0;
}