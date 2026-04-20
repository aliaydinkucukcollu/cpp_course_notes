#include <iostream>

// ---- scoped enum ----
// - underlying type'ı belirleyebiliyoruz.Dolayısıyla forward decleration
// yapılabiliyor.
// - unscoped enumlarda da forward decleration artık mümkün.
// - artık enumeratörlerin kendi scopelrı var.
// - örtülü dönüşüm yok
// - C++20 ==> using enum

enum class Mode : int;

enum class Color : int { White, Yellow, Red, Brown, Blue, Black };

enum class TrafficLight { Red, Yellow, Green };
enum class ScreenColor { Magenta, DarkBlue, Blue, Red };

struct Foo {
  //
  Mode m;
};

// C++ dilinde isimler 2 farklı şekilde olabilir.
// - unqualified name
//      x
// - qualified name
//      - scope resolution operator
//              A::x
//      - dot operator
//              A.x
//      - arrow operator
//              A->x

// using enum

namespace foo {
namespace buz {
namespace bar {
enum class NavMode { Active, Idle, Inactive };
}
} // namespace buz
} // namespace foo

int main() {

  Color mycolor;
  mycolor = Color::White;

  // int x = mycolor; // ERROR
  // x = ScreenColor::Red;

  int x = static_cast<int>(mycolor);

  // "using enum" example
  auto n = foo::buz::bar::NavMode::Active;

  foo::buz::bar::NavMode nm = foo::buz::bar::NavMode::Inactive;

  {
    using enum foo::buz::bar::NavMode;
    nm = Idle;
  }

  auto inm = static_cast<int>(nm);

  std::cout << "nm: " << inm << '\n';

  {
    using foo::buz::bar::NavMode::Inactive;

    auto anm = Inactive;
    auto ianm = static_cast<int>(anm);

    std::cout << "ianm: " << ianm << '\n';
    
  }


  return 0;
}