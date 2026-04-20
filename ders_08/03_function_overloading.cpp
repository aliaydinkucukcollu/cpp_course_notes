// ---- function overload resolution ----
// 1-) başarılı
// 2-) başarısız
//  2.1 -> function overloading yok
//  2.2 -> ambiguity (belirsizlik)

// ---- 1. candidate function ----

enum Color { White, Yellow, Red, Brown, Blue, Black };

void foo(int);
void foo(int *);
void foo(int, int);
void foo(double);
void foo(long);
void foo(Color);

// ---- 2. viable function ----
// - eğer fonksiyon tek başına bu argümanla bu fonksiyona yapılan çağrı legal
// olur mu? ==> foo(x)
// - viable functions:
//    void foo(int);
//    void foo(double);
//    void foo(long);


int main() {

  int x = 10;

  foo(x); // for this function call there are 6 candidate function

  return 0;
}