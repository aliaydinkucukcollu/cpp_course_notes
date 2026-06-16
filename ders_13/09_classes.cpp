// copy constructor

// C code
struct Nec {
  int a, b, c;
};

int main() {

  int x = 10;
  int y = x;

  int y = 98; // x değişmez ==> value semantics

  struct Nec m = {3, 6, 9};
  struct Nec n = n;

  n.a = 5; // n.a=5, n.b=6, n.c=9

  // C++'da ==> y nesnesi için copy constructor çağrılır.

  return 0;
}
