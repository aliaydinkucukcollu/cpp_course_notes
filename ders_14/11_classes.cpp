// moved-from state
// -> hayatı devam eden değişkenlerin kaynağı çalınmış durumda
//
// örnek:

#include <ios>
#include <iostream>
#include <string>

void func(std::string str) {
  // str ne belli değil ancak geçerli bir durumda
}

int main() {
  std::string str(1000, 'A');

  std::cout << str << '\n';

  std::string s = std::move(str);

  // str'nin hayatı burada da devam ediyor.
  // ancak str'nin kaynağı çalınmış durumda.
  //
  // the object is in a valid state and destructible
  //
  // yani nesne geçerli bir durumda ve destruct edilebilir
  // ancak değeri ne garanti değil.

  // -> aşağıda str'yi kullanmak UB değil.

  std::cout << "[" << str << "]" << '\n';
  std::cout << "lenght: " << str.length() << '\n';
  std::cout << std::boolalpha << str.empty() << '\n';
  str += '!';
  std::cout << "[" << str << "]" << '\n';

  // yeni değer atama garantisi var
  str = "ali aydin kucukcollu";
  std::cout << "[" << str << "]" << '\n';

  return 0;
} // bu noktada str için destructor çağrılcak ancak bu bir UB'ye neden olmucak.
