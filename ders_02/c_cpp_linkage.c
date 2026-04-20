#include <stdio.h>
#include <stdlib.h>

// linkage

// external linkage
int x = 10;
int foo();

// internal linkage
static int a = 4;
static int fuz();

// const : external linkage
const int var = 10;

int main() {
    printf("Hello World!\n");
    return 0;
}