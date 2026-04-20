#include <iostream>

// constexpr

int main() {
  constexpr const int x = 5; // legal, redundant

  // constexpr ile gelen const top level const

  char str[10];

  // constexpr char *const p = str; // constexpr char* p = str; ifadesi ile aynı

  constexpr const char *cptr = "modern cpp"; // pointer-to-const

  constexpr char *const ptr = "modern cpp"; // const pointer

  return 0;
}