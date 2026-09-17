# Ders-03

12 Temmuz 2026 Pazar

---

## Initialization Biçimleri

- Initialization in C++
```cpp
// default initialization
int x;

// direct initialization
int x(12);

// uniform initialization
// brace initialization
int x{44};

// solves most vexing parse
```
- most vexing parse example
```cpp
class B{};

class A{
public:
    A(B);
};

A ax(B());
// modern derleyiciler uyarı veriyor, vermek zorunda değil.

// SOLUTION
A ax{B()};
```

- value initialization
```cpp
int x{}; // ilk olarak zero initialization uygulanıyor

int x; // garbage value

int y{}; // y = 0
```

- garbage value
    - community terimi
    - çöp değer demek
    - standard: indetermined value
    - değişkenin yerleştirildiği adreste en son çalışan programın bıraktığı byte değeri var.
    Biz değer vermezsek bu bytelar ile kullanılıyor.
    Garbage value kullanmak UB.

## Type deduction (Tür çıkarımı)

- C'de yok.
- değişkenin türünü yazmasak da derleyici koda bakarak anlıyor.
- farklı araçlar var.
    - auto
    - decltype
    - decltype(auto)

```cpp
auto x = 'A'; // char
```

## NULL pointer

- C'de NULL pointer
    - geçerli bir address (a valid pointer) ancak hiçbir nesnenin adresi değil.
    - dereference etmek UB.
    - kullanım senaryoları:
        - pointer değişkenin 2 farklı state'i
            - NULL pointer ya da değil
        - adress döndüren fonksiyonlar, başarısız oldukları zaman NULL pointer döndürüyor.
            ```c
            int *foo();
            ```
            - malloc
                ```c
                void *malloc(size_t b);
                ```
            - fopen
                ```c
                FILE* fopen(const char* filename, const char* openmode);
                ```
            - calloc
        - Adres isteyen fonksiyonlar
            - NULL pointer bir opsiyon olarak sunuyor.
        ```c
        void foo(T *);
        
        time_t time(time_t *);

        int fflush(FILE*);
        ```
        - veri yapılarında arama yapan fonksiyonlar
        ```c
        strchr
        strrchr
        strstr
        strpbrk
        memchr
        ```
- Macro kullanılıypr
```c
#include <stdio.h> // NULL
int *p = NULL; // NULL bir macro
```
- NULL pointer conversion
```c
int *p = 0; // tavsiye edilmiyor
p = 0;
```
- Macro kullanımı tercih edilmiyor çok, sakıncalı.

- Modern C++ ile birlikte **nullptr** geldi.
Eski kurallar geçerli ama kullanmak sakıncalı.
```cpp
int *p = nullptr;

double dx{};
double *dptr = &dx;

dptr = nullptr;
```

- nullptr sabitinin bir türü vardır. Bu tür **nullptr_t**.
    - herhangibir pointera atanabilir. Ancak sadece pointer türlerine.
    - nullptr'ı dereference etmek tanımsız davranış.

```cpp
auto x = nullptr; // std::nullptr_t

int* p = 0;

// aşağıdakiler aynı anlamda
if(p == nullptr)
{

}

if(!p)
{

}
```

- ifadeler(expression)
    - data type of an expression
    - value category of an expression
        - her ifadenin bir value categorisi var.
     
```cpp
// example expressions
a + b
x > y
x
1234
nullptr
```

- C'de expressions
```c
// in C
// L value OR R value

int x = 12; // L value
int ar[10]{};
ar[3]; // L value

int *ptr = &x;
*ptr; // L value

x + 3; // R value
```

- address of operatörünün operandı olabiliyorsa L value aksi halde R value olur.
```c
&(x+5); // ERROR -> R value
```

- Bir ifadenin value categorisi önemi bu ifadenin kullanıldığı bağlamda geçerli ya da değil buna bağlı.

    - Öyle bağlamlar var ki L value kullılması gerekiyor.
    - Bazı yerlerde is ifadenin value categorisi ne olacağını belirliyor.

