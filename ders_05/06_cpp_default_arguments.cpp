#include <ctime>
#include <iostream>
#include <string>

// // function redecleration
// //  - fonksiyonun bildiriminin derleyici ttarafından 2., 3. ,... n. kez
// //  görülmesi

// void foo(int, int, int = 0);
// void foo(int, int = 0, int); // derleyici void foo(int, int = 0 , int = 0);
//                              // şeklinde değerlendiriyor

// // neden böyle bir araca ihtiyaç duyuluyor?

// // ---- ismail.h ----
// void bar(int, int, int = 0);

// // ---- necati.cpp ----
// // #include "ismail.hpp"

// // void bar(int, int=0, int = 0); // error
// void bar(int, int = 0, int);

// // AIM: just set zero to second argument. HOW?
// void bar(int x, int y, int z);

// // SOLUTION: write a wrapper!
// void call_foo(int x, int z, int y = 0) { foo(x, y, z); }

// fonksiyon çağrısında değer -1 ise mevcut zaman kullanılır
void print_date(int msec = -1, int min = -1, int hour = -1, int mday = -1,
                int mon = -1, int year = -1, char* time_zone = nullptr) {
  if (year == -1) {
    time_t sec = time(nullptr);
    tm *tp = localtime(&sec);
    time_zone =  const_cast<char*>(tp->tm_zone); 
    year = tp->tm_year + 1900;
    if (mon == -1) {
      mon = tp->tm_mon + 1;
      if (mday == -1) {
        mday = tp->tm_mday;
        if (hour == -1) {
          hour = tp->tm_hour;
          if (min == -1) {
            min = tp->tm_min;
            if (msec == -1) {
              msec = tp->tm_sec;
            }
          }
        }
      }
    }
  }
  std::cout << mday << "." << mon << "." << year << " " << hour << ":" << min
            << ":" << msec << " UTC" << time_zone <<  '\n';
}

// out param
void buz(int, int *ptr = nullptr);

int main() {

  // foo(2, , 5); // error

  //   print_date(15, 5, 1987);

  //   print_date(15, 5);

  //   print_date(15);

  // print current time
  print_date();

  int x = 10;
//   buz(14);
//   buz(12, &x);

  std::string str{"23443"};
  int res = std::stoi(str);

  std::cout << "converted number: " << res << '\n';

  return 0;
}