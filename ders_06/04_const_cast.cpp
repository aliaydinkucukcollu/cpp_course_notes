#include <iostream>

// const_cast
// 1-) const T* ==> T*
// 2-) reference
// 3-) volatile

volatile int gnum = 2092;

int main() {

  // 1-) const T* ==> T*
  int x = 23;

  const int *xptr = &x;
  // code
  // int* p = static_cast<int*>(xptr); ERROR
  int *p = const_cast<int *>(xptr);

  // 2-) reference
  const int &cr = x;
  int &r = const_cast<int &>(cr);

  // volatile keyword
  int *volatile iptr = (int *)0x1AC4; // volatile pointer to int

  volatile int *vptr = (int *)0x1AC4; // pointer to volatile int

  volatile int *volatile vvptr =
      (int *)0x1AC4; // volatile pointer to volatile int

  // 3-)  cast for volatile keyword
  volatile int* vp = &gnum;
  int* gnum_ptr = const_cast<int*>(vp);

  return 0;
}