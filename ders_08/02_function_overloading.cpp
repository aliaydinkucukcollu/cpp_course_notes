#include <cstdint> // int32_t
#include <iostream>

// Function overloading soruları

// 1-) function redecleration
typedef int Word; // even if using Word = int;
void foo(int);
void foo(Word);

// 2-) function overloading
void foo(int);
void foo(int, int = 0);

// 3-) function redecleration
void foo(int);
void foo(const int);

// 4-) function overloading ==> const overloading(community term)
void foo(int *);
void foo(const int *);

// 5-) function redecleration
void foo(int *);
void foo(int *const); // top-level const

// 6-) function overloading
void foo(int *);
void foo(const int);

// 7-) function overloading
void foo(int &);
void foo(const int &);

// 8-) function redecleration
void foo(int *);
void foo(int[]);
void foo(int[10]);

// 9-) function redecleration
void foo(int **);
void foo(int *[]);

// 10-) function overloading
void foo(int *);
void foo(int **);
void foo(int ***);

// 11-) function overloading
void foo(int (*)[5]);
void foo(int (*)[10]);
void foo(int (*)[15]);
void foo(int (*)[20]);

// 12-) function redecleration
void foo(int (*)[5]);
void foo(int[][5]);

// 13-) function overloading
void foo(int (*)(int));
void foo(double (*)(int));

// 14-) function redecleration
void foo(int (*)(int));
void foo(int(int));

// 15-) function overloading
void foo(int (*)(int));
void foo(int (*)());

// 16-) function overloading
void foo(int);
void foo(int &);
void foo(int *);

// 17-) function overloading
void foo(int);
void foo(int &);
void foo(int *);
void foo(const int &);
void foo(const int *);

// 18-) function overloading
void foo(int &);
void foo(int &&);

// 19-) function overloading
void foo(int &);
void foo(const int &);
void foo(int &&);

// 20-) function overloading
void foo(char);
void foo(signed char);
void foo(unsigned char);

// 21-) derleyiciye bağlı (function overloading OR function redecleration)
void foo(int);
void foo(int32_t);

// 22-) function redecleration
void foo(int x);
void foo(int y);

// 23-) function overloading
void foo(...); // C'de geçerli değil (variadic parametreden önce başka bir
               // paramter olmalı)
void foo(int);

// ---------------------------------

void bar(int (*)[10]);

void buz(int);

int main() {
  int ar[10];

  // bar(ar); // array decay ==> int*
  bar(&ar); // int (*)[10]

  void buz(int, int);

  // buz(12);
  // yukarıdaki fonksiyon çağrısı hatalı çünkü
  // scopelar aynı değil bu nedenle fuction overloading yok!

  return 0;
}