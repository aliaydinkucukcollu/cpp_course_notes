#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    
    // implementation defined (depends on compiler)
    char c = 'D'; // signed or unsigned

    std::cout << sizeof(c) << std::endl;

    // implementation defined (depends on compiler)
    int x = 2;

    auto y = x >> 3; // bitsel sağa kaydırma işlemi C99 için

    std::cout << y << std::endl;

    return 0;
}