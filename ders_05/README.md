# Ders-05

19 Temmuz 2026 Pazar

---

## Type Deduction

### Auto Type Deduction

- AAA (Almost Always Auto)

- auto kullanım avantajları
    - uzun değişken isimleri için kullanışlı.
    - fonksiyon geri dönüş değeri tutan bir değişken için fonksiyon geri dnüş type'ı değişse bile değişken türünü değiştirmeye gerek kalmıyor.
    ```cpp
    int foo(){ return 55; }

    auto x = foo();
    ```

#### Sabitler / Literals Recap

- Son ek içermiyorsa ve signed int sınırları içinde kalıyorsa sabitlerin türü int.
```cpp
4532 // sabitin türü int
```

- sayı sistemi ve türün ilişkisi yok
```cpp
0x1AC4 // sabitin türü: int, sayı sistemi: hex

// sabitler
0x1AC4      // hexadecimal  -> 16lık
0421        // octal        -> 8lik
63763       // decimal      -> 10luk
0b101001    // binary       -> 2lik
```

- binary (Modern C++ / C++14)
```cpp
int x = 0B1010101;
```

- digit seperator
    - sabitin yazımında basamak ayırıcı
    ```cpp
    unsigned long long l1 = 18446744073709550592ull;       // C++11
    unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14

    int x = 0xAC'D2'F4'1C;
    ```

- max int değeri
```cpp
#include <limits>
std::numeric_limits<int>::max(); // 2'147'483'647

1'193'259'147; // int
```

- örneğin:
```cpp
// ifadenin değeri -752
-752; // sabitin değeri: 752, - : sign operator minus
```

- unsigned, long, ...
```cpp
// unsigned int
752u
752U

// long
752L
752l // pek tercih edilmez, l ile 1 karışıyor.

// unsigned long
35UL
35LU
35lu

// long long
45LL
45ll

// unsigned long long
98ULL

auto x = 0U; // unsigned int

auto x = 0LL; // long long

auto val = 'A'; // char

// float
2.f
2.F

// double
2.4

// long double
3.8L

// int, hex
0x1AC4
0X1ac4

// long int
0X1ACEL

// int, octal
0212243

// unsigned int, octal
0212243

auto val = 4.; // double
auto val = 4.f; // float
auto val = 4f; // ERROR
```

- scientific notation
```cpp
scientific notation

auto val = 2.3E2; // 2.3 x 10^2

auto val = 2.3e-2; // 2.3 x 10^-2

// nokta mecburi değil
auto val = 2E2; // 2.3 x 10^2, double

auto val = 2E2F; // 2 x 10^2, float  
```

- integral promotion
    - bazı türlerin rank'i farklı
    - rank'i int'ten küçük türler bir operatörün operandı yapıldığında int'e ya da unsigned int'e dönüştürülürler.
    ```cpp
    // rank'i int'ten küçük türler
    bool
    char / signed char / unsigned char
    short / unsigned short

    int / unsigned int
    long / unsigned long
    long long / unsigned long long

    float
    double
    long double
    ```
    - örneğin:
    ```cpp
    char c = 345;
    auto x = c; // x'in türü char

    auto x = +c; // integral promotion -> int

    auto x = c + c; // integral promotion -> int

    auto x = true + true; // integral promotion -> int, 2
    ```

#### Auto Type Deduction Kuralları

- çıkarım auto için yapılıyor.
```cpp
const auto x = 23; // auto -> int
```

- adres operatörü ile oluşturulan ifadeler
```cpp
int x = 10;
auto p = &x; // int* p = &x;

const int x = 10;
auto p = &x; // const int* p = &X;

int x = 10;
const auto p = &x; // int* const p = &x; -> top level const, p'nin kendisi const
```

- const'un düşmesi
```cpp
const int x = 10;
auto y = x; // int y = x; -> const düşüyor
```

- Bir ifadenin türü referans türü olamaz.
```cpp
int x = 10;
int& r = x;
int* p = &x;

x // ifadenin türü int, x'in türü int
r // ifadenin türü int,  r'nin türü(decleration type) int&
p // ifadenin türü int*, p'nin türü int*

auto y = r; // int y = r;
```
```cpp
// const olunca da değişmiyor, const yine düşüyor!
int x = 10;
const int& r = x;
int* p = &x;

x // ifadenin türü int, x'in türü int
r // ifadenin türü int,  r'nin türü(decleration type) int&
p // ifadenin türü int*, p'nin türü int*

auto y = r; // int y = r;
```

