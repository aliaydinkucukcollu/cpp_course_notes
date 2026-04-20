#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// types (türler)

int main()
{
    // 1: 'A' is character constant in C and the type is int
    printf("%lu\n", sizeof('a')); // type: int, size: 4

    // 2: string literal
    "murat"; // char [6]

    char *p = "murat"; // char*, legal

    // 3: implicit conversion
    // void* ---> int* geçerli

    int* ptr = malloc(1024); // legal

    int* ptr2 = (int*)malloc(1024); // both legal and recommended (with typecast operator)

    // 4: C99'da eklenen bool türü
    _Bool b;

    // C99'da eklenen bi macro -> stdbool.h
    bool flag = true;
    flag = false;

    return 0;
}