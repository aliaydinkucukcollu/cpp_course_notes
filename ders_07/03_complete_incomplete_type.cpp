#include <cstdlib>
#include <iostream>

// ---- incomplete type vs complete type ----

// derleyici bir türün varlığından (o türün ismini görerek)
// haberdar ise ancak o trün tanımını (yani o türle ilgili gereken bütün
// bilgileri henüz öğrenmemiş ise) o tür incomplete type'dır.

// derleyici o türlü ilgili gerekeen tüm bigileri edinmiş ise ==> complete type

// forward decleration in C++
// incomplete type in C
struct Foo;

// complete type
struct Data {
  int x, y, z;
};

Foo *buz();
Foo bar(Foo &);
Foo &boz(Foo);

// ---- incomplete type ile ne yapabiliriz? ----
// 1-) tür eş isim bildirimleri / type alias decleration
typedef struct Dummy NecData;

// 4-) extern değişken bildirimlerinde incomplete type türünden bir değişken
// için extern bildirimi yapılabilir.
int g;        // derleyici storage allocate ediyor
extern int x; // derleyici storage allocate etmiyor

struct Zoo;
extern Zoo gzoo;

void zuu(int);

int goo(int);

int main() {

  // 2-) pointer değişken tanımlanabilir
  Foo *p = nullptr;
  p = buz();

  // 3-) fonksiyon protoiplerinde incomplete type kullanılabilir.

  // ---- bir tür incomplete ise o türle ilgili hangi kodlar error olur? ----
  // 1-) incomplete type türünden değişken tanımlayamam

  // Zoo z; // error

  // 2-) pointer değişkeni dereference edemem, ya da bunu gerektirecek bir ifade
  // yazamam!

  // aşağıdakiler error:]
  // *p
  // p[]
  // p->

  // 3-) sizof operatorünün operandı yapamam

  // sizeof(Foo);]

  // NOT: void is an "incomplete type"
  // Dikkat! Bir ifadenin türü void türü olabilir.

  zuu(4); // türü void olan ifade

  static_cast<void>(goo(11)); // türü void olan bir ifade

  (void)getchar(); // geri dönüş değeri int'i dikkate almıyorum demek.

  // ---- NOT ----
  // Eğer bir türü incomplete olarak kullanılabiliyorsa (henüz) complete yapma

  // aşağıdaki iyi bir pratik değil

  // -- necati.hpp --
  // #include "nec.h"
  // #include "berk.h"
  // #include "sel.h"
  // #include "murat.h"
  // #include "emre.h"

  //   Nec foo(Berk);
  //   using Sel = Selahhattin;

  //   extern Murat mrt;

  //   struct Data {
  //     Emre* eptr;
  //   };

  // bunun yerine aşağıdaki gibi kullanmak daha doğru.

  // -- necati.hpp --
  // struct Nec;
  // struct Berk;
  // struct Sel;
  // struct Murat;
  // struct Emre;

  //   Nec foo(Berk);
  //   using Sel = Selahhattin;

  //   extern Murat mrt;

  //   struct Data {
  //     Emre* eptr;
  //   };

  // bu kullanım neden daha iyi?
  // 1-) aksi taktirde compile time uzar.
  // 2-) aksi takdirde bağımlılık oluşturulur ve başlık dosyaları tekrar tekrar
  // derlenir.

  // ABI (Abstract Binary Interface)
  // - dahil edilen başlık dosyalarının recompilation edilemesi

  return 0;
}