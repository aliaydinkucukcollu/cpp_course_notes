#include <iostream>
#include <string>

// legal
class Myclass {
public:
  Myclass(int x, int y) : x(x), y(y) {}

  void print() const {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
  }

private:
  int x;
  int y;
};

// Modern C++ ile birlikte legal.
class Foo {
public:
private:
  int mx = 10; // mx'i 10 değeri ile initialize ettim ==> yanlış ifade. =>
               // default member initializer
  int my{14};

  // int mz(34); // geçersiz
};

int main() {

  Myclass m(10, 90);
  m.print();

  std::string str(68, 'A');
  std::cout << str << '\n';

  // legal -> çağrılan ctor -> sınıfın init list parametreli ctor'ı
  std::string str2{68, 'A'};
  std::cout << str2 << '\n';

  return 0;
}
