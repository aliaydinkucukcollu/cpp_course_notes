# Ders-01 

5 Temmuz 2026 Pazar

---

## C++ Standartları

- C++98 / C++03
- Modern C++
    - C++11
    - C++14 (minor)
    - C++17
    - C++20
    - C++23
    - C++26

## Temel Terimler

-  Syntax

Dilin grameri.

- syntax hatası

```cpp
int x // ; unutulmuş
```

- constraint violation

C terminolojisinde geçersiz kod, derleyicin uyarı(diagnostic) vermesi gereken durumlar.

```c
const int x = 55;
x = 12; // geçersiz
```

- ill-formed

C++ terminolojisinde geçersiz kod, derleyicin uyarı(diagnostic) vermesi gereken durumlar.

- invalid code / geçersiz kod
- error

- dil terminolojisi
    - standard terminoloji
    - community terminolojisi (community terms)
        - Examples
            - universal reference
            - RAII
            - CRTP

---

## C in C++ Tarihi ve Farkları

- C --> C++

**Bjarne Stroustrup** Çekirdeğinde C olan ve yapılan eklemelerle
    - object oriented programming
    - generic programming
        - türden bağımsız programlama
    - data abstraction
    - multi-paradigm
özellkleri kazandırılmış bir programlama dili kazandırmak istiyor.

- C with Classes -> C++
    C++ ismi increment operatöründen geliyor.

## C++ genel karakteri

- multi-paradigm
    - procedural
    - object oriented programming
    - object based programming
    - generic programming
    - türden bağımsız programlama
    - data abstraction
    - functional programming

Dil birden fazla programlama paradigmasını bir arada kullanıma sunuyor.

- STL (Standard Template Library)

- efficiency / performance
    CPU bound

- C and C++
    - Aradaki fark açıldı.
    - C++ değişti.
    - C de değişti.

- C history
    - C89
    - C95
    - C99
        - bir kısmı C++'da yok.
    - C11

---

## Temel Terimler

- identifier (isim)
    - varlıkların isimleri
    - örneğin:
        - değişkenin ismi
        - fonksiyonun ismi
    - decleration(bildirimi) olmak zorunda.

- scope(kapsam)
    - ismin scopu denildiğinde, ismin kullanılabileceği alanı kastediyoruz.

    - kategoriler
        - C 
            - file scope
            - block scope
            - function prototype scope
            - function scope
        - C++
            - namespace scope
            - block scope
            - class scope
            - function prototype scope
            - function scope

- data type
    - değişkenleri, ifadelerin ve sabitlerin data type'ı var.
    ```cpp
    int x = 12; // x -> int
    ```

- decleration(bildirim)
    - ismin ne anlama geldiğini anlatan cümlelere denir.
    - örneğin:
        ```cpp
        // function prototype
        // function decleration
        int func(int);

        // değişken bildirimi
        int x;
        ```
- statement
    - C/C++ dilinin cümleleri
    - decleration statement
        - identifierların neyi temsil ettiğini anlatan statementlar.

- expresssion (ifade)
    - değişkenlerin, sabitlerin ya da bunların operatörlerle birleştirilmiş birimleri
    ```cpp
        x++ > 10 && y < 3; // ifade
    ```
    - data type
        - ifadelerin data type'ı var.
    - value category
        - C'de yok
        - C++'da var

- Value Category
    - C 
        - L value
            - address-of operatörün(&) operandı olabiliyorsa L valuedür.
            - ifade doğrudan bir nesneye karşılık geliyor.
            - bellekte yeri var. ve o yere adresiyle erişebiliriz.
        ```c
        int x = 5;
        x // L value

        int *ptr = &x;

        *ptr // L value

        int ar[3] = {0};
        ar[1] // L value
        ```

        - R value
            - address-of operatörün(&) operandı olamazlar.
        ```c
        int x = 5;
        
        (x+5) // R value
        ```
    - C++
        - Primary Value Categories
            - PR Value 
            - L Value
            - X Value
        - Combined Value Categories
            - PR Value ya da X Value => R Value
            - L Value ya da X Value  => GL Value

- değişkenlerin value categorisi olmaz.

- expression statement
```cpp
int x = 5; // decleration (initialization)

x = 13; // ifade (expression)

// statement (deyim) -> C++ dilinde cümle yapısı
// - expression statement
++x;

x = 3 // ifade

x = 4; // expression statement

; // null statement

```

