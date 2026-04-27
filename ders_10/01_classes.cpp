#include <iostream>

// member functionların kullanımı

class Nec {
public:
  void foo();
};

void bar(Nec *necptr);

void bom(Nec &necptr);

int main() {

  Nec mynec;
  Nec *ptr = &mynec;

  mynec.foo();

  (*ptr).foo();

  ptr->foo();

  bar(&mynec);

  return 0;
}