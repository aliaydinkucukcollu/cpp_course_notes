# Ders-04

18 Temmuz 2026 Cumartesi

---

## Default Arguments

- C'de yok.Modern dillerin çoğunda var.

- Önceden belirlenmiş argümanların kullanılmasını sağlıyor.

- C++'ın standardın kütüphanesi sıklıkla kullanıyor.(STL)

- fonksiyon bildiriminde ya da tanımında belirtilebilir ancak ikisinde birden değil.

```cpp
// --- HEADER FILE (math_utils.h) ---
// DECLARATION: Specify default values here
void printMessage(std::string msg = "Hello", int count = 1);

// --- SOURCE FILE (math_utils.cpp) ---
// DEFINITION: Do NOT repeat the default values here
void printMessage(std::string msg, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << msg << "\n";
    }
}
```

- parametrelerden biri varsayılan argüman almışsa sağındaki kalan paramtrelerin hepsinin varsayınlan argüman alması gerekiyor.

```cpp
void foo(int x = 6, int); // ERROR

void foo(int, int  = 6, int = 0); // OK
```

- fonksiyon bildiiriminde parametrelere isim vermek de vermemekte geçerli.

- Eğer bir fonksiyonun tanımında kullanılmaycak bir paramtre varsa bu parametreye isim vermeyin.
```cpp
void dummy(int x, int)
{
    // use only x here
}
```

- nullptr default argument
```cpp
void foo(int *p = nullptr);
```

- reference default argument

```cpp
int x = 5;
void bar(int & = x);
```

- string literal default argument
```cpp
void baz(const char* p = "");
```

- function default argument
```cpp
int foo(int = 0);
int bar(int = foo());

bar(); // bar(foo(0));
```

- tipik kullanım:
    - asla kullandığınız bir kütüphanenin bir header dosyasında değişiklik yapmayın.
```cpp
// a.h
void foo(int x, int y, int z);

// b.cpp

// #include "a.h"

void foo(int x, int y, int z = 0);

// main.cpp

foo(12,45); // foo(12,45,0);

```

- function redecleration
    - fonksyionu yeniden bildirmek.

- ek varsayılan arguman eklemek
```cpp
// a.h
void foo(int x, int y, int z = 0);

// b.cpp

// #include "a.h"

void foo(int x, int y = 0, int z);

// main.cpp

foo(12); // foo(12,0,0);
```

- daha önceki bir parametre değişkenini varsayılan argümanda kullanamayız.
```cpp

void foo(int x, int y = x * 2); // ERROR
```

- default argüman farklı kullanım örneği:
```cpp
void process_date(int day = -1, int mon = -1, int year = -1)
{
    // yıl için varsayılan argüman kullanılmış mı
    if(year == -1)
    {
        // mevcut yılı kullan
    }
}

// kullanım senaryosu -> foksiyona argüman gönderilmiş mi gönderilmemiş mi onu kotrol etmek
```

- NOT: C^deki kütüphanelerin C++'da kullanımı
```cpp
// in C
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

// in C++
#include <cstdio>
#include <cctype>
#include <cstddef>
#include <cstring>
```

---

## Enumeration types in C++

- enum türü
    - enum türleri tamsayı türünün bir alt kümesidir, hem C hem C++ için.

- enum recap
```c
// enumerator
enum Color {White, Yellow, Red, Brown, Blue, Black};

// Red -> compile time sabiti

// fonksiyon içinde(lokal düzeyde) tanımı yapılabilir.

// 0'dan başlayıp artarak gidiyor.

// aksi durum için:
enum Color {White=123, Yellow=213, Red=567, Brown, Blue, Black};

// Brown -> 568

// legal
enum Color {White=123, Yellow=213, Red=567, Brown, Blue, Black = White + 3};

// negatif değer de olabilirler.
enum Color {White, Yellow, Red = -1, Brown, Blue, Black};

// trailing comma
// negatif değer de olabilirler.
enum Color {White, Yellow, Red, Brown, Blue, Black, };
```

- Neden kullanıyoruz?
    - önceden belirlenmiş sabitlerin kullanımında kodu yazmayı ve okumayı kolaylaştırıyor.

###  C++ yönelik kurallar

- typedef yapmadan kullanım mümkün.
```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

// enum Color c;
Color c;
```

- bir enum türünde diğer tam sayı türlerinden (implicit conversion) yoktur.
```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

Color c{Yellow};
int x = 5;
c = x; // ERROR
```

- Farklı enum türleri arasında da dönüşüm yok.
```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

enum Season {Spring, Summer, Autumn, Winter};

Color c = Winter; // ERROR

Color c1 = Blue;
Color c2 = c1; // OK
```

- DİKKAT: bir enum türünden aritmetik türlere  dönüşüm geçerli.
```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

int x = 5;
Color mycolor{Brown};

// enum -> int
x = mycolor;
```

- C++ felsefesi
    - strict type checking 

- her ifadenin bir data type'ı vardır.
```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

Color mycolor{Brown};

// mycolor ifadesinin türü -> Color

```

