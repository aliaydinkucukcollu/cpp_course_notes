#include <iostream>
#include <utility>

// fonksiyona gelen argüman L value ===> kaynağı kopyala
// fonksiyona gelen argüman R value ===> kaynağı çal

class Myclass {};

// 2 overload oluştur

// L value için
void foo(const Myclass &r) {
  Myclass m = r;

  // ya da
  Myclass m2;

  m2 = r;
}

// R value
void foo(Myclass &&r) {
  // m nesnesi çalışıyor kaynağı
  Myclass m = std::move(r);

  // ya da
  Myclass m2;

  m2 = std::move(r);
}

int main() { return 0; }
