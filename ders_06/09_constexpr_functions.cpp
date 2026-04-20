#include <iostream>

// eskiden sert kısıtlamalar vardı artık yok
constexpr int factorial(int x) { return x < 2 ? 1 : x * factorial(x - 1); }

// eskiden tek line sınırı vardı artık yok
constexpr bool isprime(int x) {
  if (x < 2)
    return false;
  if (x % 2 == 0)
    return x == 2;
  if (x % 3 == 0)
    return x == 3;
  if (x % 5 == 0)
    return x == 5;
  for (int i = 7; i * i <= x; i += 2) {
    if (x % i == 0)
      return false;
  }
  return true;
}

// constexpr functions

// eğer bir constexpr fonksiyona yapılan bir çağrıda fonksiyon parametrelerine
// çağrıda gönderilen argümanlar constant expressions ise ve fonksiyon çağrı
// ifadesi fonksiyon çağrıs ifadesi constant expression gerektiren bir bağlamda
// kullanılmışsa derleyici fonksiyon çağrısından elde eldilen değeri compile
// time'da hesaplamak zorunda.

constexpr int sum_square(int x, int y) { return x * x + y * y; }

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

constexpr int foo(int x, int y) {
  int ival = 7;
  ival -= 6;
  --ival;
  return (x + y) / ival;
}

int main() {

  int x{};
  std::cin >> x;

  if (isprime(x)) // iki şartı da sağlamıyor
  {
    // code
  }

  int a = 10;

  // derleyici isprime fonksiyonuna yapılan çağrıdan elde
  // edilen değeri compile time'da hesaplayabilir mi? (fonksiyon constexpr
  // olmasa dahi)
  bool b = isprime(a); // evet, compiler optimization'a bağlı olarak

  const int a2 = 10; // derleyici compile time'da hesaplamak zorunda değil.
  bool b2 = isprime(a2);

  constexpr bool flag =
      isprime(a2); // derleyici isprime fonksiyonuna yapılan çağrıdan elde
  // edilen değeri compile time'da hesaplamak zorunda!!!

  const int x1 = 7;
  const int y1 = 9;

  bool bl2 =
      isprime(ndigit((sum_square(x1, y1) + 2))); // run time'da hesaplayabilir
  constexpr bool bl =
      isprime(ndigit((sum_square(x1, y1) + 2))); // compile time garantisi var

  int ar[sum_square(x1, y1)]; // compile time garantisi var

  // constexpr int resw = foo(4,7); // ERROR

  return 0;
}