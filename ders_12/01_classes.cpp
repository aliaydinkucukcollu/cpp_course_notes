#include <iostream>

// ---  constructor ---
// constructor -> standarda göre member function değil
// -> geri dönüş kavramı yok
// -> public, private, protected olabilir
// -> ismiyle çağrılamaz
// -> sınıfın ismiyle aynı isimde olmak zorunda
// -> overload edilebilir
// -> const member function olamaz.
// -> static member function olamaz.
// -> ctor içinde this pointerı kullanılabilir.
// -> sınıf nesenesini kullanılabilir bir varlık haline getiriyor.

// => storage duration
// storage : nesnesnin bellekte kapladığı yeri
// storage duration => o yerin tutulduğu süre
// => life-time: nesnenin hayatta olduğu süre
//
// => storage duration life-time'ı içine alana bir kavram.

// constructor'ın çalışmasının bitmesiyle ile sınıf nesnesi hayata geliyor
// destructor'ın koduna girdiğinde ise nesnenin hayatı bitiyor.

// --- destructor ---
// ~sınıf ismiyle aynı
// destructor overload edilemez.
// geri dönüş değeri yok
// parametresiz olamk zorunda
// const anahtar sözcüğü kullanılamaz
// static anahtar sözcüğü kullanılamaz
// destructor ismiyle çağrılabilir (legal)

class Myclass {
public:
  Myclass();

  Myclass(int);

  Myclass(int, int);

  // Myclass() const;
  // static Myclass(); // error

  // destructor
  ~Myclass();
};

Myclass::Myclass() {
  // code ...
}

int main() {
  Myclass m;

  m.~Myclass(); // UB
  // öyle bir durum var ki kendi istediğimiz bir bellek alanı var,
  // allocate edilmemiş ama deallocate edilmesi gerekiyor. Bu senaryoda destroct
  // ismiyle çağtılır.

  return 0;
}
