#include <iostream>

// bazı sınıf nesneleri hayatta olduğu sürece kaynak(resource) tutuyor.
// resource -> mutex, smafor, dosya, ...

// RAII(Resource Acquisition Is Initialization) idiom / acroynm
// ctor sınıf nesnesinin kullanacağı kaynağı sınıf nesnesine bağlıyor.
// dtor ise kanakları geri veriyor.

// ctor ne zaman çağrılıyor?
// dtor ne zaman çağrılıyor?

// ---- storage duration types ----
// -> automatic
// -> static
// -> dynamic
// -> thread-local

class Myclass {
public:
  Myclass() // default ctor
  {
    std::cout << "Myclass ctor this: " << this << '\n';
  }
  ~Myclass() { std::cout << "Myclass dtor this: " << this << '\n'; }
};

// çağrılma sırası garanti altında.
// ilk çağrılan ctor g1 için, en son gnec için.
// en son hayata gelen gnec için dtor ilk çağrılacak.
Myclass g1, g2, g3;
// Nec gnec;

// Static Initialization Order Fiasco
// -> hangi nesnesnin daha önce hayata geleceği garanti altında değil.
// -> aynı kaynak dosyadaki nesnelerin hayata gelme sırası belli.
// -> farklı kaynak dosyadaki nesnelerin hayata gelme sıraları belli değil.
// -> farklı kaynak dosyadaki nesnleri belirli bir sırayla çalıştırmak
// geliştirici sorumluluğunda.

// a.cpp
// A ga;

// b.cpp
// B gb;

// c.cpp
// C gc;

void foo() {
  // int x = 10; // otomatik ömürlü

  // static int y = 5; // static ömürlü, hayata gelmesi için çağrılmaıs lazım

  // Myclass m; // otomatik ömürlü

  static int call_cnt = 0;
  std::cout << "foo called: " << ++call_cnt << '\n';

  static Myclass sobj; // hayata gelmesi için, ctor çağrılması için foo()'nun
                       // çağrılması lazım. theread-safe. (concurrency tarafında
                       // bakılacak tekrar.)
}

void hoo() {
  int x = 10; // otomatik ömürlü değişken
  static int y = 18;

  std::cout << "x= " << x << " y= " << y << '\n';
  ++x, ++y;

  Myclass h;

  { // nesne hayatı başlıyor.
    Myclass mobj;
  } // nesne hayatı bitiyor.

} // otomatik ömürlü değişkenin ömrü bitiyor

int main() {

  std::cout << "main called\n";

  foo();
  foo(); // nesnesinin hayatı devam ediyor. yenisi oluşmuyor.
  foo();

  hoo();
  hoo();
  hoo();
  hoo();
  hoo();

  Myclass *mptr; // ctor çağrılmaz.

  // ctor sadece 1 kere çağrılacak.
  Myclass m;
  Myclass &r1{m};
  Myclass &r2{r1};
  Myclass &r3{r2};

  // dinamik ömürlü nesne
  auto ptr = new Myclass; // nesne hayata geldi
  delete ptr;             // nesnenin hayatı bitti
  ptr = nullptr;

  // thread local ömürlü nesne ileride görülecek.

  std::cout << "main terminates\n";

  return 0;
}
