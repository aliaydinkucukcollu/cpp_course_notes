#include <iostream>
#include <string>

// sentaks ile semantiğin ayrıştığı bir yer

class Fighter {
public:
  void attack() {
    ++debug_call_count;
    // ..
  }

  std::string name() const { ++debug_call_count; }

private:
  mutable int debug_call_count;
};

int main() { return 0; }