- compound statement

```cpp
// block halinde -> compound statement
{
    ++x;
    foo(x);
    a = x + 24;
}
```

- control statement
    - C'deki kontrol değimleri
        - if
        - for
        - while
        - do while
        - switch
        - goto
        - return
        - continue
        - break
    - C++'daki kontrol değimleri
        - throw statement
        - range based for loop
        - if with initializer
        - ...

- constant expression

- scope
    - compile-time'a ilişkin bir kavram

- name lookup (isim arama)
    - ismin hangi varlığın ismi olduğunun anlaşılma süreci
```cpp
// x bir isim ancak hangi varlığın ismi
x = 5;
```


- sıralama
    - 1. name lookupü
        - aranan isim bulunamazsa hata
            - ambiguity
                - hangisini seçecek karar veremiyor
                ```cpp
                int x(int);
                int x(unsigned);

                int res = x(4.2);
                ```
    - 2. context control

- preprocessor
- preprocessor directives
- conditional compiling
```cpp
#include <iostream>
#define SIZE 100
```
- source file
    - kaynak dosya.

- translation unit

```text

┌─────────────────┐                              ┌─────────────────┐
│                 │                              │                 │
│   Source File   │                              │   Preprocessor  │ ───► translation unit
│                 │   ──────────-----────►       │                 │
└────────┬────────┘                              └────────┬────────┘
         |
   preprocessor directives                
```

## Tooling

- compiler
- linker
- debugger
- build tools
    - cmake
    - make
- profiler
- sanitizer
    - usan
- static code analyzer
    - cppcheck
    - clang tidy
    - doxygen

## Terimler Devam
- operator vs declerator

```cpp
// bildirimde kullanılıyorsa declerator
// ifade içinde kullanılıyorsa operator
int x = 10;
int ar[5] = { 0 }; // [] -> declerator
int *ptr = &x; // * -> declerator
int& r = x; // & -> declerator

ar[2]++; // [] -> operator
*ptr = 5; // * -> operator
```

- token
derleyicinin anlam biçtiği ve ayrıştırdığı

- tokenizing (lexical analysis)

- diagnostic (message)
    - constraint violation
    - ill-formed
    - invalid code
    - illegal

- No Diagnostic Required
    - ODR (One Definition Rule)
```cpp
// a.cpp
int x = 5;

// b.cpp
int x = 12;
```

Derleyiciler derledikleri kaynak dosyalar arasındaki mantıksal ilişkiden sorumlu değil. 

- compiler (derleyici)
    - kodu assembly / makine koduna çevirir.
    - örneğin:
        - C -> assembly
        - C++ -> assembly
- compilation
    - derlerme sürecinin kendisi.
- compile time
    - compiler'ın çalıştırıldığı süreç

- linker(bağlayıcı)

```text
preprocessing --> compiler time --> link time --> runtime
```

- compiler optimization
    - derleyicilerin optimizer modülü var.
    - optimizer'ın yaptığı iş compiler optimization yapıyor.
    - **ŞART** => observable değişmeeyecek.
    - derleyici yazılan kodu yazılmamış varsayabilir.
    - kodun sırasını değiştirebilir.
    - as-if rule'a tabi.

- as-if rule
    - kodun davranışta gözlenebilir bir davranış olmayacaksa kodda değişiklik yapabilir.
    - runtime'da ne gözlenecekse yine aynı şeyler gözlenecek.
    - sonuç olarak as-if rule, derleyiciye bazı insiyatifleri vberiyor ancak tek şart observable behaviour değşmiyecek şartı koşuyor.

- observable behaviour
    - gözlenebilir davranış
    - kodun gözle gözlemlenene çıktısı değşmicek.

