/**

build with: clang++ main.cpp dummy.cpp -o program

*/

#include <iostream>

extern const double dVal;

int main()
{

    std::cout << "dVal: " << dVal << '\n';

    return 0;
}