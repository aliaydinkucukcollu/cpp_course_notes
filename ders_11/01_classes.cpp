#include <iostream>

// member functions
// -> const member funciton
// -> non-const member function

// accessor and mutator in C
class Fighter;

void foo(const Fighter *); // accessor
void bar(Fighter *);       // mutator and  out param OR in-out param

// sınıfların üye fonkisyonlarının accessor
// ya da mutator olması

class Nec {
public:
  // Nec nesnelerini değiştirmez
  void foo() const; // accessor, const member function
  // Nec nesnelerini değiştirmeye yönelik
  void bar();       // mutator, non-const member function
};

int main() { return 0; }