#include <iostream>

void print_array(const int *ar, size_t size) {
  for (size_t i = 0; i < 6; ++i) {
    std::cout << *(ar + i) << ' ';
  }
  std::cout << '\n';
}

int main() {
  int ar[6] = {2, 1, 3, 2, 1, 0};

  auto x = ar;

  for (int i = 0; i < 6; ++i) {
    std::cout << *(x + i) << ' ';
  }
  std::cout << '\n';

  print_array(x, 6);

  auto &y = ar;

  for (int i = 0; i < 6; ++i) {
    std::cout << y[i] << ' ';
  }
  std::cout << '\n';

  print_array(y, 6);

  return 0;
}
