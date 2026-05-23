#include <iostream>

class Myclass
{
    public:
        // function overloading in class
        void foo()
        {
            std::cout << "foo() is called\n";
        }
        void foo() const
        {
            std::cout << "foo() const is called\n";
        }
};

int main() {

    Myclass m;
    m.foo();

    const Myclass cm;
    cm.foo();

    return 0;
}