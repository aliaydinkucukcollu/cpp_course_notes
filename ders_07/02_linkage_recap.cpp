#include <iostream>

// ---- linkage (bağlantı) ----
// - external linkage (dış bağlantı)
// - internal linkage (iç bağlantı)
// - no linkage

// ---- linkage nedir? ----
// örneğin x değişkeni aynı projeye ait a.cpp , b.cpp ve c.cpp isimli kaynak
// kodlarda kullanılıyor.
// eğer link zamanında ve runtimeda bu x ismi birden fazla kaynak dosyada
// kullanılmasına karşın aynı varlığa ilişkinse bu isim dış bağlantıdadır.
// (external linkage)

// bunu amaçlıyorsak aşağıdaki gibi tanımla
int x;

int buz(void) { return 8; } // clientler için var olan fonksiyon

// dezavantajı: birden fazla kaynak dosyadan erişimde çakışma olmamalı.

// her birindeki x aynı varlığa ait değilse ==> internal linkage

// internal linkage olması için aşağıdaki gibi tanımla
static int a;

static int foo(void) { return 6; } // bu sadece bulunduğu dosyanın fonksiyonu

int main() { return 0; }