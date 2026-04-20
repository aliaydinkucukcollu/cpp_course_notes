#include <iostream>

//              pointers                                    lvalue references
//------------------------------------------------------------------------------------------
// 1      default init. edilebilir                         default init. edilemez
//
// 2   göst. nesneyi ve ptr değ. değişebilir                  rebindible değil
//
// 3     pointer to pointer var                          reference to reference yok
//
// 4        NULL pointer var                                NULL reference yok

struct Data {};

/**
 * eğer işini yapamazsa
 * @returns nullptr 
 */
Data* do_something();

// işini yapamazsa null reference gibi bir şey döndüremez.
// Data& do_something();

struct Point
{
    double x, y;
};

int main() {

    // default initialization
    int* ptr; // OK
    
    // int& ref; // Not OK

    // rebindible
    int x = 10;
    int y = 30;
    int* iptr = &x;

    iptr = &y; // OK

    int& ref = x;

    // &ref = y; // Not OK

    // pointer to pointer
    int** dptr = &iptr; // OK

    // int&& dref = &ref; // Not OK
    

    return 0;
}