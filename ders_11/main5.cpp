#include <iostream>
#include <vector>
#include <cstring>

class Date {
public:
  void print();

private:
};

class Myclass {
public:
  // function overloading
  void foo();       // non-const objeler için çağrılır
  void foo() const; // const nesneler için çağrılır
};

// function overloading ==> const overloading
void foo(Myclass *);
void foo(const Myclass *);

void bar(Myclass &);
void bar(const Myclass &);

int main() {

  Myclass m;
  foo(&m); // 2 vailable ==> void foo(Myclass*); called

  const Myclass m2;
  bar(m2);

  const Myclass m3;
  m3.foo(); // void foo(); called

  std::vector<int> vec{2, 5, 7, 9};
  vec.front();

  const std::vector<int> vec2{1, 2, 3};
  vec2.front();

  // std::strcpy() ==> restrict pointer

  return 0;
}