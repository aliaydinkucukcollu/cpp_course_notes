#include <iostream>

struct Date {
  int d, m, y;
};

// yanlışlıkla değişiklik yaparbiliriz ve bu bir logic hata oluşturur.
void print_date(Date *p) {}

// sınıflarda da aynı durum var

class DateClass {
public:
  void print() {} // const olmalı
};

int main() {

  const Date mydate = {3, 5, 1980};

  // const T* ==> T* (illegal)
  // print_date(&mydate);

  return 0;
}