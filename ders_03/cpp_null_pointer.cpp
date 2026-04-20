#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// NULL pointer

int main() {
    
    // int *ptr = NULL;
    int *ptr = 0; // function overloding için problemli kullanım

    // Modern C++ çözümü ==> nullptr (nullptr_t türünden bir sabit)
    // tüm pointer türlerine implicit conversion oluyor.

    int *iptr = nullptr;
    iptr = nullptr;

    // Neden nullptr?

    // nullptr'den önce
    int *zptr = 0; // 0 değeri aritmetik işlemlerine de atama yapılabilir, compiler keeps silent !

    // Modern C++'da 0 değil nullptr kullanmalıyız.

    // nullptr pointer olmayan türden değişkenlere atanamaz. Sadece pointer türlerine atama yapılır.
    int x;
    // x = nullptr; // ill-formed

    int *aptr = nullptr;
    if(aptr != nullptr) // same with if (aptr)
    {
        // code
    }

    return 0;
}