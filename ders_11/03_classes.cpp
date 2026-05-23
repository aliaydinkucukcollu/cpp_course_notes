#include <iostream>

// syntax of const member functions

class Myclass {
public:
  void bar() const {}

  void buz() {}

  void foo() const {
    // const member functions sınıfın non-static elemanları üzwerinde set işlemi
    // yapamaz. mx = 5; my = 13;

    bar(); // legal

    // sınıfın const üye fonsiyonları non-const üye fonksiyonlarını çağıramaz
    // buz(); // illegal

    Myclass m;
    m.bar(); // legal
  }

private:
  int mx, my;
};

int main() { return 0; }