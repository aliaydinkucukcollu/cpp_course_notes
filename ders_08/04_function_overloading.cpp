// ---- viable function degrees ----

// 1-) variadic functions (worst case)
void foo(...);
void foo(double);

class Myclass {
public:
  operator int() const;
};
// 2-) user defined conversion (udc)
void foo(...);
void foo(int);

class Dummy {
public:
  Dummy(int = 0);
};
// 3-) standard conversion
void foo(...);
void foo(Dummy);
void foo(double);

// 4-) birden fazla standard converison olması durumu
void foo(double);
void foo(float);
void foo(long);

// 4.1-) exact match
// T*  ==> const T*
void foo(const int *);

// ar  ==> &ar[0]   (array decay)
void foo(int *);

// foo ==> &foo
void foo(int (*)(int));
int bar(int);

// 4.2-) promotion
// integral promotion: int'ten küçük rankteki argümanlardan int'e
// sadece float --> double promotion oluyor

// ---- ranks ----
// long double
// double
// float
// long long 
// long
// int
// ===
// short
// char
// bool

void foo(int);    // integral promotion for foo('a') call
void foo(double); // conversion for foo('a') call

// promotion
void foo(double);      // promotion
void foo(long double); // conversion

// 4.3-) conversion
void foo(long double);
void foo(char);

// example-2
void foo(unsigned int);
void foo(char);

int main() {
  foo(12); // void foo(double); called

  Myclass m;
  foo(m); // void foo(int); called

  Dummy d;
  foo(d); // void foo(double); called

  // birden fazla standard conversion olması durumu
  // exact match
  // T* ==> const T*
  int x = 12;
  foo(&x);

  // ar ==> &ar[0]
  int ar[10];
  foo(ar); // foo(&ar[10]); // array decay

  // foo ==> &foo
  foo(&bar);

  // integral promotion
  foo('a');

  // promotion
  foo(1.2f);

  // converison
  foo(1.2); // ambiguity

  foo(1); // ambiguity

  return 0;
}