#include <iostream>

// ambiguity caused by user defined types(udt)

struct A{
    operator int()const;
};

struct B{
    B(A);
};

void foo(B);
void foo(int);

int main() {

    // foo(A{});
    
    return 0;
}