#include <iostream>

// ---- predefined symbolic constants ----

// C99
// __LINE__
// __FILE__
// __DATE__
// __TIME__
// __STDC__

// C++
// __cplusplus

// ---- name mangling (name decoration) ----
// C'de function overloading yok. Bu nedenle aynı isimli bir fonksiyondan sadece
// 1 adet bulunabilirken, C++'da function overloading olduğu için aynı isimli
// fonksiyondan birden fazla bulunabilir. Bu nedenle linker fonksiyon isimlerini
// aynı isimle kodlarsa bu bir ambuguity oluşturacaktır. C++'da bu problem name
// mangling ile çözülür. Derleyici fonksiyon çağrısını gördüğünde hangi
// fonksiyonun çağrılacağını bilmediğinden, name mangling uygular. Name
// mangling: derleyicinin parametre türü ve kapsamını belirtecek şekilde
// fonksiyonları yeniden adlandırır.

// C'de yazılmış ancak C++'da kullanılmak istenen fonksiyonklar için de
// extern C bildirimi ile bu problem çözülmüş oluyor.

// Yazılmış fonksiyonun, eğer C++ kodunda kullanılırsa extern C bildirimini
// yapmak için aşağıdakiş gibi yapı klullanılır.

// ---- ahmet.h ----
#ifdef __cplusplus
extern "C" {
#endif

void foo(int);
void bar(double);
// ...

#ifdef __cplusplus
}
#endif

int main() {
  std::cout << __cplusplus << '\n';
  return 0;
}