#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

// types (türler)

// 1: 'A' is character literal in C++ and the type is char

int main() {
    
    std::cout << sizeof('a') << std::endl; // type: char, size: 1

    // 2: string literal
    "murat"; // const char [6]

    char *p = "murat"; // error
    const char *p1 = "murat"; // legal

    // Undefine Behaviour (UB): string literal read only
    const char *ptr = "murat";
    char* pp = (char*)ptr;
    *pp = 's';

    // 3: implicit conversion
    // void* ---> int* geçerli değil

    int* ptr = malloc(1024); // illegal

    // 4: bool
    bool flag = true;
    flag = false;

    // implicit conversions

    // bool to arithmetic
    int x = flag;

    int a = 44;
    int y = 0;

    // arithmetic to bool
    bool b = y;

    // pointer to bool conversion
    int num = 10;
    int* nptr = &num;
    int* nnptr = nullptr;

    bool fflag;

    flag = p1; // true

    flag = nnptr; // false

    return 0;
}