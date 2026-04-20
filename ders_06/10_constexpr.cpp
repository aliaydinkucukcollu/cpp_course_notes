#include <iostream>

// constexpr functions
// - başlık dosyalarına konulabilir (inline keyword kullanmadan) (ODR violation olmaz)

constexpr int ndigit(int x) {
  if (x == 0)
    return 1;
  int digit_cnt{};

  while (x) {
    ++digit_cnt;
    x /= 10;
  }
  return digit_cnt;
}

int main() {
  int x = 10;
  ndigit(x); // legal, sabit ifadesi gereken bağlamda error olacak

  int ar[ndigit(x)]; // Error

  return 0;
}