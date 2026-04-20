#include <iostream>

// const member functions
// non-const member functions

// class ==> temsil ettiği varlığın bir state'i var

// type cast recap
// T*       ==> const T*    LEGAL
// const T* ==> T*          ILLEGAL

class Fighter {
public:
  void foo() const; // accessor, const member functions, sadece member functionlarda

  void attack(); // non-const function

  void bar(); // mutator, non-const member functions
private:
  void tell_me();
  int *ptr;
};

int main() {
  Fighter obj;

  return 0;
}