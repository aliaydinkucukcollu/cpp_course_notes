#include <iostream>

// fonksiyonların varsayılan argüman alması (default arguments)
// - complie time'a yönelik bir araç

void foo(int x, int y); // x and y are parameters

// variadic function
void bar(int x, int y, int z, ...);

// 3. paramtreye argüman gönderilmezse 6 varsayılcak.
void baz(int x, int y, int z = 6); // z is default argument

// varsayılan argüman için fonksiyonun son parametre değişkeni için kullanılmak
// zorunda. Alttaki fonksiyon bu nedenle geçerli değil.

// void buz(int a, int b = 4, int c); // illegal
void tuu(int a, int b = 4, int c = 5);     // legal
void too(int a = 3, int b = 4, int c = 5); // legal

void fuu(int, int, int); // legal

void faa(int, int = 3, int = 2); // legal

// fonksiyon tanımında default arguments olabilir
void zoo(int a = 4) { std::cout << "a: " << a << '\n'; }

void zaa(int = 1, int = 2, int = 3);

int g = 5;

void zuu(int = g, int = g + 3); // legal

void hoo(int * = &g); // legal

void huu(const char * = "error"); // legal

int x;
void haa(int& = x); // legal

int hee(int = 5);
int roo(int = hee());


int soo(int x = ++g)
{
  std::cout << "x: " << x << '\n';
}

int main() {

  // foo(1); // ERROR
  foo(1, 3); // OKAY
  // foo(2, 5, 7); // ERROR

  // arguments
  foo(5, 6); // 5 and 6 are arguments

  // variadic function için:

  // bar(1); // illegal
  // bar(2, 5); // illegal
  bar(4, 5, 6);    // OKAY
  bar(4, 5, 6, 7); // OKAY

  // default arguments examples
  baz(2, 3);
  baz(5, 7, 9);

  zoo();
  zoo(66);

  zaa(10, 20, 30); // legal
  zaa(10, 20);     // legal
  zaa(10);         // legal
  zaa();           // legal

  huu(); // huu("error");

  roo(); // roo(hee(5));

  // g = 5 in here
  soo(); // soo(++g),  6
  soo(); // soo(++g),  7
  soo(); // soo(++g),  8

  return 0;
}

// illegal
// void zaa(int =1, int =2, int =3)
// {
//   // code
// }

// legal
void zaa(int x, int y, int z) {
  std::cout << "x: " << x << "y: " << y << "z: " << z << '\n';
}