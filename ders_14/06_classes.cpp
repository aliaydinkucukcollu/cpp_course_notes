// ---- move semantics ----
//
// String str = expr; ==> copy ctor called
//
// str = expr; ==> copy assignment operator called
//
// copy --> kaynağı kopyalıyor
// move --> kaynağı çalıyor
//
// -> bundan dolayı R value eklendi
//
// -> function overload resolution güncellendi
//    void foo(const T&); ==> L value
//    void foo(T&&);      ==> R value

#include <iostream>
#include <utility>

// 6 special member functions
class Myclass {
public:
  // 1. default constructor
  Myclass() {
    // std::cout << "default constructor\n";
  }
  // 2. copy constructor ===> constructor'a gönderilen argüman L value ise
  // -> compiler-generated version does shallow copy
  Myclass(const Myclass &) { std::cout << "copy constructor\n"; }

  // 3. move constructor ===> constructor'a gönderilen argüman R value ise
  // -> after C++11
  Myclass(Myclass &&) { std::cout << "move constructor\n"; }

  // 4. copy assignment ===> atama operatorünün sağındaki ifade L value ise
  // -> must handle self-assignment and return *this
  Myclass &operator=(const Myclass &) {
    std::cout << "copy assignment\n";
    return *this;
  }

  // 5. move assignment ===> atama operatörünün sağındaki ifade R value ise
  // -> after C++11
  Myclass &operator=(Myclass &&) {
    std::cout << "move assignment\n";
    return *this;
  }

  // 6. destructor
  ~Myclass() {
    // std::cout << "destructor\n";
  }
};

// bir nedenden dolayı move ctor ve move assignment(move members) olmasa
// sadece copy ctor ve copy assignment(copy members) hem L valueları hem de R
// valuları alıp handle edebilirdi.
//
// move members'ların fayda sağlaması için kaynak  çalma teması olması lazım.
// aksi halde copy members yeterli oluyor.

int main() {
  Myclass m;

  Myclass m2;

  m2 = m; // copy assignment

  Myclass m3 = m2; // copy ctor

  Myclass m4 = std::move(m); // move constructor

  Myclass m5;

  m5 = std::move(m3); // move assignment

  return 0;
}