- Özel durumlar
    - array decay
    ```cpp
    int ar[10]{};

    ar // array decay -> &ar[0]

    auto x = ar; // int* x = ar;
    ```
    - string literal
    ```cpp
    auto y = "okan"; // const char* y = "okan";
    ```
    - functions
    ```cpp
    int foo(int, int); // decleration type: int(int, int);

    // function to pointer conversion
    foo // int(*)(int, int)

    auto x = foo; // int(*)(int, int)
    auto y = &foo; // int(*)(int, int)
    ```

- auto'dan sonra L value referans declerator var ise çıkarım kuralları değişiyor.
```cpp
// bu noktada aynı
int x = 5;
auto& r = x; // int& r = x;

// 1. const düşmüyor
const int x = 5;
auto& r = x; // const int& r = x;

// 2. array decay uygulanmıyor
int ar[5]{};
auto& r = ar; // int (&r)[5] = ar;

// 2.1 string literali için de geçerli.
auto x = "naci"; // const char* x = "naci";

auto& y = "naci"; // const char(&y)[5] = "naci";

// 3. function decay olmuyor
int foo(int,int);

auto x = foo; // int (*x)(int,int) = foo;

// function referans type oluyor.
auto& y = foo; // int(&y)(int, int) = foo;
```

- auto and references
```cpp
auto x //
auto& y // L value reference
auto&& z // universal (forwarding) reference
```

- Dikkat
```cpp
auto x = 5; // int
auto y(5);  // int
auto z{4};  // int

auto k{4,5}; // ERROR

auto m = {1}; // std::initializer_list<int>
```

### decltype specifier
- decleration type
- type computation (tür hesaplattırma)
- tür gereken her yerde kullanılabilir.
- operandına göre kurallar:
    - isim(identifier) ise:
    ```cpp
    decltype(x)
    decltype(x.a)
    decltype(ptr->b)
    ```
    - ifade(expression) ise:
    ```cpp
    decltype(+x)
    decltype(x*5)
    decltype((x))
    ```
- 1. decltype operandı bir isim olduğunda
```cpp
int x = 5;
decltype(x); // int

const int x = 10;
decltype(x); // const int

// değişken tanımında kullanma
decltype(x) name;

int x = 22;
double dval = 3.4;

// fonksiyon prototipinde kullanma
decltype(x) foo(decltype(dval));

decltype(x)* foo(decltype(dval)*); // int* foo(double*);

int x = 3;
decltype(x)** ptr = nullptr; // int** ptr = nullptr;

int ar[20]{};
decltype(ar) x; // int x[20];

int x = 10;
int& y = x;
decltype(y) r; // int& r;

int&& z = 24;
decltype(z) m = 56; // int&& m = 56;

const int& k = x;
decltype(k) d = x; // const int& d = x;
```

- nokta operatörü ile oluşturulan isimler de dahil.
```cpp
struct Data
{
    int x;
    double d;
};

Data mydata;
decltype(mydata) x; // Data
decltype(mydata.x) x; // int
decltype(mydata.d) x; // double

```

- 2. decltype operandı bir ifade olduğunda
    - algoritma değişiyor.
    - ifadenin türü ne?
        - T
    - ifadenin value categorisi ne?
        - PR value  T
        - L  value  T&
        - X  value  T&&
    ```cpp
    int x = 5;
    decltype(x+2); // int

    int ar[10]{};
    decltype(ar[3]); // int&

    int x = 10;
    int* p = &x;
    decltype(*p); // int&

    int x = 24;
    decltype(x); // int
    decltype((x)); // int&
    ```
    ```cpp
    int foo();
    int& bar();
    int&& baz();

    decltype(foo()); // int
    decltype(bar()); // int&
    decltype(baz()); // int&&
    ```

- fonksiyonların geri dönüş değeri türü için auto kullanımı
    - return ifadesinden çıkarım yapılıyor.
    - tüm return ifade türleri aynı olmalı.
    ```cpp
    auto foo(){ return 1; } // int

    int ar[10]{};
    auto foo(){ return ar; } // int*
    ```
    ```cpp
    int foo(int,int);

    auto bar() // int(*)(int,int)
    {
        return foo;
    }
    ```
