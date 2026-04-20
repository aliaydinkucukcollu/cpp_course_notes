#include <iostream>

void foo(const char * = "necati"); // legal

// void foo(const char *= "necati"); // illegal
// neden illegal?

// community term
// maximal munch (en büyük lokma) kuralı nedeniyle

int main() {
  // peki maximal munch nedir?
  int x = 20;
  int y = 40;

  // int z = x+++y; ifadesi aşağıdaki satır ile aynıdır.
  int z = x++ + y;

  // derleyici en uzun tokenı elde edilecek şekilde ayırım yapıyor.

  // diğer kod örneği

  int n = 10;

  // according to maximal munch:
  while (n --> 0) // while (n-- > 0)
  {
    // code
  }

  return 0;
}