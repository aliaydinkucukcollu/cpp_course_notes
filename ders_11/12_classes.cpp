#include <iostream>

// ne zaman this kullanmam lazım?

// ---- myclass.h ----
class Myclass
{
    public:
        void func();  
};

// ---- myclass.cpp ----
void gf1(Myclass* p);
void gf2(Myclass& r);

void Myclass::func()
{
    gf1(this);
    gf2(*this);
}

int main() {

    return 0;
}