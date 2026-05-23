#include <iostream>

class Myclass
{
    public:
        void foo();
        void bar() const;
};

int main() {

    const Myclass cm;

    // cm.foo(); // illegal, const T* ==> T* (no implicit conversion)
    cm.bar();    // legal

    return 0;
}