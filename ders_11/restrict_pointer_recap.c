#include <stdio.h>

// ---- pointer aliasing ----
// -> two or more pointers refer to the same memory location
void foo() {
  int x = 10;

  int *p1 = &x;
  int *p2 = &x; // alias of p1

  *p1 = 20;

  printf("*p2: %d\n", *p2); // p2*: 20
}

// ---- restrict pointer ----
// derleyici optimizasyon yaparak
// kodun yanlış çalışmasına neden olabilir.
// yani compiler x ve y'nin farklı nesneleri gösteridiğini bilmiyor, aynı
// nesneyi gösterdiği varsayabilir.
void dummy(int *x, int *y) {
  // code ...
}

// fonksiyonun kodunun yürütülmesi esnasında
// x'in gösterdiği nesneyi gösteren başka bir pointer yok
// yani compiler x ve y'nin farklı nesneleri gösteridiğini biliyor
void dummy2(int *restrict x, int *restrict y) {
  // code ...
}

int main() {

  foo();

  return 0;
}