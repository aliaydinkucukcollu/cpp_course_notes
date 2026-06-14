#include <iostream>
#include <string>

// ---- constructor initializer list ----
// -> btün ctorlar için ctor init. list kullanılabilir.
// -> sınıfnın tüm elemanlarını initializer list ile initilize etmek zorunlu
// değil ama best practice!

/**
 * ---- syntax ----
 * class Myclass
 * {
 * public:
 *   Myclass() : tx(expr1), ux(expr2), wx(expr3) // Modern C++'dan önce
 * private:
 * T tx;
 * U ux;
 * W wx;
 *
 * };
 *
 * class Myclass
 * {
 * public:
 *   Myclass() : mx{1.2}, ux{expr2}, wx{expr3} // Modern C++'dan sonra
 * private:
 * int mx;
 * U ux;
 * W wx;

 */

class Date {
public:
  Date() : mday(1), mmon(1), myear(1900) {}

  Date(int d, int m, int y) : mday(d), mmon(m), myear(y) {}

  // aşağıdaki ile aynı şey değil

  // Date(int d, int m, int y) {
  //   mday = d;
  //   mmon = m;
  //   myear = y;
  // }

private:
  int mday, mmon, myear;
};

// date.cpp
// Date::Date() : mday(1), mmon(1), myear(1900) {} // geçerli kod

int g{};

class Myclass {
public:
  Myclass() {
    // mr = g; // references must be initialized
    // mx = 6; // const data member cannot be changed
  }

  // Myclass() : mstr(100, 'a') {
  //   // code ...
  // }
  //

private:
  // int &mr;
  // const int mx;
  std::string mstr;
};

class Doo {
public:
  Doo()
      : ux(4.6), tx(68) // legal ama hayata gelme sırası, sınıf içinde bildirim
                        // sırasına göre, tx'i tanımlarken ux'i kullanıbilirdik.
  {}

private:
  int tx;
  double ux;
};

int main() {
  Date mydate(14, 4, 2026);

  return 0;
}
