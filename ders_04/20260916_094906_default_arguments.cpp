#include <iostream>

int g = 5;

void foo(int x = ++g)
{

}

int main()
{
    foo(); // foo(++g);
    foo(); // foo(++g);
    foo(); // foo(++g);
    foo(); // foo(++g);
    foo(); // foo(++g);

    std::cout << "g: " << g << '\n'; // 10

    return 0;
}
