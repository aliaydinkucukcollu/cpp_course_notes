// derleyicinin yazdığı special member functions

#include <utility>

class A {};
class B {};

class Myclass {
public:
  // default constructor
  Myclass() : ax(), bx() {} // default initialize ==> indetermined value

  // copy constructor -> non-static, public, inline
  Myclass(const Myclass &other)
      : ax(other.ax), bx(other.bx) {
  } // A bir sınıf türü ise ax için de copy ctor çağrılır

  // move constructor
  Myclass(Myclass &&other) : ax(std::move(other.ax)), bx(std::move(other.bx)) {}

  // copy assignment
  Myclass &operator=(const Myclass &other) {
    ax = other.ax;
    bx = other.bx;
    return *this;
  }

  // move assignment
  Myclass &operator=(Myclass &&other) {
    ax = std::move(other.ax);
    bx = std::move(other.bx);
    return *this;
  }

  // destructor
  ~Myclass() {}

private:
  A ax;
  B bx;
};

int main() { return 0; }
