#include <iostream>
#include <string>

void foo(const std::string &other) { std::cout << "const string& \n"; }
void foo(std::string &&other) { std::cout << "string && \n"; }

int main() {

  std::string str;

  foo(str); // L value call

  // str'yi kullanayım ama alttaki overload çağrılsın istiyorum.
  // 1. L value to R value expression
  foo(static_cast<std::string &&>(str));

  // her defasında bu ifadeyi yazmayalım
  // bu dönüşümü yapan compile time'da çağrılan
  // bir fonksiyon yazalım demişler.
  // fonksiyon basitçe ifadeyi L value ise R value yapıyor.
  // R value ise R value olarak kalıyor.
  //
  // -> compile time function
  // -> misnomer (move doesn't move)

  foo(std::move(str));

  foo(std::string{}); // R value call

  return 0;
}
