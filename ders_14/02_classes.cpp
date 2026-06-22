// Myclass a, b;
// a = b; => 2 adet çağrılan special member function
// -> copy assignment
// -> move assignment
//
// biri function overload resolutionda L valueları alırken
// diğeri R valuları alacak.

// operator= -> operator assignment

// operator overloading
// X x1;
// X y1;
// x1 + y1 => bir sınıf nesnesi bir operatörün operandı olduğunda => fonksiyon
// çağrısı => 'operator functions' olarak adlandırlırlar.
//
// fonksiyon isimlendirmesinin kuralı var => operator keyword ve operatör tokenı
//
// operator+
// operator/
//
// copy assignment bir special member functiondır => non-static, inline, public.
// aynı zamanda operator function.
//
// operator= -> operatör atama

#include <iostream>

class A {};
class B {};

class Myclass {
public:
  // default contstructor
  Myclass() : ax(), bx() {}

  // copy contstructor
  Myclass(const Myclass &other) : ax(other.ax), bx(other.bx) {}

  // copy assignment
  // -> ctor olmadığı için initializer list kullanılamaz.
  // -> geri dönş türü L value ref.
  // -> derleyicinin yazdığı şekilde:
  Myclass &operator=(const Myclass &other) {
    ax = other.ax;
    bx = other.bx;
    // ax ve bx sınıf türündense onların da copy assignment operatörleri
    // çağrılacak.
    //
    // privitive türdense(int,double) int'e int atanır.
    //
    // pointer türündense pointerlar birbirine kopyalanır. Bu da istediğimiz
    // birşey değil. sınıfa pointer koyarsak bunları bizim yazmamız lazım.

    std::cout << "copy assignment\n";

    std::cout << "this: " << this << '\n';
    std::cout << "&other: " << &other << '\n';

    return *this;
  }

  // destructor
  ~Myclass() {}

private:
  A ax;
  B bx;
};

int main() {
  Myclass a, b;

  std::cout << "&a: " << &a << '\n';
  std::cout << "&b: " << &b << '\n';

  a = b;

  // a.operator=(b);

  return 0;
}
