#include "stdio.h"

// implicit int (C99)

// C++ does not support default int
foo()
{
    return 1;
}

// 2: C++ has no old style function definition
int bar(a, b, c)
int a, b; double c;
{

}

// 3: function decleration with no param
void hoo(); // most common in C++ 

// function prototype
void voo(void); // same but not preferred



int main() {  

    // both of them error
    hoo(3,4);
    voo(3,4);

    // 4: C++ has no default function decleration OR implicit function decleration
    // name lookup yapıldı ve bulunamadı
    zoo(1, 3, 5); // error

  return 0;
}