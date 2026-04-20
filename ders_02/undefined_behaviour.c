#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * === Undefined Behaviour (UB) ===
 * - zero division
 * - null pointer dereference
 * - danglig pointer
 * - array bound
 * - bitsel işlemler
 */

int main() {
    
    // Example-1:  Undefined Behaviour (UB)
    char str[100] = "sevcan";
    strcpy(str+3, str); // since overlapped block it is UB
    puts(str);


    // Example-2: Zero division
    int x, y;
    // code

    x /= y;
    // code

    // compiler optimizasyon için UB olmaması şartı nedeniyle
    // y'nin 0 olamayacağını varsayıp alttaki kod bloğunu silebilir.
    if(y==0)
    {
        // statements
        // statements
        // statements
        // statements
        // statements
    }

    return 0;
}