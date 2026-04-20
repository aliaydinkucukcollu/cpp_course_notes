#include <iostream>

// ---- function overloading (fonksiyonların yüklenmesi) ----
// - C'de yok
// - birden fazla fonksiyon belirli şartlar altında aynı ismi taşıyabiliyor
// - compile time'a yönelik bir araç

// ---- Neden function overloading? ----
// - daha yüksek düzeyde soyutlama(abstraction yapmak)
// - kullanıcı kodun işini kolaylaştırmak

// ---- function overload resolution ----
// - derleyici aynı isimli birden fazla fonkiyonlardan hangisinin çağrılacağını
//   dilin kurallarına göre anlaması

// ---- function overloading şartları ----
// 1-) fonksiyonların isimleri aynı olmalı
// 2-) scopeları(kapsam) aynı olmalı
// 3-) signature(imza)ları farklı olmalı
//      -> return dahil değil

// function redecleration (function overlading değil)
int foo(int);
int foo(int);

// tanımı yapıldığında derleyici hata vermiyorsa function overloadingdir.

// imza aynı geri dönüş değeri türü farklı ise ERROR
// int bar(int, int);
// float bar(int, int);

// Example: funciton overloading
int buz(int, int);
int buz(int);

int main() { return 0; }