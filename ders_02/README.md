# Ders-02

11 Temmuz 2026 Cumartesi

---

## C in C++

### Türlere ilişkin farklılılar

- characters
```c
// in C
'A' // character constant, int
'\n'
'\101'
```

```cpp
// in C++
'A' // character literals, char
```

- karşılaştırma operatörleri
```c
// in C
a > b // int

#include <stdbool.h>
_Bool // C99 ancak genel kabul görmedi

bool b = true; // _Bool b = 1;
b = false; // b = 0;
```

```cpp
// in C++
a > b // bool

bool // bellekte en az 1 byte yer kaplar
    true
    false
```

- bool data type & type conversions
```cpp
int x;
bool b = true;

// bool to int
x = b; // x = 1

x = 0;

// implicit type conversion
// int to bool
b = x; // b = false
```

- pointer to bool conversion(**DİKKAT**)
```cpp
int x = 10;
int *ptr = &x;
bool b = ptr; // b = true (null pointer değil)

ptr = nullptr;

b = ptr; // b = false (null pointer)
```

- bool türünden pointer türüne dönüşüm yok.

- bool increment
```cpp
// Modern C++ ile geçersiz (ill-formed)
bool flag = false;

++flag;
```

- Örneğin:
```cpp
// integral promotion
// int'ten küçük türler operatörlerin operandı olduğunda int'e yükseltilerek işlem yapılır.
true + true // int, 2
```

- integral promotion
```c
// rank'i int'den küçük türler
// operatörün operandı olduğunda
// int'e yükseltilerek işlem yapılıyor.
bool
char / signed char / unsigned char
short / unsigned short

int

// örneğin:
char c1 = 5;
char c2 = 7;
c1 + c2; // int
+c1 // int

true + true; // int,2
```

- arithmetic type
    - tam sayı ve gerçek sayı türlerinin birleşim kümesi

    - floating point type
        - float
        - double
        - long double

- void pointer (void*)
```c
// in C
// T* --> void*     OK

// void* --> T*     OK
void foo(void* vptr)
{
    int *ip = vptr; // LEGAL

    int *ip = (int*)vptr; // LEGAL
}

```

```cpp
// T* --> void*         OK
int x = 10;
void *vptr = &x;

double dval = 3.156;
vptr = &dval;

// void* --> T*         ERROR
void foo(void* vptr)
{
    int *ip = vptr; // ERROR

    int *ip = (int*)vptr; // LEGAL

    int *ip = static_cast<int*>(vptr); // LEGAL
}
```

- Hem C hem de C++ dillerinde farklı pointer türleri arasındaki dönüşümler ERROR.(geçerli değil)
Aritmetik türler ile pointer türleri arasında da dönüşüm yok.
```cpp
int x = 10;
int *ptr = &x; // OK

int *ptr = x; // ERROR

unsigned int y = 44;
ptr = &y; // ERROR
```

- enum türlerine yönelik farklılıklar
    - basic types
    - user-defined types
        - structures
        - unions
        - enumarations
```c
// ---- in C ----
// structure tag
struct Data{
    int x,y,z;
};

// union tag
union Nec{
    int x;
    double dval;
    char buf[16];
};

// enumaration tag
enum Color{White, Yellow, Red};

struct Data mydata;
union Nec mynec;
enum Color mycolor;
```

```c
// ---- in C++ ----
// tag doğrudan türü belirtmek için yeterli.
// structure tag
struct Data{
    int x,y,z;
};

// union tag
union Nec{
    int x;
    double dval;
    char buf[16];
};

// enumaration tag
enum Color{White, Yellow, Red};

Data mydata;
Nec mynec;
Color mycolor;
```

- C dilinde aritmetik türlerden enumeration türlerine örtülü dönüşüm var e tersi de var.
Farklı enum türleri arasında da dönüşüm var.
```c
// in C 
enum Color{Red, Green, Yellow};
enum Pos{On, Off, Idle};

enum Color mycolor = Red;
mycolor = 1; // OK

mycolor = Idle; // OK
```

- C++ dilinde artimetik türlerden enum türlerine örtülü dönüşüm yok. Farklı enum tüleri arasında da örtülü dönüşüm yok.
```cpp
// in C++
enum Color{Red, Green, Yellow};
enum Pos{On, Off, Idle};

enum Color mycolor = Red;
mycolor = 1; // ill-formed

mycolor = Idle; // ill-formed

// enum -> aritmetic dönüşüm var

int x = 4;
x = mycolor; // ne yazık ki geçerli
```

Bu problemi çözmke için Modern C++'da yeni bir araç var => **scoped enum**

```cpp
// scoped enum
enum class Color{Red, Green, Yellow};

// unscoped enum
// traditional enum
enum Color{Red, Green, Yellow};
```

- const ile ilgili farklılıklar
    - const correctness
        - const olması gereken herşey const olucak.
```cpp
// RED FLAG => const correctness
void print_array(int *p, size_t size);

// should be
void print_array(const int *p, size_t size);
```

- C++ const keywords
    - const
    - constexpr
    - consteval
    - constinit

- const
    - mutable
        - değiştirilebilir
    - immutable
        - değiştirilemez
```cpp
// mutable
int x = 5;

// immutable
const int y  = 10;
```

