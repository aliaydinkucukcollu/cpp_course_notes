#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// structure tag

struct Nec
{
    int a, b, c;
};

union Data
{
    int x, y;
    double d;
};

// unscoped enum
enum Color {White, Yellow, Red, Brown, Blue, Black};
enum Pos {On, Off, Hold};

// Modern C++ - enum update to fix enum conversion and 2 other problems
// scoped enums
enum class Letters{A, B, C};


// legal in C++ but illegal in C
struct Dummy
{

};

int main() {

    Nec mynec;

    Data mydata;

    Color mycolor;

    // enum türlerine diğer türlerden dönüşüm yok
    // enum to enum conversion yok

    Color c;
    c = 5; // error
    c = Off; // error


    // ancak enum to arithmetic conversion is valid
    Color c2 = Red;

    int x = c2;

    
    return 0;
}