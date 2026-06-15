#include <ctime>
#include <iostream>

// Dikkat
// -> derleyicinin default ctor'ı default etmesi ===> non-static data members
// ===> default initialize

// example-1 : legal ==> implicitly decleared defaulted
class A {};

class Myclass {
  A ax;
};

// example-2
class B {
  B(int);
};

class Foo {
  // default ctor --> implicitly decleared deleted
  // default init için B sınıfından default ctor çağrılcak
  // ama B'de def. ctor yok bunun için de derleyici Foo'nun
  // defauşt ctor'ı için delete bildirimi yapacak.
  B bx;
};

// example-3
class C {
  C(); // default ctor is private
};

class Hoo {
  C cx; // default ctor çağrılamıyor(private) bu nedenle Hoo'nun default ctor'ı
        // deleted.
};

// example-4
class D {
public:
  D() = delete;
};

class Goo {
  // default ctor deleted.
  D dx;
};

int main() {
  Myclass m; // Legal

  Foo f; // ERROR !!

  Hoo h; // ERROR !!

  Goo g; // ERROR !!

  return 0;
}
