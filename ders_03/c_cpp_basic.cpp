#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int arr[10];

// returns int* (int nesne adresi)
int* foo()
{
    return arr; // legal, "return ar == return &ar[0]"
    // return &ar; // illegal
}

// int (*fuz())[10]; yerine aşağıdaki gibi kullanım mümkün

typedef int inta10[10]; // tür eş isim bildirimi : int[10]

inta10 *bar()
{
    // fonksiyonun geri dönüş değerinin dizinin kendi adresi olmasını istiyorsak
    return &arr;
}

typedef int (*inta10ptr)[10];

inta10ptr fuz()
{
    return &arr;
}

int main() {
    // ar değişkeninin türü(dizinin türü) yani decleration type: int[10]
    int ar[10] = {0,1,2,3,4,5,6,7,8,9};

    int* ptr = ar; // legal
    // *ptr ==> ptr'nin gösterdiği tür int

    std::cout << "ptr: " << ptr << '\n';
    std::cout << "ar : " << ar << '\n';

    int (*p)[10] = &ar; // legal
    // *p ==> dizinin kendisini gösteriyor
    // yani *p ile ar aynı aynlamda

    std::cout << " *p: " << *p << '\n';
    std::cout << "&ar: " << &ar << '\n';

    // ar ==> int*
    // ar ifadesinin türü: int*
    // ar in C: lvalue, modifiable lvalue

    // &ar ==> int(*)[10]
    // &ar ifadesinin türü: int(*)[10]

    // int *p = &ar;
    // ERROR : Cannot initialize a variable of type 'int *' with an rvalue of type 'int (*)[10]'

    // eğer ar değişkeninin ismini bir ifade içinde kullanırsak:
    // "array decay" OR "array to pointer conversion" : diziden adrese dönüşüm
    // geçerli olur.

    // yani diznin ilk elemanının adresine dönüşüm olur.

    // ar ==> &ar[0]

    std::cout << ar << std::endl; // 0x7ffe3acc07b0
    std::cout << &ar << std::endl; // 0x7ffe3acc07b0

    // lvalue check: & operatorü ile kullanılabiliyorsa lvalue oluyor.
    // ar bu nedenle lvalue.

    const int x = 5;
    std::cout << &x << std::endl;
    

    return 0;
}