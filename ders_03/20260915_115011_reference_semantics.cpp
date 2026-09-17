#include <iostream>

int main() {
  int ar[5] = {1, 6, 2, 9, 5};

  // array pointer => dizinin kendisini göster pointer
  int(*ptr)[5] = &ar;

  // array decay => dizinin ilk elemanını gösteren pointer
  int *p = ar;
  std::cout << "*p: " << *p << '\n'; // ar'nin ilk elemanı -> array decay

  for (int i = 0; i < 5; ++i) {
    std::cout << (*ptr)[i] << ' ';
  }
  std::cout << '\n';

  int(&r)[5] = ar; // r demek ar demek

  for (int i = 0; i < 5; ++i) {
    std::cout << r[i] << ' ';
  }
  std::cout << '\n';

  int *pref = r; // int *pref = &r[0];

  for (int i = 0; i < 5; ++i) {
    std::cout << *(pref+i) << ' ';
  }
  std::cout << '\n';

  return 0;
}
