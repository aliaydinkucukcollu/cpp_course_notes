#include <iostream>

// ---- special member functions (özel üye fonksiyonlar) (6 adet) ----
// -> default constructor
// -> copy constructor
// -> move constructor
// -> copy assignment
// -> move assignment
// -> destructor

// -> belirli koşullar oluştuğunda derleyici bazı fonksiyonların
// kodunu yazıyor.
// -> derleyici kendi de yazabilir, biz de yazmasını bildirebiliriz.

// C++20 ile birlikte dile eklenen operatör (three-way comparison operator, <=>)
// ile birlikte bazı karşılaştırma fonksiyonlarının da kodlarının derleyici
// tarafından yazılmasını talep edebiliyoruz.

class Myclass {
public:
  Myclass() { std::cout << "Myclass default ctor\n"; }
};

// delete bildirimi, fonksiyona çağtı yapılırsa error olur.
int foo(int) = delete;

// neden ?
// -> function overload resolution' a katılıyor çünkü.

int foo(double);
int foo(float);

// default bildirimi
// -> sadece special member functions için (C++20 ile eklenen operatör hariç)

void hoo() = default; // error

class Foo {
public:
  Foo() = default; // default ctor is defaulted.
  ~Foo() = default;
};

int main() {
  Myclass m;

  foo(12); // error

  return 0;
}
