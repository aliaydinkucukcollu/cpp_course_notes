#include <iostream>

int g = 20;

int foo(void)
{
    ++g;
    return 4;
}

int bar(void)
{
    return g+3;
}


int main()
{

    int x = 10;

    // foo önce çağrılırsa -> 28
    // bar önce çağrılırsa -> 27
    x = foo() + bar();

    std::cout << "x: " << x << '\n'; // 28

    return 0;
}
