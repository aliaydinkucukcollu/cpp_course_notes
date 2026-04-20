#include <iostream>

// 2 tür değişken var

// mutable: değişen
// immutable: değişmeyen

// immutabele için "const" kullanılır.
// const ===> type qualifier

typedef struct cpp_const {
  double x, y;
} Point;

// API-1
// mutator OR setter
void foo(Point *ptr); // void foo(T* ptr);

// out-param: istenilen adrese output değeri yazdırılır
void calculate_point(double x, double y, Point *ptr);

// API-2
// getter OR accessor OR get function
// low-level const param: adresi gönderilen adres read-only olarak kullanılacak
void display_point(const Point *ptr);

// void display_point(Point* ptr);
// şeklinde tanımlama doğru değil
// const -correctness için const ile tanımlanması gerek!

// const kullanılmazsa
// değerini değiştirmeyecek fonksiyonda
// yanlışlıkla yapılan değişiklikte fonksiyon hata vermez.
// void display_point(Point *ptr) { ptr->x = 3.45; }

int main() {

  const int x = 5; // x ===> const variable

  // x = 44; // ill-formed

  int *ptr = (int *)&x; // UB
  *ptr = 44;

  std::cout << "*ptr: " << *ptr << '\n';

  // neden const kullanmalıyız ---> 3 Neden

  // 1-) kendimizi koruyoruz, logic hataları önlemek için

  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  primes[4]++; // logic hata, bu arrayi kullanan kodlar yanlış işleme yapacak
               // üstelik derleyici hata vermeyecek

  const int kprimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  // kprimes[4]++; // ill-formed

  // 2-) okuyucu bilgilendirmek, niyetini belli eden kod iyi koddur.

  // 3-) derleyiciye yardımcı olmak: compiler optimization

  // const with pointers
  int y = 10;

  int *p0 = &y; // p0 ===> pointer-to-int (int*)

  // 1-) TOP-LEVEL CONST
  int *const p1 = &y; // const olan p1 değişkeni
  // p1 ===> const pointer-to-int OR top-level const OR right const OR east
  // const

  *p1 = 14; // OK
  // p1 = &x; // Not OK

  // 2-) LOW-LEVEL CONST
  // aşağıdaki iki satır aynısı (const int* == int const*)
  const int *p2 = &y; // == int const *p3 = &y;
  // p2 ===> pointer-to-const int OR low-level const

  p2 = &x; // OK
  // *p2 = 23; // Not OK

  // pointerların en çok kullanıldığı yer fonksiyonların parametre değişkenleri

  // 4-) parametresi const olarak tanımlanmamış fonsiyonlara
  // const değişken gönderilemez çünkü:
  // T* ===> const T* // LEGAL
  // const T* ===> T* // ILLEGAL

  const int a = 5;
  // int* p = &a; // ERROR

  const Point p = {1.2, 4.5};
  // display_point(&p); // void display_point(Point *ptr); decleration için hatalı

  // pointer-to-pointer
  int aa = 10;
  int* aptr = &aa;
  int** apptr = &aptr;

  ++**apptr;

  std::cout << "aa: " << **apptr << '\n';

  // const neyden önce gelirse const olan odur
  const int* iptr = &x; // const olan *ptr
  int* const p4 = &aa; // const olan ptr

  // pointer-to-pointer için
  // const neyden önce gelirse const olan odur

  int* q = nullptr;
  int num1 = 10;
  int num2 = 20;

  int *ptr1 = &num1;
  int** const ptr2 = &ptr1;

  // ptr2 = &q; // ERROR!
  *ptr2 = &num2; // LEGAL
  **ptr2 = 45;   // LEGAL

  int* const *ptr3 = &ptr1;
  ptr3 = &q; // LEGAL
  // *ptr3 = &num2; // ERROR!
  **ptr3 = 45;   // LEGAL

  // const int* *ptr4 = &ptr1;
  // ptr4 = &q; // LEGAL
  // *ptr4 = &num2; // LEGAL
  // // **ptr4 = 45;   // ERROR!

  int num3 = 25;
  const int* const ptr5 = &num3; // const pointer to const int

  return 0;
}