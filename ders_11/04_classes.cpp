#include <iostream>

// syntax of const member functions

class Myclass {
public:
  void bar() const {
    // const üye fonksiyon sınıfın referans elemanı varsa, referansın bağlandığı
    // nesneyi değiştirebilir. pointer elemanı varsa pointerın gösterdiği değeri
    // değiştirebilir.
    r = 345345;
    *ptr = 23234;

    // ptr'ye atama yapılsa illegal olurdu.
    // ptr = ...;
  }

private:
  int &r;
  int *ptr;
};

int main() { return 0; }