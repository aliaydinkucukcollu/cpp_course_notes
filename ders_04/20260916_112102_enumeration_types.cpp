#include <iostream>

enum TrafficLight { TrafficLightRed, TrafficLightYellow, TrafficLightGreen };

enum ScreenColor {
  ScreenColorWhite,
  ScreenColorYellow,
  ScreenColorRed,
  ScreenColorBrown,
  ScreenColorBlue,
  ScreenColorBlack,
  ScreenColorGreen
};

int main() {

  int x = 2;
  enum TrafficLight tl = {TrafficLightGreen};
  enum ScreenColor sc = {ScreenColorBlue};

  // int -> enum
  // tl = x; // ERROR

  // enum -> int
  x = sc; // LEGAL

  // enum -> enum
  // tl = sc; // ERROR

  return 0;
}
