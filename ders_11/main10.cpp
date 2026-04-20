#include <iostream>

// nec.hpp
class Nec {
public:
  void foo();
  static void sbom();

private:
  void bar();
};

// nec.cpp
#define PUBLIC
#define PRIVATE
#define PROTECTED
#define STATIC

PUBLIC void Nec::foo()
{

}

PUBLIC STATIC void Nec::sbom()
{

}

PRIVATE void Nec::bar()
{

}

int main() { return 0; }