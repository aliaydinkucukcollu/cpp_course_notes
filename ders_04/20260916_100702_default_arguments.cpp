#include <ctime>
#include <iostream>
#include <locale>

void print_date(int day = -1, int mon = -1, int year = -1) {
  if (year == -1) {
    std::time_t sec;
    std::time(&sec);
    tm *p = std::localtime(&sec);
    year = p->tm_year + 1900;

    if (mon == -1) {
      mon = p->tm_mon + 1;
      if (day == -1) {
        day = p->tm_mday;
      }
    }
  }

  std::cout << day << '-' << mon << '-' << year << '\n';
}

int main() {

  print_date(12, 5, 1998);
  print_date(24, 2);
  print_date(24);
  print_date();

  return 0;
}
