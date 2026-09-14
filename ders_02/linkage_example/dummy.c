#include <stdio.h>

// external linkage
int number = 34;

// internal linkage
static double magic_number = 56.78;

// external linkage
void foo(void) {  printf("number(dummy.c): %d\n", number); }

// internal linkage
static void print_magic_num(void) { printf("magic_num(dummy.c): %f\n", magic_number); }