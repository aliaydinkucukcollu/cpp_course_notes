#include <stdio.h>

#include "static.h"

// static keyword usage in C

void increase()
{
    // 1: static local variables
    static int counter = 0;
    counter++;
    printf("counter: %d\n", counter);
}

int main()
{
    increase();
    increase();
    increase();
    increase();

    // 2: static global variables
    printf("secret_number: %d\n", secret_number);

    printf("dummy_number: %d\n", dummy_number);

    return 0;
}