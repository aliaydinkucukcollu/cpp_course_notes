#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class A
{

};

class B
{
    public:
        B(A);  
};

// initialization

// Initialization Is Not A n Assignment!

int main() {
    
    // initialization
    int x = 5;

    // assignment
    x = 7;

    // aşağıdakiler C++ için legal C için değil
    int a(5);
    int y{6};
    int ar[]{1,3,5,7};
    int array[10]{};

    // before Modern C++

    // copy initialization 
    int x2 = 10;

    // default initialization
    int y2;

    // direct initialization
    int z(90);

    // after Modern C++

    // comminity terms: brace initialization OR uniform initialization
    // standard terms : direct list initialization
    int x3{12};

    // value initialization OR zero initialization
    int x4{};


    // default init. and using this variable is UB
    int aa;

    // value initialization OR zero initialization
    // compiler quarantees the variable is zero
    int bb {};

    // it is a function prototype
    int zoo();

    // ERROR : definition of function inside another function
    // int bar()
    // {

    // }

    // veri kaybı var ama implicit conversion var ill-formed değil
    int xxx = 2.3;
    int yyy(9.1);

    // ill-formed : uniform initialization'da narrowing conversion bir hatadır
    // int zzz{3.14};

    // narrowing conversion : implicit conversion ile veri kaybı olduğu için verilen isim
    // örn: double -> int conversion bir narrowing conversion

    // neden uniform conversion
    // 1 - herşeyle kullanılabiliyor (uniform)
    // 2 - narrowing conversion are invalid
    
    // 3 - most vexing parse (defined by Scott Meyers)
            // * - function prototype
            //   - variable definition

    B bx(A()); // -Wvexing-parse
    
    // düşünülen :
    // türü B ismi bx olan bir değişken tanımladım
    // ve bu değişkene A() ifadesi ile ilk değer verdim

    // aslında olan :
    // ismi bx olan geri dönüş değeri türü B olan
    // paramteresi bir function pointer olan bir fonksiyon prototipi

    B by {A()}; // no warning no most vexing parse

    return 0;
}