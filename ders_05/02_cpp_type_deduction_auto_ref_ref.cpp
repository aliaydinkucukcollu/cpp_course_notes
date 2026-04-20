#include <iostream>

// 3 KATEGORİ MEVCUT
// 3. KULLANIM   ===>    auto&& x   = expr;

// forwarding reference OR universal reference

// öyle bağlamlar varki dilin kuralları dahilinde
// "reference to reference" olmamasına karşın, "reference to reference"
// oluşuyor. Ve oluştuğunda REFERENCE COLLAPSING uygulanıyor.

// REFERENCE COLLAPSING: reference to reference oluşunca uygulanan kural.

// ------------ KURAL ------------
// T&           &       ===>    T&
// T&           &&      ===>    T&
// T&&          &       ===>    T&
// T&&          &&      ===>    T&&

int &&foo();

using iref = int &;

using irefref = int &&;

int main() {
  int x = 5;
  decltype((x)); // int&

  // reference collapsing application

  decltype((x)) &y = x; // int& and & ===> int&

  decltype((x)) &&z = x; // int& and && ===> int&

  decltype(foo()) &v = x; // int&& and & ===> int&

  decltype(foo()) &&b = 5; // int&& and && ===> int&&

  // iref &x; // error çünkü int&

  int i{};
  iref &h = i; // int&

  iref &&t = i; // int&

  irefref &g = i; // int&

  irefref &&m = 4; // int&&

  // universal reference (auto &&r)
  // - herşeye bağlanır.

  // 1-) eğer ilk değer veren ifadenin value category'si L value ise
  // auto karşılığı elde edilen tür lvalue & türü.

  int num = 5;
  auto &&rnum = num; // int&

  // 2-) eğer ilk değer veren ifadenin value category'si R value ise
  // (yani x value ya da pr value) auto karşılığı elde edilen tür
  // referans olmayan tür.

  auto &&rr = 10; // int&&

  // auto &&r tipindeki ifadeler KURAL'da yer aldığı üzere
  // illaki reference türünden bir değişken olacak.
  // Ek olarak auto ne ise ifadenin türü o olacak.

  // örneğin
  int magic_number = 445566;

  auto &&mgcnum = magic_number; // & and && ==> int &

  auto &&rr_val = 100; // && and && ===> int &&

  return 0;
}