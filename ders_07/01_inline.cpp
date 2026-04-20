#include <iostream>

// inline keyword and inline functions

// ---- inline expansion optimization ----
// - derleyici kodu görecek
// - derleyici analizinden olumlu sonuç çıkıcak
// - optimizasyon bayrakları uygun olucak
// - en uygun fonksiyonlar kısa fonksiyonlar : one line functions
// - derleyici bunu yapabilecek kabiliyette olacak

// ---- Not ----
// derleyici inline keyword olmayan bir fonksiyonu optimize edebilir
// inline keywordü kullanılarak tanımlanan bir fonksiyonu optimize
// etmeyebilir. Peki bu durumda yazmanın avantajı ne?

// CEVAP: ODR.
// derleyiciye optimizasyon imkanı tanımak için derleyicinin kodu görmesi
// gerekiyor. inline anahtar sözcüğü kullanmadan sadece decleration yapabiliriz
// başlık dosyasında. sadece decleration ile de derleyici kodu görmediği için
// derleyicinin kodu optimize etme imkanı yok. Optimizsayon imkanı için kodun
// definition'ını başlık dosyasına koymamız lazım. ODR violation olmadan bunu
// inline keyword ile yapabiliriz.

// Örnek:

// necati.hpp
inline int foo(int x) { return x * x; }

static int buz(int x) { return 2; } // internal linkage

// a.cpp
// b.cpp
// c.cpp

// yukarıdaki örnekte necati.hpp başlık dosyasında 2 adet fonksiyon
// tanımlanmıştır. Bu kaynak dosyayı a.cpp, b.cpp ve c.cpp kaynak dosyaları
// dahil ettiklerinde foo() fonksiyonu inline expansion optimizasyonuna girmese
// bile derleme esnasında tek bir fonksiyon oluşacak. buz() fonksiyonu ise
// static anahtar sözcüğü ile tanımlandığı için internal linkage bağlkamı oluşur
// ve her bir kaynak dosya için ayrı fonksiyon üretilir.

// ---- C++17 öncesi ----

// necati.hpp
extern int x;

// necati.cpp
int x = 10;

// header-only library : hpp var cpp yok
// header-only library için global değişkenler ve sınıfların static veri
// elemanları için yapamıyorduk.

// çözüm:

// global değişken yerine fonksiyon local statik ömürlü değişkeni döndürüyor.
inline int& getx()
{
    static int x = 10;
    return x;
}

// ---- C++17 sonrası ----

// artık inline keyword ile global değişkenler ve sınıfların static veri
// elemanları için yapabiliyoruz.

// necati.hpp
inline int y;

int main() { return 0; }