- underlying type
    - derleyici tarafında enum türleri için kullanılan tamsayı türü
```cpp
enum Color {White, Yellow = 9823455, Red, Brown, Blue, Black};

// underlying int -> int unsigned int olabilir

std::underlying_type_t<Color> x;

// diğer çözüm: underlying type'ı belirtmek.
enum Color : int;
```

- bu problem taşınabilirlik açısında sorun oluşturuyordu.
    - complete type
    - incomplete type

- C'den gelen enum türleri incomplete type olarak kullanamıyoruz.
```cpp
// neco.h

// aşağıdaki kullanım error oluşturacak çünkü derleyici için Color bir incomplete type.

enum Color;

struct Neco{
    int x, y;
    Color c; // storage
};
```

## Neden C'den gelen enum türlerini sevmiyoruz?

- enum türlerinden aritmetik türlere örtülü dönüşüm olası.
- header'larda enum türlerinin yapı elemanı olması durumunda incomplete type olarak kullanılamaması
- scope
    - each identifier has a scope

```cpp
enum Color {White, Yellow, Red, Brown, Blue, Black};

void foo()
{
    Color;
    Red;
}
```

- örnek problem yaratan senaryo:

```cpp
// traffic.h
enum TrafficLight {Red, Yellow, Green};

// screen.h
enum ScreenColor {White, Yellow, Red, Brown, Blue, Black, Green};

// necati.cpp
#include "traffic.h"
#include "screen.h"

// redefinition
// name collision -> ERROR
```

- çözüm:
```cpp
// traffic.h
enum TrafficLight {TrafficLightRed, TrafficLightYellow, TrafficLightGreen};

// screen.h
enum ScreenColor {ScreenColorWhite, ScreenColorYellow, ScreenColorRed, ScreenColorBrown, ScreenColorBlue, ScreenColorBlack, ScreenColorGreen};

// necati.cpp
#include "traffic.h"
#include "screen.h"

// artık error değil
```

- çözüm - 2:
    - Unscoped enum
        - C++98
    - Scoped enum
        - C++11 ile ekleme yapıldı.

### Scoped enum's

```cpp
// enum class -> scoped enum
enum class Color {White, Yellow, Red, Brown, Blue, Black};

// struct ile de kullanılabilir
enum struct Color {White, Yellow, Red, Brown, Blue, Black};
```

- artık scoped enumlardan aritmetik türlere dönüşüm yok.

```cpp
enum class Color {White, Yellow, Red, Brown, Blue, Black};

Color my_color{};

int x = my_color; // ERROR
```

- artık kendi scopeları var
    - scope resolution operator (::)
```cpp
enum class Color {White, Yellow, Red, Brown, Blue, Black};

Color my_color = Color::Red;

Color my_color = White; // name lookup error
```

- dolayısıyla aşağıdaki durum artık problem değil.
```cpp
// geçerli kullanım
enum class TrafficLight {Red, Yellow, Green};

enum class ScreenColor {White, Yellow, Red, Brown, Blue, Black, Green};
```

- underlying type'ı kendimiz seçebiliyoruz.
```cpp
// tanımda
enum class Color : int {White, Yellow, Red, Brown, Blue, Black};

enum class Color : unsigned {White, Yellow, Red, Brown, Blue, Black};

enum class Color : unsigned char {White, Yellow, Red, Brown, Blue, Black};

// forward decleration'da
enum class Color : unsigned char;

// unscoped enumlar için de geçerli.
enum Color : int;
```

- Eğer geçmişten gelen bir bağımlılık yok ise (legacy code) scoped enum kullan.

- unscoped enum özelliği:
```cpp
// tanımda
enum Color : int {White, Yellow, Red, Brown, Blue, Black};

Color::Red; // generic programlama için legal oldu.
```

- using enum bildirimi (C++20)
    - dar bir scope için faydalı
```cpp
enum class Color {White, Yellow, Red, Brown, Blue, Black};

// qualified name (nitelenmiş isim)
void foo()
{
    Color my_color = Color::Red;
    
    my_color = Color::Blue;
}

void bar()
{
    // using enum decleration
    using enum Color;

    // use unqualified names here

    Color my_color = Red;
    my_color = Blue;
} // using enum decleration ends here
```

- farklı kullanımları:
```cpp

using enum Color;

// use only Red as unqualified name
using enum Color::Red;

// use only Red and Black as unqualified name
using enum Color::Red, Color::Black;
```

### Tür dönüştürme operatörleri

- C'deki tür dönüştürme operatörü
    - type-cast operator (C-style cast)

- C'den gelen type-cast operator'ün C++ dilinde kullanımı geçerli ancak (kallanmanızı makul kılıcak bir neden söz konusu değilse) kullanmayın. Bunun yerine C++ dilinin C'de olmayan type-cast operatörlerini kullanın.

- C++'daki tür dönüştürme operatörleri
    - static_cast
    - const_cast
    - reinterpret_cast
    - dynamic_cast

