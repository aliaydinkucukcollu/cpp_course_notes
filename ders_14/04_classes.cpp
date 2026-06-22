#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

class String {
public:
  // constructor
  String(const char *p)
      : mlen(std::strlen(p)), mp(static_cast<char *>(std::malloc(mlen + 1))) {
    std::cout << "constructor\n";
    std::strcpy(mp, p);
  }

  // copy constructor
  String(const String &other)
      : mlen(other.mlen), mp(static_cast<char *>(std::malloc(mlen + 1))) {

    std::cout << "copy constructor\n";
    std::strcpy(mp, other.mp);
  }

  // -------------- Önemli Not --------------------
  // copy constructor user decleared ise
  // copy assignment is implictly decleared defaulted by compiler olur.
  // copy assignment tanımlamamak kodu derleyice
  // bırakmak pek iyi bir fikir değildir.
  // ----------------------------------------------
  //
  // NEDEN? ==> derleyici nasıl yazıyor ?

  // String &operator=(const String &other) {
  //  mlen = other.mlen;
  //  mp = other.mp; // bu atamayla pointer da kopyalanıyor ve UB'ye neden
  //  oluyor.
  //
  //  return *this;
  // }

  // user decleared copy assignment
  String &operator=(const String &other) {

    // check self assignment
    if (this == &other) {
      return *this;
    }

    std::cout << "copy assignment\n";

    std::free(mp);

    mlen = other.mlen;

    mp = static_cast<char *>(std::malloc(mlen + 1));

    std::strcpy(mp, other.mp);

    return *this;
  }

  // copy assignment fonksiyonunda aşağıdaki hatadan var:
  // self-assignment problem: bir nesnesnin kendisine atanması problemi
  //
  // int x = 10;
  // x = x;
  //
  // String s("message");
  //
  // s = s; // FELAKATE YOL AÇAN PROBLEM !!!!
  //
  // Çünkü:
  // -> std::free ile kaynak geri veriliyor sonrasında UB olur!

  // neden copy assignment *this döndürür ?
  // -> C'den gelen konvensiyonel yapı.
  //
  // int foo() { return 42; }
  //
  // int x, y, z, t;
  // x = y = z = t = foo();

  // copy swap idiom
  // -> copy assignment bu idiom ile daha farklı yazılır.
  //    exception handling ile ilgili.

  // overload of assignment operator (atama operatör fonksiyonunun overload'u)

  String &operator=(const int &value) {
    std::cout << "String& operator=(const int& value) is called\n";
    return *this;
  }

  void reverse() {
    for (size_t i{}; i < mlen / 2; ++i) {
      std::swap(mp[i], mp[mlen - 1 - i]);
    }
  }

  void print() const { std::puts(mp); }

  ~String() {
    if (mp) {
      std::free(mp);
    }
  }

private:
  std::size_t mlen;
  char *mp;
};

void foo(String str) { str.print(); }

int main() {
  String s1("Mehmet Goktug Gurler");
  s1.print();

  {
    String s2("Ali Aydin Kucukcollu");
    s2.print();
    s2 = s1;
    s2.print();
  }

  // s1 için çağrılan destructor double dillision'a neden olacak.
  (void)getchar();

  s1.print();

  // call overload function
  String s3("dummy message in here....");

  s3 = 4;

  return 0;
}
