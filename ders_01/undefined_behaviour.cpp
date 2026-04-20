#include <iostream>
#include <climits> // INT_MAX

int main(int argc, char** argv) {

    // UB: Undefined behaviour

    // 1: Out-of-Bounds Array Access
    int numbers[3] =  {2, 4, 6};
    
    std::cout <<  numbers[4] << std::endl;

    // 2: Signed integer overflow
    std::cout << INT_MAX << std::endl;

    int num = INT_MAX;

    std::cout << ++num << std::endl;

    // 3: Using uninitialized variables

    float fvar;
    std::cout << fvar << std::endl;

    // 4: Dereferencing a Null Pointer
    
    int *ptr = nullptr;

    std::cout << *ptr << std::endl;

    return 0;
}