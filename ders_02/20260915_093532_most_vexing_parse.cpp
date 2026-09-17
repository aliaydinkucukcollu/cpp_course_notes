#include <iostream>

class Timer {
public:
  Timer() { std::cout << "Timer def. ctor called\n"; }
};

class Engine {
public:
  Engine(Timer t) { std::cout << "Engine ctor called\n"; }
  void run() { std::cout << "Engine running!\n"; }
};

int main() {

  // direct initialization
  // Timer();

  // AIM -> create an Engine object
  // that takes anonymous temporary object type Timer
  Engine myEngine(Timer()); // most vexing parse

  // REALITY -> function prototype created

  // SOLUTION
  Engine my_engine{Timer{}};
  my_engine.run();

  return 0;
}