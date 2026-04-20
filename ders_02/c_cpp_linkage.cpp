#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// linkage with const

// with const : internal const 
const int x = 10;
const int foo();

// hem const hem external için
extern const int var = 45;

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}