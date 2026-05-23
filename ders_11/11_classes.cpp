#include <iostream>

// this keyword  ve pointer
// -> "this pointer" olarak biliniyor

class Myclass {
public:
  void foo() {
    // aşağıdaki iki cümle farklı anlamlarda
    // 1. this kullanıldığı zaman bu fonksiyon hangi nesne için çağrılırsa
    // onun adresini kullanmış oluyoruz.
    // çünkü this keywordünün oluşturduğu ifade R value. L vsalue değil.

    // 2. bu fonksiyonun gizli parametre değerini kullanmış oluyorum.

    std::cout << "this: " << this << '\n';

    // anlamsal açıdan aşağıdaki 3 satır aynı
    mx = 5;
    Myclass::mx = 5;
    this->mx = 5;
  }

  void bar() {}

private:
  int mx;
};

int main() {

  Myclass m;
  std::cout << "&m: " << &m << '\n';

  m.foo();

  return 0;
}