- **undefined behaviur (tanımsız davranış) (UB)**
    - öyle kodlar var ki o kodlar dil tarafından tanımsız davranış olarak belirlenmiş ve bu durumlarda derleyici dilediği gibi kod üretebilir.
    - Dilin standardı hangi durumlar UB olduğunu belirtiyor.
    - Örneğin:
        - işaretli tamsayı türlerinde taşma
        ```cpp
        // 4 Byte'tan büyükse taşma olur -> UB
        int mean(int x, int y)
        {
            return (x+y)/2;
        }
        ```
        - zero division
        ```cpp
        int foo();
        int bar();

        int x = foo();
        int y = bar();

        x /= y; // y = 0 olabilir -> UB
        ```
        - dangling pointer
        ```cpp
        int *ptr = NULL;
        *ptr = 34; // UB
        ```
        - dizi aşımı
        ```cpp
        int ar[5] = {0};
        ar[5] = 66; // UB
        ```

    - derleyici optimizasyon yaparken 1 adet bile UB olmadığı garantisi ile işlem yapıyor.
    ```cpp
    // derleyici y = 0 olması durumunda UB olacağı için ve UB olmadığı taahhüt ettiği için control statementta always false edip kodu siler.
    x = foo();
    y = bar();
    x = a / y;

    if(y == 0) // always false
    {
        // statements
    }
    ```


- unspecified behaviour
    - kötü değil gayet doğal bir durum.
    - bundan etkilenecek kod yazmamak lazım.
    - derleyicin farklı kod üretme özgürlüğü.
    - örneğin:
    ```cpp
    int g = 20;
    int foo(void)
    {
        ++g;
        return 4;
    }
    int bar(void)
    {
        return g+3;
    }

    int x = 10;
    // ...
    // hangisi daha önce çağrılcak belli değil
    x = foo() + bar();
    ```
    - implementation defined behaviour
        - derleyiciye bağlı davranışlar
        - dökümante etmek zorunda
        - örneğin:
        ```cpp
        char x; // signed OR unsigned -> implementation defined
        signed char y;
        unsigned char z;
        ```
        - taşınabilirlik konusunda problem
            - derleyici değişimi ya da kodun başka bir yere taşınması durumunda kodun anlamı değişebilir.
        - bitwise right shift operator
        ```cpp
        a >> b
        // soldan yapılan besleme 0 ile mi 1 ile mi yapılacak
        // derleyiciye bağlı  -> implementation defined
        // 0 ile besleme -> logical feeding
        ```

- NOT
    - C'de UB olup C++'da UB olmayan durumlar var.

## C in C++

### Fonksiyonlar ile ilgili uyumsuzluklar

- C89 -> C99 farklılıkları var.
    - derleyiciler genelde uyarı verip kabul ediyor.

- implicit int(örtülü int)
```c
// implicit int (C89)
// C99'da yok
// C++ -> ERROR
foo(int x)
{
    return x * 5;
}
```

- Old-style function definition
```c
// C++'da geçerli değil
int sum(x, y)
{
    return x + y;
}

double sum(x, y)
int x, int y;
{
    return x + y;
}

```

- function params
```c
// in C
int foo(); // foo may have any parameter list
int bar(void); // no parameter variables

foo(1,4,7); // OK
bar(1,4,7); // ERROR
```

```cpp
// in C++
int foo(); // no parameter variables
int bar(void); // no parameter variables

foo(1,4,7); // ERROR
bar(1,4,7); // ERROR
```

- implicit function decleration(C89)
    - C99'da kalktı ama uyum sağlıyor derleyiciler.
```c
// implicit function decleration
// (default function decleration)

// derleyici varsayımı:
// int foo();

int x = foo(12);

// C++'da yok!
```

### Türlere ilişkin farklılılar

- static typing
    - derleyici değişkenlerin türlerini koda bakarak anlıyor.
- dynamic typing
    - derleyici değişkenlerin türleri runtime'da anlaşılıyor.

- characters
```c
// in C
'A' // character constant, int
```

```cpp
// in C++
'A' // character literals, char
```

---

## Ek kaynaklar

- [What is good C++ code? - Bjarne Stroustrup](https://www.youtube.com/live/0Fl9fhmfBYY?si=tIhOLadahRWXIvKS)



---

## ToDo

- [ ] efficiency / performance and CPU bound
- [ ] C++ standards
- [ ] Boost library
- [ ] Undefined Behaviour
- [ ] Compiler Optimization
- [ ] preprocessor
- [ ] preprocessor directives
- [ ] building a C/C++ program
- [ ] #define ...
- [ ] scott meyers books
- [ ] Anthony Williams - concurrency in C++
- [ ] [What is good C++ code? - Bjarne Stroustrup](https://www.youtube.com/live/0Fl9fhmfBYY?si=tIhOLadahRWXIvKS)
- [ ] [Software and Safety - Anthony Williams - Keynote Meeting C++ 2025
](https://youtu.be/wKGkOmpUTH8?si=tiPPHkenVOecfvAe)
