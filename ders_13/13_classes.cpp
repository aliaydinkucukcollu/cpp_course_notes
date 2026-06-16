#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

// neden copy constructor'ı kendimiz tanımlayalım?

// Örnek: dummy string sınıfı
class String {
public:
  // constructor
  String(const char *p)
      : mlen(std::strlen(p)),
        mp(static_cast<char *>(std::malloc(std::strlen(p) + 1))) {
    std::cout << "constructor\n";
    std::strcpy(mp, p);
  }

  void reverse() {
    for (size_t i{}; i < mlen / 2; ++i) {
      std::swap(mp[i], mp[mlen - 1 - i]);
    }
  }

  void print() const { std::puts(mp); }

  ~String() {
    if (mp) {
      std::free(mp);
    }
  }

private:
  std::size_t mlen;
  char *mp;
};

void foo(String str) { str.print(); }

int main() {
  String s1{"artik bahar geldi agaclar cicek acti"};
  s1.print();
  s1.reverse();
  s1.print();

  String s2 = s1; // derleyicinin tanımladığı copy constructor çağrılır.
  // s1.mp ile s2.mp aynı olur ==> isteyeceğimiz bir senaryo değil. NEDEN?
  // 1. value semantics korunmaz, bozulur.
  // s1 nesnesi için reverse fonksiyonu çağrılırsa, s2 de değişir.

  // 2. tanımsız davranış senaryosu
  // s1'in hayatı bitmiş ama s2'nin hayatı devam ediyor olabilir.
  // sınıfın destroctur'ı allocate edilen alanı geri verecek peki ya sonra???
  // s2 hayattayken s2 içindeki pointerlar ==> dangling pointer oldu.
  // s2'nin herhangi bir fonksiyonu çağrıldığında ==> Undefined Behaviour (UB)

  // 2.1. ==> Double dilision
  // s1 yok edildi ve s2 için de constructor çağrılıyor.

  s2.reverse();
  s1.print();
  s2.print();

  (void)getchar(); // UB olmasın beklesin!

  // s2 en son hayata geldi ilk onun hayatı bitecek.
  // s2 -> destructor -> dinamik bellek bloğu free edilecek.
  // s1'in içindeki pointer dangling pointer olur.
  // bu da double illision demek...

  // part - 2
  String s{"artik bahar geldi agaclar cicek acti"};
  foo(s);

  s.print(); // bommm! UB

  (void)getchar();

  // peki copy constructor'ı biz yazsaydık ne yapmamız gerekiyordu?
  // 1. s2 değişkeninin de bir bellek alanı allocate etmesi gerekirdi.
  // s2'nin içindeki pointerın kendi allocate ettiği alanı göstermesi gerekirdi.
  // böylece s1 için yapılan çağrı s2'yi etkilemez.
  // hangisi daha önce hayatını kaybederse kaybetsin
  // her nesnesnin kendi destructorı kendi nesnesnin meorysini geri verecek.
  //
  // derleyicinin copy constructor'ı pointer kopyalıyor, biz yazarsak
  // pointerın gösterdiği değerleri kopyalıyor.
  //
  // deep copy    : pointerın gösterdiği kaynağı kopyalıyoruz.
  // shallow copy : pointer kopyalıyor.

  return 0;
}
