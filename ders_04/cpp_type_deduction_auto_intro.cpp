#include <iostream>
#include <list>
#include <vector>

// TYPE DEDUCTION (TÜR ÇIKARIMI)
// derleyici bağlamdan türü anlıyor

// TYPE DEDUCTİON KEYWORDS
// 1-) auto
// 2-) decltype
// 3-) decltype(auto)

// AUTO TYPE DEDUCTION
// auto x = expr;

// tür çıkarımı değişken için değil auto için yapılıyor.
// örneğin:
//  const auto x = 5; ifadesi için
// auto ===> int, x ===> const auto olur.

// 3 KATEGORİ
// 1-) auto x   = expr;
// 2-) auto& x  = expr;
// 3-) auto&& x = expr; (forwarding reference OR universal reference)

int *foo(int *, int *);

int bar();
// double bar();

int main() {
  const auto x = 5;

  // NİYE TÜR ÇIKARIMI VAR?

  // 1-) Kodun daha kolay yazılması ve daha kolay okunması
  // karmaşık türlerin yazılması kolaylaşıyor

  // uzun ve karmaşık değişken türü
  std::vector<std::pair<std::list<int>::iterator,
                        std::list<int>::iterator>>::iterator iter;

  // function pointer
  int *(*fptr)(int *, int *) = foo;

  // daha kolay kullanım
  auto fp = foo;

  // verbosity(verbose) ===> karmaşık, fazla öge içeren & kod kalabalığı
  //  auto type deduction verbosity'yi ortadan kaldırıyor.

  // 2-) Kodda değişiklik yapmak kolaylaşıyor

  // bar isimli fonksiyonun türü değişirse, bu haliyle sıkıntı çıkıyor.
  int val = bar();

  // AAA: Almost Always Auto

  return 0;
}