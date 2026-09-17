#include <iostream>

int main() {
  int x = 2;

  int *iPtr = &x;

  if (iPtr == nullptr) {
    std::cout << "iPtr is nullptr.\n";
  } else {
    std::cout << "iPtr is not nullptr.\n";
  }

  iPtr = nullptr;

  if (!iPtr) {
    std::cout << "iPtr is nullptr.\n";
  } else {
    std::cout << "iPtr is not nullptr.\n";
  }

  return 0;
}
