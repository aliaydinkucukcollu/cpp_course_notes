#include <iostream>

// copy constructor

class Myclass {
public:
  // constructor initializer list ==> bütün constructorlara uygulanabilir.
  Myclass(const Myclass &other) : ax(other.ax), bx(other.bx), cx(other.cx) {}

private:
  int ax;
  double bx;
  float cx;
};

class Date {
public:
  // constructor ama special member function değil
  Date(int d, int m, int y) : md(d), mm(m), my(y) {}

  // copy constructor => user decleared defined
  // yazmamız gerekmiyor zaten implicitly decleared defined idi.
  Date(const Date &other) : md(other.md), mm(other.mm), my(other.my) {
    std::cout << "copy constructor\n";
  }

  void print() const { std::cout << md << '-' << mm << '-' << my << '\n'; }

private:
  int md, mm, my;
};

// önemli not
class A {};
class B {};

class Nec {
public:
private:
  A ax; // A'nın copy constructor çağrılcak
  B bx; // B'nin copy constructor çağrılcak
};

// implementasyonu
class Abo {
public:
  Abo() = default;
  Abo(const Abo &) { std::cout << "Abo copy constructor\n"; }
};

class Bao {
public:
  Bao() = default;

  Bao(const Bao &) { std::cout << "Bao copy constructor\n"; }
};

class Neco {
public:
  Neco() = default;

  Neco(const Neco &other) : ax(other.ax), bx(other.bx) {
    std::cout << "Neco copy constructor\n";
  }

private:
  Abo ax;
  Bao bx;
};

// 1. derleyicin yazdığı copy constructor (implicitly decleared defined) işimizi
// görüyor. value semantics için kullanıyoruz zaten yani kopyalanan nesnenin
// data memberları yeni nesneye de kopyalasın diye. Ancak öyle durumlar var ki
// copy constructorı biziim yazmamız gerekiyor.

int main() {

  Date d1(12, 6, 1987);

  d1.print();

  Date d2(d1);
  d2.print(); // value semantics gereği d1 değeriyle aynı değerlere sahip

  Neco c1;
  Neco c2 = c1;

  return 0;
}
