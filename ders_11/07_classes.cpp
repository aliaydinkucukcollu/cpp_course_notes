#include <iostream>

class Myclass {};

// function overloading (const overloading)
void foo(Myclass *) {
    std::cout << "Myclass* is called\n";
}
void foo(const Myclass *)
{
    std::cout << "const Myclass* is called\n";
}

// referans semantiği için de aynısı geçerli
void bar(Myclass &)
{
    std::cout << "Myclass& is called\n"; 
}
void bar(const Myclass &)
{
    std::cout << "const Myclass& is called\n";
}

int main() {

  Myclass m;
  foo(&m);
  bar(m);

  const Myclass cm;
  foo(&cm);
  bar(cm);

  return 0;
}