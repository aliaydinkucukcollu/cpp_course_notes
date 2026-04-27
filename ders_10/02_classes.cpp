#include <iostream>

// nec.h
class Nec {
public:
  // sınıf içinde tanımlanan fonksiyonlar implicitly inline
  void foo(); // fonksiyon bildirimi
  void foo(int);
  void foo(int, int);
};

// NOTE
// ==> üye fonksiyonu header dosyasında hem berlitp hem tanımlamak istersek
// ikisinden birinde inline anahtar sözcüğü olmalı.
// örneğin tanım için:
// inline void Nec::foo() {}

// nec.cpp

void Nec::foo() // fonksiyon tanımı
{}

void Nec::foo(int) // fonksiyon tanımı
{}

void Nec::foo(int, int) // fonksiyon tanımı
{}

// bu fonksiyonun tnaımı olmadığı için error.
// void Nec::foo(double) {}

int main() { return 0; }