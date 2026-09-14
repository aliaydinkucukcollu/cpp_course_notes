/**

build with: clang main.c dummy.c -o program

*/

#include <stdio.h>

extern int number;
void foo(void);

static double magic_number = 5.123;

void print_magic_num(void) { printf("magic_num(main.c): %.3f\n", magic_number); }

int main() {
  printf("extern number: %d\n", number);

  foo();

  print_magic_num();

  return 0;
}