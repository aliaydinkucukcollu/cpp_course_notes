#include <iostream>

class Myclass {
public:
  void foo();

  void bar() const;

private:
};

int main() {
  const Myclass km;

  // km.foo(); // const T* ==> T* , illegal

  km.bar(); // T* ==> const T* , legal

  return 0;
}