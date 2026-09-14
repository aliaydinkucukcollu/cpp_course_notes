#include <iostream>

// BAD
void print_array(int *ptr, size_t size) {
  while (size--) {
    std::cout << *ptr++ << ' ';
  }
  std::cout << '\n';
}

// GOOD
void GoodPrintArray(const int *ptr, size_t size) {
  while (size--) {
    std::cout << *ptr++ << ' ';
  }
  std::cout << '\n';
}

int main() {
  int ar[5] = {2, 4, 6, 8, 0};
  print_array(ar, 5);    // OK
  GoodPrintArray(ar, 5); // OK

  // const int* -> int*
  const kArr[3] = {1, 7, 9};
  print_array(kArr, 3);    // ERROR
  GoodPrintArray(kArr, 3); // OK

  return 0;
}