- sizeof, size_t, unevaluated context
```cpp
int x = 5;
auto sz = sizeof(x++); // size_t

// size_t -> type alias, derleyiciye bağlı -> unsigned

// x is still 5 int here => unevaluated context
```

```cpp
int x = 5;
int y = 0;

sizeof(x / y); // UB değil

// unevaluated context'de işlem kodu üretilmiyor bu nedenle side affect yok ve bunda dolayı UB yok!
```

```cpp
int x = 5;
decltype(x++) y = 5; // unevaluated context -> işlem kodu üretilmeyecek
// x is still 5 in here
```

```cpp
int x = 5;

decltype(x++); // int
decltype(++x); // int&
```

- C++ dilinde reference to reference olmaz ancak belirli bağlamlarda referansa referans oluşur.
    - type alias
    - decltype
    - universal reference
    ```cpp
    int x = 34;
    int& r = x;

    decltype(x) & r; // int&

    decltype(r)& m; // 
    ```
- Bu durumda **reference collapsing rules** uygulanır.
```cpp
T&          &       T&
T&          &&      T&
T&&         &       T&
T&&         &&      T&&
```

```cpp
int x = 5;
int& r = x;
int&& r2 = 10;

decltype(r)   &x; // int&
decltype(r)  &&x; // int&
decltype(r2)  &x; // int&
decltype(r2) &&x; // int&&
```

- type alias decleration with using keyword
    - C'de yok.
    ```c
    // C'de ve Modern C++'a kadar tek araç -> typedef

    typedef int* IPTR;

    // Nasıl kullanırız?
    // 1. Hangi türe eş isim verecekseniz o türden bir değişken tanımlayın.
    // 2. Bildirimin başına typedef keywordünü ekleyin.
    // 3. Değişken ismi yerine eş isim koyun.

    // example : int[20] => ar20

    // 1
    int a[20];
    // 2
    typedef int a[20];
    // 3 
    typedef int ar20[20];

    // example : int(*)(int, int)

    // 1
    int (*fp)(int,int);
    // 2
    typedef int (*fp)(int,int);
    // 3
    typedef int (*FPTR)(int,int);


    // example : int*[10] => arptr

    // 1
    int* x[10];
    // 2
    typedef int* x[10];
    // 3
    typedef int* arptr[10];
    ``` 
    - Modern C++ ile birlikte ```using``` keywordu geldi.
    ```cpp
    using iptr = int*;

    using FPTR = int(*)(int);

    using FN = int(int);

    using inta20 = int[20];

    inta20 x,y,z; // herbiri 20 elemanlı int diziler.
    // int x[20];

    inta20& r = x; // r inta20 türüne referans.
    // int(&r)[20] = x;
    ```
    - neden ```using``` eklendi?
        - typedef ile yapılan bildirimlere göre çok daha basit ve anlaşılır.
        - C'den gelen typedef bildirimi generic programlamaya uygun değil.
            - alias template

- reference collapsing with using
```cpp
using iref = int&;
using irefref = int&&;

iref  &x; // int&
iref &&x; // int&
irefref &x; // int&
irefref &&x; // int&&
```

---

## ```constexpr``` specifier
- specifier(niteleyici)
- C++11 ile eklendi
- Kapsamı yeni standardlar ile genişledi ve dolayısıyla constraintler azaldı.
- 2 kullanım çeşidi var:
    - constexpr variable
    - constexpr function

- constexpr variables
```cpp
// 1. const içeriyor, kendisi bir tür değil
constexpr int x = 5; // const int

constexpr const int x = 44; // OK ancak gerek yok

// 2. ilk değer veren ifadenin constant expression olması zorunlu.

constexpr int x = 100; // OK

int y = 20;
constexpr int x = y; // ERROR

const int x = 5; // LEGAL

int y = 5;
const int x = y; // LEGAL
```

```cpp
int foo();
const int y = foo(); // OK

int ar[y]; // ERROR

// SORU  => const bir ifadenin oluşturduğu ifadeyi constant expression kullanımı zorunlu olan bir bağlanda kullanmam geçerli mi?
// YANIT => ilk değer veren ifadeye bağlı.

// EVET
const int size = 50;
int ar[size]; // OK

// HAYIR
int foo();
const int size = foo();
int ar[size]; // OK
```



---

## Ek kaynaklar

- 

---

## ToDo

- [ ] Almost Always Auto
- [ ] Literals in C++
- [ ] scientific notation
- [ ] array decay
- [ ] function decay