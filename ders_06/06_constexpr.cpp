#include <iostream>

// constexpr
// - Modern C++ ile geldi, anlamı her standartta gelişti.
// - constant expression
// - tür değil! specifier!
// - constexpr specifier ile tanımlanan değişkenler otomatik olarak const
// oluyor.
// - initialize edilirken sabit ifadesi gerekiyor.

int get_size();

int main() {
  // değişken ile kullanım
  constexpr int x = 5; // x'in türü: const int

  constexpr const int a = 4; // legal ama const burada redundant.

  // int* xptr = &x; // error!

  // ---- const recap ----
  // const yerine constexpr ne değiştiriyor?
  const int y = 10; // constant expression in C++

  const int size = 55;
  int ar[size]; // C'de illegal, C++'da legal.

  const int sz = get_size();

  // int ar[sz]; // legal değil

  // ---- NEDEN ? ----
  // const bir değişkene
  // a) sabit ifadesiyle ilk değer verilebilir.
  //    const değişkeninin oluşturduğu ifade "bir sabit ifadesisidir."
  // b) sabit ifadesi olmayan bir değerler ilk değer verilebilir.
  // const değişkeninin oluşturduğu ifade "bir sabit ifadesi değildir."

  // ---- constexpr'de durum nasıl? ----
  // Eğer constexpr anahtar sözcüğü ile bir değişken tanımlanırsa
  // derleyici compile time'da ona ilk değer veren ifadeninin contant expression
  // olup olmadığını kontrol etmek zorunda.

  // constexpr değişken diyor ki benim oluşturduğum ifade constant expression
  // gereken yerde kullanılabilir. legal olması için sabit ifadesi ile
  // initilize edilmesi gerekiyor.
  // Bu nedenle

  constexpr double dval = 4.56; // ifadesi gerçerli iken
  // constexpr int ival = get_size(); // ifadesi geçersiz

  // 1-) constexpr değişkenler sabit gibi kullanılabilir.
  //    - değişkenimizin compile time'da kullanılacağını ima etmiş oluyoruz.

  constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  return 0;
}