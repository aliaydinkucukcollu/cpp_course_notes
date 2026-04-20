#include <iostream>

// ---- enumeration types ----
// 1-) unscoped enum ==> C and C++
// 2-) scoped enum ==> C++

enum Color { White, Yellow, Red, Brown, Blue, Black };

enum Status { Ready, NotReady, Waiting, Busy };

// derleyicilerin enum türleri için arka planda kullandıkları tamsayı türüne
// "underlying type" denir. (derleyiciye bağlı)

int main() {

  Color c = White; // c'nin türü C'de, int C++'da enum

  std::underlying_type_t<Color> ut_color{}; // underlying type : unsigned int

  // tür dönüşümleri
  Color mycolor;

  // tamsayı türlerinden enum türüne örtülü dönüşüm yok
  // mycolor = 5; // ill-formed

  // farklı enum türleri arasında da örtülü dönüşüm yok
  // mycolor = Ready;

  // type-cast operator
  mycolor = static_cast<Color>(4);     // int to enum conversion
  mycolor = static_cast<Color>(Ready); // enum to enum conversion

  // ---- enum türlerine ilişkin 3 önemli problem ----

  // 1-) Boyutu derleyiciye göre değiştiği için forward decleration olarak
  // kullanılamıyor.

  // -- berk.h --
  // enum Color { White, Yellow, Red, Brown, Blue, Black };

  // -- necati.cpp --
  // #include "berk.h"

  //   enum Color; // sadece bunu kullansak olmaz, tanım lazım.
  //                  çünkü boyutu derleyiciye bağlı.

  //   struct Neco {
  //     //
  //     //
  //     //
  //     Color nc;
  //   };

  // 2-) Aynı scopeda aynı isim birden fazla varlığa karşılık olmaz.
  // Ancak; dilin kuralları gereği TrafficLight ve ScreenColor enum türlerinin
  // scopeları aynı bu durumda error oluşuyor.

  // -- necati.cpp --
  // #include "traffic.h"
  // #include "screen.h"

  // traffic.h ==> enum TrafficLight{Red, Yellow, Green};
  // screen.h  ==> enum ScreenColor{Magenta, DarkBlue, Blue, Red};

  // ÇÖZÜM-1 : prefix

  // traffic.h ==> enum TrafficLight{TrafficLightRed,
  // TrafficLightYellow,TrafficLightGreen}; screen.h  ==> enum
  // ScreenColor{ScreenColorMagenta,ScreenColorDarkBlue, ScreenColorBlue,
  // ScreenColorRed};

  // ÇÖZÜM-2 : namespace

  // -- traffic.h --

  //   namespace traffic_light {
  //   enum TrafficLight { TrafficLightRed, TrafficLightYellow,
  //   TrafficLightGreen };
  //   }

  // -- screen.h --

  //   namespace screen {
  //   enum ScreenColor { Magenta, DarkBlue, Blue, Red };
  //   }

  // ÇÖZÜM-3: yapı nesnesinin elemanı

  //   struct traffic {
  //     enum TrafficLight { Red, Yellow, Green };
  //   };

  //   struct screen {
  //     enum ScreenColor { Magenta, DarkBlue, Blue, Red };
  //   };

  // 3-) enum türlerinde tamsayı türlerine dönüşüm legal.
  Color color  = Red;
  int x = 4;
  x = color;

  return 0;
}