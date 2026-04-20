#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstring>

// swap with pointers
void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// swap with reference
void swap_r(int& p1, int& p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void foo(int* p)
{
    *p = 999;
}

void bar(int& p)
{
    p = 555;
}

int g = 10;

int* buz()
{
    return &g;
}

int& bar()
{
    return g;
}

int* zort()
{
    int z_x = 66;
 
    return &z_x; // dangling pointer
}

int& fuz()
{
    int number = 44;

    return number;
}

// zort() ile fuz() aynı hataya düşüyor

int* hoo(int* ptr)
{
    *ptr *= 10;

    return ptr;
}

int& hoof(int& ref)
{
    ref *= 10;

    return ref;
}

int* get_array(size_t size)
{
    int *ptr = (int*)malloc(size * sizeof(int));

    memset(ptr, 0, size * sizeof(init));

    return ptr;
}

int main() {

    // lvalue reference değişken tanımı:
    // int& r; 

    // operator and declerator
    // int* ptr;      ---> *: declerator
    // int* ptr = &x; ---> &: operator

    // The Asterisk (*)
    int *xptr;      // *: declerator
    int x2 = *xptr; // *: operator

    // The Ampersand (&)
    int xvar = 4;
    int &ref = xvar;  // &: declarator
    int *iptr = &xvar; // &: operator

    int x = 4;
    int* p = &x;    // *: declerator, &: operator
    int** ptr = &p; // *: declerator, *: declerator, &: operator

    **ptr = 9; // **: operator, **: operator

    int ar[10];     // declerator
    int *pa[20];    // declerator
    int m[10][20];  // declerator

    // followings are operators
    // *ar
    // ar[3]
    // *pa
    // *pa[3]

    int xx = 4;

    int &r = xx; // r: reference değişken, decleration type: int&

    // the type of the variable  : int&, double&, Data&
    // the type of the expression: cannot be reference

    // references must be initialize!
    // referans değişkenler default initialize edilemez.
    // örn: int &ref; // ill-formed

    // lvalue reference' a ilk değer veren ifade lvalue expression olmalı!
    int a = 4;
    int &aref = a;

    // int &numref = 10;
    // invalid code : 10 is not lvalue ecpression

    // references are not rebinda ble

    int var = 10;
    int var2 = 20;
    int *var_ptr = &var;
    int*& rp = var_ptr; // var_ptr'ye bağlı referans değişken 

    *rp = 85;

    std::cout << var << '\n'; // 85

    // örn: 
    int** nptr = nullptr;
    int**& rp_null = nptr;

    // diziler
    int arr[10] = {00, 11, 22, 33, 44, 55, 66, 77, 88, 99};

    int (*parr)[10] = &arr; // *parr == arr
    std::cout << (*parr)[4] << std::endl; // 44

    int (&ref_arr)[10] = arr; // ref_arr == arr
    std::cout << ref_arr[4] << std::endl; // 44

    int xxx = 10;

    std::cout << "xxx: " << xxx << std::endl;

    foo(&xxx); // call by pointer  
    std::cout << "xxx: " << xxx << std::endl;

    bar(xxx); // call by reference
    std::cout << "xxx: " << xxx << std::endl;

    int *buz_ptr = buz();
    std::cout << "g: " << g << '\n';

    *buz_ptr = 9864;
    std::cout << "g: " << g << '\n';

    bar() = 2222;
    std::cout << "g: " << g << '\n';

    int& result = bar();
    result = 888;

    std::cout << "g: " << g << '\n';

    int* zort_ptr = zort();
    std::cout << *zort_ptr << '\n'; // UB!

    int value = 18;

    int *res_ptr = hoo(&value);

    ++*res_ptr;

    std::cout << "value: " << value << std::endl;

    int ref_value = 18;

    int& ref_result = hoof(ref_value);

    ++ref_result;

    std::cout << "ref_result: " << ref_result << std::endl;


    int intvar = 10;
    int& rrr1 = intvar;
    int& rrr2 = rrr1;
    int& rrr3 = rrr2;

    ++rrr1;
    ++rrr2;
    ++rrr3;

    std::cout << intvar << std::endl;

    int aa = 10;
    int bb = 98;
    int *aa_ptr = &aa;
    int*& reff = aa_ptr;
    reff = &bb;

    ++*aa_ptr;

    std::cout << bb << std::endl;

    // dinamik ömürlü nesne döndüren fonksiyonlar
    int* dinamic_ptr = get_array(100);
    // code
    free(dinamic_ptr);

    return 0;
}