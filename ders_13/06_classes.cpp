#include <iostream>

// function overloading
void foo(const int &); // for L value
void foo(int &&);      // for R value

int main() {

  int x = 5;

  foo(x); // void foo(const int &);

  foo(5); // void foo(int &&);

  return 0;
}
