// ---- special member functions ----
// -> default constructor
// -> copy constructor
// -> move constructor
// -> copy assignment
// -> move assignment
// -> destructor

// bir sınıfın special member fonksiyonu şunlardan biri olmalı:
// 1-> not declared
// 2-> user declared : foksiyonu programcı bildiriyor.
// 3-> implicitly decleared

#include <iostream>

class Nec {
public:
  // 1 not decleared
  Nec(int); // Nec sınıfının def. ctor'ı yok ==> not decleared

  // 2 user decleared
  // Nec(); // derleyici kodu yazmaz.
  // Nec() = default;
  // Nec() = delete;

  // 3 implicitly decleared (zıttı ==> explicit conversion)
  // -> derleyici special member function bildirmesi gerektiğini anlıyor ve
  // bildiriyor ve tanımlıyor. => implicitly decleared defaulted.
};

// 6 adet special member function var => implicitly decleared
class Dummy {
public:
};

class Myclass {
public:
  Myclass(const Myclass &); // copy constructor
  // copy constructor bildirildiği için def.ctor yok, move constructor ve move
  // assignment da yok.
};

// implicitly decleared deleted
// -> derleyici special member function default etmesi gereken s.m.f.'nı delete
// edecek.

// DİKKAT => derleyicinin sınıfın default ctor'ını default etmesi şu şekilde
// olur. sınıfın bütün non-static date member'larının default init. eder.
class Zort {
public:
  int mx, my;

  const int mz; // default ctor için delete bildirimi yapıcak. ==> implicitly
                // decleared deleted
};

int main() {
  // Nec mynec; // No matching constructor for initialization of 'Nec'

  Zort z; // derleyici z'nin elemanlarını default initialize etti.
  // z'nin sahip olduğu mx ve my değerleri garbage value aslında.

  // call to implicitly-deleted default constructor of 'Zort'
  // hatası şundan dolayı alınıyor:
  // 1 Zort sınıfında const var
  // 2 default ctor ı derleyici tsrafından belirlenecek
  // 3 default ctor ile default init. edilecek.
  // 4 const nesnenin default init edilmesi kurallara aykırı.
  // 5. derleyici default ctor'ı delete edecek. => implicitly decleared deleted

  return 0;
}
