#include <iostream>

// 3 KATEGORİ MEVCUT
// 2. KULLANIM   ===>    auto& x   = expr;

int foo(int);

int main()
{
    int x = 10;
    auto& y = x; // x: int, y: int&

    // FARKLILIKLAR

    // 1-) Dizi isimleri: ARRAY DECAY yok!
    int ar[4] = {0};
    auto& v = ar; // ar: int[4], v: int &[4]

    // const array
    const int kar[4] = {0};
    auto& karr = kar; // const int &[4]

    auto t = "enis"; // const char *
    auto &s = "enis"; // const char[5] ===> const char &[5]

    // 2-) Function isimleri
    
    // NOTE: C  ===> function pointer
    //      C++ ===> function pointer and function reference
    int (*fp)(int) = &foo; // function pointer
    int (&fr)(int) = foo;  // function reference

    auto e = foo; // int (*)(int)

    auto &f = foo; // int (&)(int)

    // OKAY
    int z = 10;
    int *zptr = &z;

    // 3-) const düşmez.
    const int a = 5;
    auto& b = a; // const int

    // Initialization with auto
    auto myvar(15); // int

    auto newvar {56}; // int

    auto n = {12}; // std::initializer_list<int>

    auto p = {3, 4, 5}; // std::initializer_list<int>

    // auto k{4, 5}; // ill-formed

    return 0;
}