- Modern C++' a kadar value category C dili gibi R value ve L value seçenekleri vardı.

- Örnekler
 ```c
int x = 5;

x + 3 = 56; // ERROR -> atama operatörünün sol operandı L value olması lazım.

++(x+3); // ERROR -> prefix increment operatörünün operandı L value olması lazım.
 ```

- Modern C++ Value categories
    - Primary Value Categories
        - PR Value (Pure R Value)
        - L Value  (Left Value)
        - X Value  (Expiring Value)
    - Combined Value Categories
        - PR value ya da X value -------> R value
        - L  value ya da X value -------> GL value

- Değişken isimlerinin oluşturduğu ifadeler her zaman => **L value**.
```cpp
int x = 10;

x; // L value

// atama operatörü ile oluşturulan ifadeler L value'dür.
x = 56; // L value
```

- Aşağıdaki operatörlerle oluşturulan ifadeler her zaman => **L value**
```cpp
*ptr    // dereference operatörü
ar[3]   // subscript operatörü
++x     // prefix ++ operatörü
--y     // prefix -- operatörü
```

- string literalleri => L value
```cpp
"murathan" // L value
```

- PR value
    - sabitler
    - nullptr
    ```cpp
    190         // PR value
    nullptr     // PR value
    &x          // PR value
    x + 12      // PR value
    x > y       // PR value
    x && y      // PR value
    +x          // PR value
    -x          // PR value
    x++         // PR value
    x--         // PR value
    ```

- fonksiyon çağrı ifadeleri => PR Value
```cpp
int foo();

foo(); // PR value
```

- X value örnekler

```cpp
int&& bar();

bar(); // X Value
```

## Reference Semantics

- C++'da pointerlara alternatif olarak referans semantiği var.

- Modern C++ öncesinde referens denilince L value reference anlamına geliyordu.

- Modern C++ ile birlikte reference demek yeterli kalmıyor.
    - L value reference
    - R value reference
    - Forwarding reference (universal reference)

- Referans semantiği dil katmanında bir araç.
    - Assembly tarafında geçerli değil. Sadece dilin aracı.

- Neden reference semantiği?
    - C'deki pointerlar C++'daki bazı araçalra uyum sağlamıyor.
        - örneğin:
            - operatör overloading
    - Reference semantiğini kullanmak daha kolay olabilir.

    - assembly düzeyinde pointer semantiği ile referans semantiği arasında hiçbir fark yok.

```cpp
int x = 12;
int& r = x; // artık r demek x demek

r = 34; // x = 34
++r; // x = 35

// ptr points to x
int *ptr = &x;

(*ptr) = 45; // x = 45
```

- Kurallar:
    - L value referanslarda declerator olarak & kullanılıyor.
    ```cpp
    int &r = x; // address of decleratorü => L value reference

    &r // address of operatörü
    ```
    - referans değişkenler default initialize edilemezler.
    ```cpp
    int &r; // ERROR
    ```
    - L value reference değişkenlere ilk değer veren ifadenin L value olması gerekiyor.
    ```cpp
    int& r = 10; // ERROR

    int& r = x++; // ERROR

    int& r = ++x; // OK
    ```
    - binding
    ```cpp
    int x{};
    int&r = x; // r binds to x
    ```
    - referans değişken bağlandıktan sonra başka bir değişkene bağlanamaz. Yani referanslar re-bindable değil.
    ```cpp
    int x{};
    int y = 5;

    int& r = x;

    r = y; // x = y demek
    ```
    - Referencelar için örtülü dönüşüm yok.
    ```cpp
    int x{12};
    double& r = x; // ERROR
    ```
    - ilk değer verme
    ```cpp
    int x{42};

    int& r = x; // LEGAL
    int& r(x); // LEGAL
    int& r{x}; // LEGAL
    ```
    - Bir ifadenin türü bir referans olamaz.
    ```cpp
    int x{};
    int& r = x; // r -> int&
    int *ptr = &x; // ptr -> int*

    p // data type -> int*

    // Bir ifadenin türü bir referans olamaz.
    r // data type -> int
    ```
    - pointer değikene referans
    ```cpp
    int x{22};
    iny y{34};
    int *ptr = &x;

    // r ptr'ye bağlanan bir referans
    int*& r = ptr;

    *r = 36; // *ptr = 36;
    r = &y; // ptr = &y;
    ```

