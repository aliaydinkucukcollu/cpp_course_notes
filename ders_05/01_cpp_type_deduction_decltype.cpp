#include <iostream>

// TYPE DEDUCTION KEYWORDS
// 1-) auto
// ----> 2-) decltype
// 3-) decltype(auto)

// decltype (decleration type)
// - specifier
// - tür belirtiyor: tür bilgisi gereken her yer yerde decltype ile elde edilen
// türü kullanabiliriz.

// usage:
//      decltype(???)

// örneğin:
// - fonksiyonun geri dönüş değeri türü
// - değişkenin türü
// - fonksiyonun parametre değişkeninin türü
// - yapının türü

// 2 KURAL MEVCUT
// 1-) operand İSİM ise  ===> decltype(x)

// 2-) operand İFADE ise ===> decltype(x + 5)

int main() {

  // 1. KURAL ===> operand İSİM ise ===> decltype(x)
  int x = 5;
  decltype(x); // int

  const int y = 4;
  decltype(y); // const int

  int z = 5;
  int &ref_z = z;

  decltype(ref_z); // int&

  const int &kref_z = z;
  // decltype(kref_z) knum; // references must be initialize

  int ar[10]{};
  decltype(ar) dar; // int dar[10]

  int ar2d[10][20];
  decltype(ar2d) dar2d; // int dar2d[10][20]

  const decltype(z) int_dec = 10; // const int

  decltype(x) *p = &z; // int*

  // 2. KURAL ===> operand İFADE ise ===> decltype(x+5)
  // hangi türün elde edildiği ifadenin value catogorysine bağlı.

  // primary value categories
  // 1-) eğer ifade türü "pr value" ise ===> T
  // 2-) eğer ifade türü "l value"  ise ===> T&
  // 3-) eğer ifade türü "x value"  ise ===> T&&

  // combined value category
  // 1-) prvalue OR xvalue ===>  rvalue
  // 2-)  lvalue OR xvalue ===> glvalue

  decltype(x + 3); // int

  decltype(2.3); // double

  int array[20]{};
  decltype(array[3]); // int&

  int mynum = 4;
  int* mynum_ptr = &mynum;

  decltype(*mynum_ptr); // int&

  decltype(x++); // int

  decltype(++x); // int&

  // x value açıklaması

  int foo();   // geri dönüş değeri: prvalue

  int& bar();  // geri dönüş değeri: lvalue
  
  int&& baz(); // geri dönüş değeri: xvalue

  decltype(foo()) f1; // int

  decltype(bar()); // int&

  decltype(baz()); // int&&


  int i{};
  
  decltype(i); // 1. kural ===> int
  
  decltype((i)); // 2. kural ===> int&
  

  return 0;
}