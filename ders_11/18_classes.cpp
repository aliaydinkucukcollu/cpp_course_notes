#include <iostream>

// ---- constructor ----
// -> standarda göre doğrudan bir member function değil.
// -> amacı sınıf nesnesinin hayatını başlatıp kullanılabilir hale getirmek.
// -> sınıf nesnesinin hayatının bitmesi için sınıfın "destructor" dediğimiz
// fonksiyonu çağrılır.
// -> sınıf ismiyle aynı olması gerek.
// -> ctor overload edilebilir.
// -> geri dönüş değeri kavramına sahip değil.
// -> non-static fonksiyon (dolayısıyla this keyword kullanılabilir.)
// -> public, private, protected olabilir.
// -> const member function olamaz
// -> nokta ya da arrow operatörü ile çağrılabilen bir fonksiyon değil.

// RAII (Resource Acquisition Is Initialization)

class Myclass {
public:
  Myclass();
  Myclass(int);
  Myclass(int, int);
};

int main() { 
    
    Myclass m;

    // m.Myclass(); // illegal

    return 0; }