- C'deki tür dönüştürme operatörü'nün kötü tarafları
    - Tür dönüşümünü ne amaçla yaparsanız yapın aynı operatör kullanılıyor.
    ```c
    int x = 10;
    int y = 3;

    double dval = x / y; // 3
    double dval = (double) x / y; // 3.333
    ```
    ```c
    int x = 10;
    const int* cptr = &x;

    // const cast (const T* -> T*)
    int* iptr = (int*)cptr;
    ```
    ```c
    int x = 10;
    // farklı pointer türüne dönüşüm
    const *ptr = (char*)&x;
    ```
    - **target type**, parantez tokenının içinde kullanılıyor.

    - risklerine göre hata yapılacabilecek yerler:
        - bir nesne adresini farklı türden nesne adresi olarak kullanmak
        - const nesne adresini (const T*) const olmayan nesne adresi olarak kullanmak.
        ```c
        const int x = 5;
        const int* cp = &x;
        int* ptr = (int*)cp;
        *ptr = 456; // UB
        ```
        - diğer dönüşümler
        ```c
        // UB: type punning
        float f = 45.32;
        int* ptr = (int*)&f;
        *ptr = 0;
        ```

- Aşağıdaki dönüşümler UB değil:
    - farklı türden adreslerden şu türlere yapılan dönüşümler
        - char *
        - unsigned char *
        - signed char *
    - aynı tam sayı türünün işaretli ve işaretsizi arasındaki dönüşümler.
        - int* -> unsigned int*
    - yapı nesnelerinin kendi adresleri ile yapının ilk elemanlarının adresleri arasındaki dönüşümler.
    ```c
    struct Point{int x, y, z;};

    Point p{2,3,6};
    int *iptr = (int*)&p;
    ```

- C++ Tür Dönüştürme Operatörleri Avantajları
    - Farklı amaçlarla yapılan tür dönüşümleri farklı operatörler ile yapılsın
    - keywordler yapılsın ve keywordler ile armaa yapılsın ve hatalatı kolay bulup kontrol edebilelim.

- C++ Tür Dönüştürme Operatörleri
```cpp
static_cast<int>

const_cast<int*>

reinterpret_cast<char*>

// inheritance (kalıtım)
dynamic_cast<Mercedes*>
```

- static_cast
    - aritmetic türler arasındaki dönüşümler için.
    - enum türleri de dahil.
    ```cpp
    // int -> double
    int x = 4;
    int y = 5;

    static_cast<double>(x) / y;
    ```
    ```cpp
    // enum -> int
    // int -> enum
    enum class Color {White, Yellow, Red, Brown, Blue, Black};

    Color my_color;
    int x{};

    x = static_cast<int>(my_color);

    Color other_color = static_cast<Color>(x);
    ```
    ```cpp
    // void* -> T*
    #include <cstdlib> // malloc

    int n = 10;
    int *ptr = static_cast<int*>(malloc(n*sizeof(int)));
    ```

- const_cast
    - const türlerden const olmayan türlere dönüşüm.
    ```cpp
    // const T* -> T*
    int x = 12;
    const int* cptr = &x;

    int *iptr = const_cast<int*>(cptr);
    ```

- reinterpret_cast
    - farklı adres türleri arasındaki dönüşüm
    ```cpp
    // int* -> unsigned int*
    int x = 12;

    unsigned int* uptr = reinterpret_cast<unsigned int*>(&x);

    reinterpret_cast<char*>(&x);
    ```

- Birden fazla operatör kullanma
```cpp
int x = 12;
const int* ptr = &x;

// ptr -> char*

// 
char* cptr = const_cast<char*>(reinterpret_cast<const char*>(ptr));
// ya da
char* cptr = reinterpret_cast<char*>(const_cast<int*>(ptr));
```

- volatile'dan volatile olamayan türlere dönüşüm
```cpp
volatile int x = 12;

int* ptr = const_cast<int*>(&x);
```
---

## Type Deduction (Tür Çıkarımı)

- C Dilinde türün kendisini yazmak zorundayız.

- Öyle bağlamlar vark i bir türü açıkça yazmadan derleyici dilin kurallarına dayanarak hangi türün kullanıldığını kendisi anlıyor. Bu mekanizmaya **type deduction** deniliyor.

- Compile time'a yönelik bir mekanizma.

- DİKKAT: auto keywordünün C++ dilindeki anlamı C dilindeki anlamından farklı.

- Araçlar
    - auto
    - decltype
    - decltype(auto)

### auto type deduction

```cpp
auto x = expr;
```

- değişkenin bir initializerı olması gerekiyor. Default initialization kullanılamaz. Diğer türlü çıkarım yapamaz.

```cpp
auto x; // ERROR
```

- Çıkarım auto için yapılıyor.

- yazması karmaşık türlerin yerine kullanılması kodun anlamını değiştirmesini ve hataları engellerken kullanım kolaylığı sağlıyor.

---

## Ek kaynaklar

- 

---

## ToDo

- [ ] ROS2 nav -> enum türleri
- [X] C and C++ -> enum
- [ ] Jason turner book -> enums
- [ ] scott meyers -> enums
- [ ] legacy code
- [ ] type punning
- [ ] const, **volatile** -> type qualifiers