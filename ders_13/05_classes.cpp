// C dilinde bir ifade için 2 seçenek vardır.
// -> L value
// -> R value

//         expression
//         /        \
//     glvalue      rvalue
//     /     \     /     \
//  lvalue   xvalue   prvalue

// value category in C++
//
// primary value categories
// -> L  value
// -> PR value
// -> X  value
//
// combined value category
// -> GL value
// -> R  value ==> PRvalue OR X value
//
// Dikkat bir değişkenin value categorisi olmaz.
// value category bir ifadeyi niteler.

class Myclass {};

Myclass foo();

int main() {
  int x = 5;

  // x'in value categorisi olmaz çünkü bir değişken

  // x ifadesinin value categorysi -> L value

  int &r = x;

  // r ifadesinin value categorisi -> L value

  int &&rr = x + 5;

  // rr ifadesinin value categorisi -> L value
  // rr ifadesinin decleration type -> int&&

  Myclass m1;

  Myclass m2 = m1; // L value -> copy ctor çağrılır.

  Myclass m3 = foo(); // R value -> move ctor çağrılır.

  return 0;
}
