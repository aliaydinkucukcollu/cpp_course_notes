#include <iostream>

// çoklu parametreli function overloading durumunda bir overload'un
// seçilebilmesi için şu koşulu sağlaması gerekiyor. En az bir parametrede
// diğerlerine üstünlük sağlayacak ancak diğer parametrelerde diğerlerinden kötü
// olmayacak.

void foo(int, double, int);
void foo(char, int, unsigned);
void foo(float, float, double);

// ----

int foo(int, double);
float foo(char, int);

int main() {

  foo(12, 12L, 3.L); // void foo(int, double, int);

  foo(12, 12L, 'a'); // void foo(int, double, int);

  foo(3u, 4L, 4u); // void foo(char, int, unsigned);

  auto x = foo('a', 20u); // float foo(char, int);

  return 0;
}