## L value referanslar kullanımı

- 1. Fonksiyon parametreleri
```cpp
// pointer sematics swap function
void iswap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// referans semantics swap function
// call by reference
void rswap(int& r1, int& r2)
{
    int temp = r1;
    r1 = r2;
    r2 = temp;
}
```

[Comparison of C++ and Assembly codes for pointer and referans semantics](https://godbolt.org/z/vWq7bKenM)

- zorunda olmadıkça referans semantiği kullanıyoruz.

- Pointer kullanmak durumunda kaldığımız durumlar:
    - nullpointer gibi bir araçtan yararlanma durumunda pointer semantiği kullanmak gerekebilir.

- 2. Geri dönüş değeri referans olan fonksiyonlar

```c
// Adres döndüren fonksiyonlar
int g = 5;

int *foo()
{
    return &g;
}

int* p = foo();

*p = 100; // g = 100;

*foo() = 777; // g = 777;
```

```cpp
// Reference döndüren fonksiyonlar
int g = 5;

int& foo()
{
    return g;
}

foo() = 999; // g = 999;
++foo(); // g = 1000;
```

- Adres döndüren bir fonksiyon asla otomotik ömürlü bir nesne adresi döndürmemeli.
    - statik ömürlü nesne adresi
        - global değişken adresi
        - statik yerel değişken adresi
        - string literali
    - dinamik ömürlü nesne adresi
    - çağrılan koddan aldığı nesne adresini döndürmek
```cpp
// undefined behaviour
// BAD
int *foo()
{
    int x = 5;
    return &x;
}

int* p= foo(); // UB

// GOOD
int g = 120;
int *foo()
{
    static int x = 5;

    if(g > 10)
        return &g;
    else    
        return &x;
}
```

```c
int *foo(int* p)
{
    *p *= 2;
    return p;
}

int x = 46;
int* ptr = foo(&x);
++*ptr; // 93
```

- Aynı şekilde; reference döndüren bir foksiyon otomatik ömürlü bir nesneye referans döndürmemeli.

```cpp
// Undefined Behaviour
int& bar()
{
    int x = 5;
    return x;
}
```

```cpp
// çağrılan koddan aldığı nesne referansını döndürmek
int& foo(int& r)
{
    r *= 2;
    return r;
}

int x = 13;
++foo(x); // 27
```

- RECAP: increment
    - postfix increment
        ```cpp
        x++;
        x--;
        ```
    - prefix increment
        ```cpp
        ++x;
        --x;
        ```

## Referans semantiği ve const doğruluğu

- pointer semantic interface
```cpp
void foo(Date*); // mutator
void bar(const Date*); // accessor
```

- pointer variables
```cpp
int x = 4;

// pointer to const int -> (low level const)
const int* ptr = &x;

// const pointer to int -> (top level const)
int* const ptr = &x;
```

- referance semantic with const
    - referanslar re-bindable olmadığı için low level ya da high level kavramları yok.
```cpp
int x = 5;
int&r = x;

// const L value reference
const int& r = x;

// r üzerinden x'i sadece okuma amaçlı erişebiliriz.
```

- reference semantic interface:
```cpp
void foo(Date&); // mutator
void bar(const Date&) // accessor
```

- reference değişkenin adresi olarak kullanabileceğimiz bir adres yok. Assembly düzeyinde gizli pointer var ve biz erişemiyoruz.

- const nesneye referans oluşturmak için referansın da const olması gerekiyor.

```cpp
const int x = 4;
int& r = x; // ERROR
const int& ref = x; // OK
```

- const L value referans değişkenler hem L value hem de R value ifadelere bağlanabilirler.

```cpp
struct Date{
    int d, m, y;
};

// accepts L value only
void foo(Date&);

// accepts both const or not const R value and L value
void bar(const Date&);

Date x{1,1,1970};
const Date cx{4,3,1970};

foo(x); // OK
foo(cx); // ERROR
foo(Date{4,5,2010}); // ERROR

bar(x);// OK
foo(cx);// OK
foo(Date{4,5,2010});// OK
```

## Pointers vs References

- Pointers
    - hayatı boyunca aynı nesneyi göstermek zorunda değil.
    - default initialize edilebilir.
    - pointer to pointer var.
    - fonksiyon çağrısında call-by-value olup olmadığı anlaşılır.
    - null pointer var.

- References
    - hayatı boyunca aynı nesneyi göstermek zorunda.(re-bindable değiller)
    - default initialize edilemezler.
    - reference to reference yok.
    - fonksiyon çağrısında call-by-value olup olmasığı fonksiyoınu görmeden anlaşılamaz.
    - null reference yok.


- C++ dilinde öyle bağlamlar var ki referansa referans yok ancak bu bağlamlar oluştuğunda **reference collapsing** oluşuyor.


- dangling reference olabilir.
    - otomatik ömürlü lokal değişkeni döndürme.

## R value reference

- Modern C++ ile dile eklendi.

```cpp
// declerator olarak && kullanılıyor.
int &&x = 10;
```

- R value reference sadece R value ifadelere bağlanabilir.

- Eskiden yapılamayan ne vardı da şimdi bunu çözebilmek için R value reference edile eklendi?
    - move semantics
    - perfect forwarding

- Bütün referanslar için default initialization yasak.
```cpp
int &&x; // ERROR
```

- L value referans sadece L value ifadelere bağlanabilir.
- R value rfeferans sadece R value ifadelere bağlanabilir.
- const L value reference hem L valueya hem de R valueya bağlanabiliyor.

```cpp
int x = 10;

// L value reference
int& r = x;

// R value reference
int&& rref = x + 3;

// const L value reference
const int& kref = x;
const int& kref2 = x + 2;
```

- string literal and reference

```cpp
"mustafa" // const char[6]

const char(&r)[6] = "mustafa";

const char(&r2)[6] = "ali"; // ERROR

// incomplete type
const char(&r)[] = "ali";
```

## Default Arguments

- Fonksiyona kaç paramtresi varsa o kadar argüman göndermek lazım ne 1 eksik ne 1 fazla.

- Ne işe yarıyor?
    - Derleyici bildirime bakarak, bir fonksiyona eksik sayıda argüman gönderdiğimizde gönderilmeyen parametre için önceden belirlenmiş bir argümanın gönderildiğini kabul ediyor.

```cpp
void foo(int, int, int = 0);

foo(3,5,6); // OK
foo(3,5); // OK => foo(3,5,0);
```

- Sık çağrılan ve aynı değerle çağrılan parametreler için hata riskini ortadan kaldırmak ve azaltmak amacıyla, varsayılan bir argüman belirlenmesi compile time'a yönelik bir araç.

```cpp
void foo(int = 0);

foo(); // OK -> foo(0);
foo(10); // OK
```

---

## Ek kaynaklar

- 



---

## ToDo

- [ ] most vexing parse
- [ ] reference semantics
- [ ] nullptr
- [ ] value categories
- [ ] pointer to pointer
- [ ] to write code
    - pointer alan fonksiyon
    - pointer döndüren fonksiyon
    - referans alan fonksiyon
    - referans döndüren fonksiyon
- [ ] ``` #include <cstring> ```
- [ ] C -> variadic function
