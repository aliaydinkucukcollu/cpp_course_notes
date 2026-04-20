#include <iostream>

// sınıfta const fonksiyonlar sınıfın non static değişken değerini değiştiremez

class Myclass {
public:
  void bar() const {
    r = 5634;
    *ptr = 213;
  }
  void foo() const {
    // bar(); // sınınfın const fonk, non-const fonk çağıramaz!
    Myclass m{};
    m.bar();
  }

private:
  int mx, my;
  int &r;
  int *ptr;
};

int main() {
  int x = 4;
  int &reff = x;
   return 0;
}