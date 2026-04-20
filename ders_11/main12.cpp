#include <iostream>

// constructor : sınıf nesnesini kullanabilir bir duruma getirmek
// destructor  : sınıf nesnesinin hayatını bitiriyor

// special member functions

// ===== constructor =====
// - görevi sınıf nesnesini kullanılabilir duruma getirmek
// - sınıf ismi ile aynı olması lazım
// - overload edilebilirler
// - geri dönüş değeri kavramı yok (void'den farklı)
// - non-static fonksiyon (static olamaz)
//      - yani this pointerı kullanılabilir
// - public, protected, private olabilir
// - const member function olamaz
// nokta ya da ok operatörü ile çağrılabilen bir fonksiyon değil.

// RAII (Resource Acquisition Is Initialization)
// Acquisition      ==>     Usage   ==>     Release
// (constructor)    ==>     -----   ==>     (destructor)

class Myclass {
public:
  Myclass();         // constructor (ctor)
  Myclass(int);      // constructor (ctor)
  Myclass(int, int); // constructor (ctor)

  ~Myclass(); // destructor (dtor)

private:
  int mx, my;
};

Myclass::Myclass()
{

}

int main() {
  Myclass m;
  
  

  return 0;
}