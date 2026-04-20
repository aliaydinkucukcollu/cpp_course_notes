#include <iostream>

// lvalue references
// option-1:       T&
// option-2: const T&

// set(T&)          lvalue reference
// get(const T&)    const lvalue reference

struct Point {
  double x, y;
};

void set_point(Point &p) {}

struct Nec{};

// rvalue expression gönderemem
// const nesne gönderemem
void foo(Nec&);

// lvalue expression gönderebilirim
// rvalue expression gönderebilirim
// const nesne gönderebilirim
void bar(const Nec&);

int main() {

  Point pt{3.3, 6.7};

  set_point(pt);

  // basic reference usage
  int x = 10;
  int &r = x;

  r = 55;

  std::cout << "x: " << x << '\n';

  // references with const

  int a = 22;
  const int &kref = a; // == int const& ref
  // kref a'ya bağlanmış bi referans değişken, sadece a'ya okuma amaçlı erişim
  // için kullanılır.

  // lvalue reference rvalue expression'a bağlanamaz.
  // int& r = 10; // ERROR

  //       lvalue ref ===> lvalue
  // const lvalue ref ===> lvalue + rvalue
  const int& r1 = 10;

  return 0;
}