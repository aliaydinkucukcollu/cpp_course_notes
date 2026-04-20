#include <iostream>

// ---- ODR (One Definition Rule) ----
// - bazı varlıkların birden fazla bildirimi olabilir ancak bütün projede tek
// bir tanımı olmak zorunda.

// eğer bu kural aynı kaynak dosyada çiğnenirse code ill-formed olur.
// ama farklı kaynak dosyalarda çiğnersek code UB olur.

// bildirim ==> decleration
// tanım    ==> definition

int x = 4; // definition

extern int a; // decleration

// non-defining decleration

struct Data; // legal, decleration

// definition
struct Foo {
  int a, b, c;
};

int foo(int); // decleration

// definition: fonksiyonun ana bloğunun da olması lazım
int buz(int) { return 1; }

// function redecleration
int bar(int x);
int bar(int x);
int bar(int x);
int bar(int x);
int bar(int x);
int bar(int x);

// her ikisi de decleration ERROR değil
class A;
class A;

// ODR violation (ihlali)
struct Zaa {
  int a, b, c;
};

// struct Zaa {
//   int a, b, c;
//   double d;
// };

// -- ahmet.h --
int ax; // başlık dosyasına  global değişken tanımı konmamalı! Aynı projede
        // birden fazla kaynak dosya include ederse ==> ODR violation

extern int eax; // bunda sıkıntı yok

void boz(int x) // başlık dosyasına bu şekilde fonksiyon tanımı koymak ==> ODR
                // violation
{}

// bazı istisnalar ODR vialotion olmuyor. (token-by-token aynı olması şartıyla.)
// 1-) inline functions
// örneğin: token-by-token aynı olmadığı için ==> ODR violation

// ahmet.cpp
inline int sum(int x, int y) { return x + y; }

// mehmet.cpp
// inline int sum(int x, int y)
// {
//     int result = x + y;
//     return result;
// }

// 2-) template kodlar için de geçerli.

// 3-) class definitions

// 4-) constexpr değişkenler implicitly inline kabul ediliyor!
// dolayısıyla ODR ihlali olmuyor.

// ahmet.h
constexpr int inum = 18;
