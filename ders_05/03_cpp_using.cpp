#include <iostream>

// using keyword

using iptr = int *;

using ar10 = int[10];

using fptr = int(*)(int);

int foo(int);

int bar(int);

int main() {

  iptr p1, p2;

  ar10 a1, a2;

  fptr fp = foo;

  fp = bar;

  return 0;
}