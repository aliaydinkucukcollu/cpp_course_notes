#include <stdio.h>
#include <stdlib.h>

// structure tag
struct Nec
{
    int a, b, c;
};

// with typedef

// option-1
// typedef struct Nec Nec;

// option-2
// typedef struct data
// {
//     int id;
// }Data;

union Data
{
    int x, y;
    double d;
};

enum Color {White, Yellow, Red, Brown, Blue, Black};

enum Pos {On, Off, Hold};

// legal in C++ but illegal in C
struct Dummy
{

};

int main() {

    // Nec mynec; // error
    struct Nec mynec;

    // option-1 usage
    // Nec nec2;

    // option-2 usage
    // Data d;

    union Data mydata;

    enum Color mycolor;

    // arithmetik türlerden enum türüne dönüşüm var
    // enum türünden diğer enum türlerine de dönüşüm var

    // legal - implicit conversion
    enum Color c;
    c = 5;

    // enum to enum conversion - legal
    c = Off;



    return 0;
}