- neden bir değişeni immutable bildiriyoruz?
    - 1. kodlama hatalarına karşı kendimizi korumak.
    - 2. kodu okuyana doru bilgi vermek.
        - Bir C ya da C++ kodu yazanın acemeliği göz önüne alınarak okunmaz.
        - intent -> niyet
    - 3. derleyiciye yardımcı olmak.
        - compiler optimization
            - derleyiciler const olan değişkenlerin kullanıldığı ifadelerde bu değişkenlerin değerinin değişmeyeceğini bilip daha iyi optimizasyon sağlıyor.

- const bir değişkeni değiştirme girişimi (legal bir kod olsa da) her zaman tanımsız davranıştır.
```cpp
const int x =10;
int *ptr = (int*)&x;

*ptr = 87; // legal ama UB
```

- const and pointers

```cpp
int x = 10;
int y = 30;

// pointer to int
int *p1 = &x;
p1 = &y; // OK
*p1 = 556; // OK

// ikisi de aynı anlamda
int const *p2 = &x;
const int *p2 = &x;

// const pointer to int (top level const)
// p3'ün değeri değişemez
// *p3 değişir
int *const p3 = &x;
p3 = &y; // ERROR
*p3 = 55; // OK

// pointer to const int (low level const)
// p4'ün değeri değişebilir
// *p4'ün değeri değişemez
const int* p4 = &x;
p4 = &y; // OK
*p4 = 234; // ERROR

// const pointer to const int
// (top level const) + (low level const)
// p5'ün değeri değişemez
// *p5'ün değeri değişemez
const int* const p5 = &x;
```

- pointer usages with pointers
```cpp
// set function
// setter
// mutator
void foo(T *ptr);

// accessor
void bar(const T* ptr);
```

- const pointer tür dönüşümü
```cpp
// T* -> const T* // LEGAL
int x = 10;
const int* ptr = &x; // OK

// const T* -> T* // ERROR
const int x = 10;
int* ptr = &x; // ERROR
```

- const overloading
```cpp
// const olmayan nesneler
void foo(int*);

// const olan nesneler
void foo(const int*);
```

## C / C++ const farkları

```c
// in C
// string literal, char[8]
"mustafa"

char* p = "necati ergin"; // legal
```

```cpp
// in C++
// string literal, const char[8]
"mustafa"

// const char* -> char*
char* p = "necati ergin"; // ERROR
```

- DİKKAT
hem C dilinde hem C++ dilinde string literallerini değiştirmeye yönelik kod tanımsız davranış.

```cpp
char *p = "Serkan";

*p = 'F'; // UB
p[1] = 'u';

// C'de legal ancak UB

// C++'da legal bile değil
// pointer const olsa legal ancak UB yine
```

- linkage (bağlantı)
    - birden fazla kaynak dosya olması lazım.
    - external linkage
        - aynı varlığa ait isim diğer kaynak dosyalarda da kullanılıyor.
    - internal linkage
        - her dosya kendi ismini kullanıyor.
```cpp
// a.c

// global değişken
int counter  = 0; 

// b.c
// func counter'ı değiştiriyor.

// c.c
// bar counter'ı değiştiriyor.

// d.c
// buz counter'ı değiştiriyor.
```

- ilk vermemiz gereken karar:
    - diğer kaynak dosyalara erişim verilsin mi?
        - evet -> external linkage
        - hayır -> internal linkage

- const and linkage

global const değişkenlerin isimleri C dilinde external linkage ancak C++ dilinde intrernal linkage.

```c
// in C
// external
const int g = 10;

// internal
static const int g = 34;
```

```c
// in C++
// internal
const int g = 10;

// external linkage
extern const int g = 122;
```

- C99 ile eklenen C++'da olnmayan bazı featurelar
    - VLA (variable length array)
    - compound literal
    - flexible array members
    - designated initializer

- örneğin
```c
// in C
#include <stdio.h>
void foo(void)
{   
    char str[4] = "ömer";
    // yukarıodaki tanımlama C dilinde geçerli ama sonunda null karakter yok.

    puts(str); // UB

    // OK
    for(int i = 0; i<4; ++i)
    {
        putchar(str[i]);
    }
}
```

```cpp
// in C++
#include <stdio.h>
void foo(void)
{   
    char str[4] = "ömer"; // geçersiz

    char str[] = "ömer"; // geçerli

    char str[5] = "ömer"; // geçerli
}
```

- **auto** keyword
    - C'de bir anlamı var.
    - varlık nedeni ortadan kalktı.
```c
int z = 56;// otomatik ömürlü
auto int x = 4; // otomatik ömürlü
static int y = 45; // statik ömürlü
```

- **auto** keywordünün Modern C++(C++11) ile birlikte C'deki anlamı gitti yeni anlamlar yüklendi.    

- **register** C dilinde bir keyworddür. ama tıpkı auto gibi kullanımdan düşmüş durumda.

---

## Ek kaynaklar

- 



---

## ToDo

- [ ] C -> pointer book
- [ ] integral promotion
- [ ] code review
- [ ] const correctness
- [ ] spotify project in C with pointers
    - pointer to int
    - pointer to const int
    - const pointer to int
    - const pointer to const int
- [ ] C strings
- [ ] C99
    - VLA (variable length array)
    - compound literal
    - flexible array members
    - designated initializer
- [ ] puts in C
- [ ] putchar