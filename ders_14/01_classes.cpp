
// special member functions
// -> default constructor
// -> copy constructor
// -> move constructor
// -> copy assignment
// -> move assignment
// -> destructor

class Nec {
public:
  Nec(Nec &); // copy constructor
};

class A {};
class B {};

class Myclass {
public:
  Myclass() : ax(), bx() {} // default initialize ==> indetermined value

  // copy constructor -> non-static, public, inline
  Myclass(const Myclass &other)
      : ax(other.ax), bx(other.bx) {
  } // A bir sınıf türü ise ax için de copy ctor çağrılır

private:
  A ax;
  B bx;
};

int main() { return 0; }
