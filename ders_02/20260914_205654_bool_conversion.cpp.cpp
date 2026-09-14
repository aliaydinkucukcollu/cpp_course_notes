#include <ios>
#include <iostream>

int main() {

  bool b = false;

  std::cout << std::boolalpha << "b: " << b << '\n';

  int res = true + true; // integral promotion

  std::cout << "res: " << res << '\n';

  int x = 10;
  int *ptr = &x;

  // pointer to bool [OK]
  b = ptr; // true

  std::cout << std::boolalpha << "b: " << b << '\n';


  b = false;

  // bool to pointer [ERROR]
  // ptr = b;
  
  return 0;
}
