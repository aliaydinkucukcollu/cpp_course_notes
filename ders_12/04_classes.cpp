#include <array>
#include <iostream>

// -> default ctor ne zaman çağrılacak ?
// -> sınıfın default ctor olması zorunlu değil, olmayabilir.
// -> olmadığı takdirde ve default ctor çağrılacak şekilde nesne oluşturulursa
// -> hata alırız.

// -> sınıfın default ctor'ı olmayabilir. Ama tasarım gereği böyle oldupundan
// emşn olmak gerek.
// -> Aksi halde default ctor ile kullanılabilecek durumlarda sınıfı
// kullanamayız.

class Myclass {
public:
  Myclass() { std::cout << "Default ctor... this: " << this << '\n'; }

  ~Myclass() { std::cout << "dtor ... this: " << this << '\n'; }

  char buf[16]{};
};

class Hoo {
public:
  Hoo(int x) { std::cout << "Myclass(int x) x = " << x << '\n'; }
  Hoo(int, int);
};

int main() {

  // default initialization kullanılırsa -> default ctor çağrılır
  Myclass m1;

  // value initialization -> default ctor çağrılacak
  Myclass m2{};

  // Hoo h; // error => no matching constructor for initialization of 'Hoo'

  Myclass m(); // local function decleration

  Hoo h1(234); // direct initialization

  Hoo h2 = 45; // copy initialization

  Hoo h3{44}; // list initialization (after Modern C++) == uniform
              // initialization == brace initialization

  // narrowing conversion
  Hoo h4(1.2);
  Hoo h5 = 1.2;

  // brace initialization rejects narrowing conversion at compile time.
  // Hoo h6{1.2}; // ERROR !!!

  // diziler ile kullanım
  constexpr auto sz = sizeof(Myclass);

  Myclass ar[10]; // her bir eleman için default ctor çağrılcak.

  // daha iyi kullanım
  std::array<Myclass, 10> mar;

  return 0;
}
