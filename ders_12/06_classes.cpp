#include <initializer_list>
#include <iostream>

// Most Vexing Parse
// A ax(B()); ==> hem değişken tanımlama hem fonksiyon prototipi syntax'ına
// uyuyor. Ancak fonksiyon prototipi seçiliyor. Derleyiciler uyarı veriyor ama
// vermek zorunda değiller.

// aşağıdaki çözümler ile birlikte most vexing parse'dan çıkıyor kod.
// Eski Çözüm => A ax((B())); ===> ifade parantezine alındı.

// Yeni Çözüm => A ax(B{})
//            => A ax{B()}
//            => A ax{B{}}

class Myclass {
public:
  Myclass() {
    // runtimeda program akışı buraya gelmişse sınıfın elemanları haya gelmiş
    // durumda.
    //
    // tx = ...; // assignment
    //
  }
  int x, y; // sınıfın non-static data memberları sınıf nesnesi hayata
            // geldiğinde initialize ediliyor.
private:
  // T tx;
  // U ux;
};

// -> ctor sınıfın non-static veri elemanlarını nasıl initialize edecek?
//
// eskiden => member initializer list
// yeni    => constructor initializer list

int main() {

  std::initializer_list<int> mylist{1, 2, 3, 4, 7};

  return 0;
}
