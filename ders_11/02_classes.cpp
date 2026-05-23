#include <iostream>

// const correctness
// -> fonksiyon const olabilir non-static data memberları değiştirebilir.
// -> fonskyion non-const olabilir ve non-static data memberları
// değiştirmeyebilir.

class Fighter {
public:
  void attack();

private:
  void tell_name();
};

// T* ==> const T*
// -> tür dönüşüm operatatörüne gerek olmadan legal

// const T* ==> T*
// -> böyle bir örtülü dönüşüm yok 
// -> tür dönüşüm operatörü kodu legal yapar ama doğru yapmaz.
// -> kod yine UB olur

void foo(const int* p); // accessor

void bar(int* p); // mutator

int main() { 
    
    int x = 10;
    foo(&x);

    bar(&x);

    const int cx = 44;
    foo(&cx);

    // bar(&cx); // ERROR

    return 0; }