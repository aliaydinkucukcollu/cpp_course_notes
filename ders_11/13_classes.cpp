#include <iostream>

// ---- fluent API ----

class Myclass {
public:
  Myclass& foo() {
    std::cout << "Myclass& foo function called\n";
    return *this;
  }

  Myclass& bar() {
    std::cout << "Myclass& bar function called\n";
    return *this;
  }

  Myclass& baz() {
    std::cout << "Myclass& baz function called\n";
    return *this;
  }
};

class Dummy {
public:
  Dummy* foo() {
    std::cout << "Dummy* foo function called\n";
    return this;
  }

  Dummy* bar() {
    std::cout << "Dummy* bar function called\n";
    return this;
  }

  Dummy* baz() {
    std::cout << "Dummy* baz function called\n";
    return this;
  }
};

int main() {
  Myclass m;
  m.foo().bar().baz();

  Dummy d;
  d.foo()->bar()->baz();
  return 0;
}
