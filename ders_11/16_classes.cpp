#include <iostream>

// ---- nec.hpp ----
class Nec {
public:
  void foo();

private:
  void bar();
};

// ---- nec.cpp ----
// fonksiyonlar public mi private mı belli olmuyor
// static olup olmadığı da belli olmuyor
void Nec::foo()
{

}

void Nec::bar()
{

}

// C'de kullanılan araç
#define ZORT
ZORT int dummy() ZORT
{
    ZORT
}

#define PUBLIC
#define PRIVATE
#define PROTECTED
#define STATIC

// ---- neco.hpp ----
class Neco {
public:
  void foo();

  void sbom();

private:
  void bar();
};

// ---- neco.cpp ----
PUBLIC void Neco::foo()
{

}

PUBLIC STATIC void Neco::sbom()
{

}

PRIVATE void Neco::bar()
{
    
}

int main() { return 0; }