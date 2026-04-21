#include <iostream>

class Myclass {};

// reference semantics

void foo(Myclass &) { std::cout << "void foo(Myclass&) called\n"; }

void foo(const Myclass &) { std::cout << "void foo(const Myclass&) called\n"; }

// const overloading ==> pointer semantics

void foo(Myclass *) { std::cout << "void foo(Myclass*) called\n"; }

void foo(const Myclass *) { std::cout << "void foo(const Myclass*) called\n"; }

int main() {
  Myclass m;
  const Myclass km;

  foo(m);
  foo(km);

  foo(&m);
  foo(&km);

  return 0;
}