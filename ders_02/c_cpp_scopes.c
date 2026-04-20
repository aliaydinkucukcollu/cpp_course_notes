#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // scope

    for(int i = 0; i < 10; ++i )
    {
        int i = 15; // LEGAL and calls name hiding / masking / shadowing

        printf("%d\n", i);
    }

    return 0;
}