#include <iostream>

// inline keyword and functions
// - C99 ile birlikte C'ye de eklendi ancak C++'daki semantikten farklı

// C++ bazı anahtar sözcükleri farklı bağlamlarda kullanıyor
// örneğin: using keyword

// - C++'da birde fazla anlam yüklenmiş

// "inline expansion optimization" ile derleyici kodu fonksiyon çağrı noktasında
// görüyor. Normalde (derleyici kodu görmüyor) linker obje kodu ile kodu
// birleştiriyor.

// eğer derleyici fonksiyon tanımını görüyorsa fonksiyon çağrısının olduğu yere
// fonksiyon kodunu yapıştırıyor.

// daha geniş kod alanı için daha geniş optimizasyon yapabilir.

// ---- 2 nedenden dolayı derleyici hız kazandırıyor. ----
// 1-) fonksiyona giriş ve çıkış kodlarının maliyeti ödenmeyecek
// 2-) fonksiyon çağrısının öündeki ve sonrasındaki bağlama bakarak geniş bir
// optimizasyon yapabiliyor.

// ---- inline expansion optimization şartları ----
// 1-) derleyici çağrılan fonksiyonun kodunu görmek zorunda

// 2-) derleyicinin optimizasyon switchleri var. 
// optimazson bayraklarına göre optimizasyon yapabilir ya da yapmayabilir.

// 3-) her fonksiyon çağrısı için optimizasyon yapmak zorunda değil.
// teknik olarak optimizasyon yapabilecekken tercih etmeyebilir.

// 4-) optimizasyon için yetersiz olabilir.


// ---- necati.cpp ----
// #include "ali.h"
// #include "aydin.h"

// bu başlık dosyalarından sadece fonksiyon bildirimi gelirse 
// optimizasyon mümkn değil.

// inline expansion optimizasyon için kodu görmesi lazım.

// inline expansion optimizastion <==> ODR

int foo(int x) {}

int main() {
  foo(12);
  return 0;
}