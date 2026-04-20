#include <stdio.h>
#include <stdlib.h>

// C ==> type-cast operator
// usage:
//      (int)dval

// implicit conversion yerine type-cast operator kullanmak
// kod davranışını değiştirmiyor. Niyet belli oluyor.

// ---- Dikkat! ----
// const T* ==> T*
// - type-cast operatorü olmadan yapılan dönüşüm : constraint violation
// - dönüşüm sonrası const nesneyi değiştirme girişi UB olur.
// - öyle durumlar var ki yanlış diyemeyiz.

char *strchr(const char *p, int ch) {
  while (*p) {
    if (*p == ch) {
      return (char *)p;
    }
    ++p;
  }
  if (ch == '\0') {
    return (char *)p;
  }
  return NULL;
}

struct Nec {
  int x, y, z;
};

typedef int *intptr;

int main() {

  // example-1: const T* ==> T*
  // x'i değiştiremeyecek bir pointer olasun ama sonradan fikir değişti diyelim
  int x = 10;
  const int *p = &x;
  // code
  int *ptr = (int *)p; // const T* ==> T*

  // example-2: UB
  const int a = 10;
  const int *aptr = &a;
  // codes
  int *p2 = (int *)aptr;
  *p2 = 234324; // UB

  // example-3: farklı adres türleri arasındaki dönüşümler
  // kodu type cast operator ile legal kıldık ama doğru değil!
  float f = 2323.34;
  int *iptr = (int *)&f;
  *iptr = 56; // UB

  // peki hangileri hem legal hem doğru?
  // 1-) T* ==> char / signed char / unsigned char adres türlerine

  double dval = 234.324;
  unsigned char *ucptr = (unsigned char *)&dval;

  for (size_t i = 0; i < sizeof(double); ++i) {
    printf("%u \n", (unsigned)*ucptr);
    ++ucptr;
  }

  // 2-) aynı tamsayı türünün signed ve unsigned dönüşümleri

  int num = -213;
  unsigned int *nptr = (unsigned int *)&num;

  printf("*nptr: %d\n", *nptr);

  // 3-) yapıların adresleri ile ilk elemanlarının adresleri arasındaki
  // dönüşümler
  struct Nec mynec = {2, 4, 5};
  int *nec_ptr = (int *)&mynec;

  printf("mynec.x: %d\n", mynec.x);
  printf("mynec.x: %d\n", *nec_ptr);

  // tersi de mümkün
  int *xptr = &mynec.x;
  struct Nec *nec = (struct Nec *)xptr;
  printf("mynec.z: %d\n", nec->z);

  // 4-)     T* ==> void*
  //      void* ==> T*

  int *mptr = malloc(100 * sizeof(int)); // legal for C
  // int* mptr = (int*) malloc(100*sizeof(int)); // legal for C++

  // 5-) enum1 ==> enum2
  //       int ==> enum
  //      enum ==> int

  // enum1 ==> enum2
  enum Mode { On, Off, Idle };
  enum VehicleState { Active, Inactive, Charging };

  enum Mode mode = Idle;

  enum VehicleState state = (enum VehicleState)mode;

  printf("state: %d\n", state);

  // int ==> enum
  int imode = 1;

  enum Mode int_mode = (enum Mode)imode;
  printf("%d\n", int_mode);

  // enum ==> int
  enum RobotMode {
    idle,
    navigation_mode,
    patrol_mode,
    circle_mode,
    formation_mode
  };

  enum RobotMode robot_state = circle_mode;
  int mode_num = (enum RobotMode)robot_state;

  printf("Robot Mode: %d\n", mode_num);

  int h = 15;
  const intptr hptr = &h; // int* const hptr = &h; // top level const
  *hptr = 19;

  printf("h: %d\n", h);


  return 0;
}