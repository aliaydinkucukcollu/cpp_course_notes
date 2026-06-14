#include <iostream>

// döngüsüz 0'dan 100'e kadar sayıları yazdır.

class Myclass {
public:
  Myclass() {
    static int x = 0;
    std::cout << ++x << '\n';
  }
};

int main() {
  Myclass ar[100];
  return 0;
}
