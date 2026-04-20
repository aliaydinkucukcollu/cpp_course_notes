#include <stdio.h> // NULL macrosu
#include <stdlib.h>

// NULL pointer

// Why is used?
// 1 - bazı fonksiyonların işlerini yapar ve adres döndürür, yapamadığında NULL pointer döndürür
// örn: FILE* fopen(***)
//      void* malloc(size_t n)

// 2 - veri yapılarında arama yapan fonksiyonlar adres döndürür, bulamadığında NULL döndürür
// örn: strchr, strrchr, strpbrk, strstr, memchr

// 3 - parametresi pointer olan bazı fonksiyonlar, opsiyon olarak NULL döndürürler
// void foo(int*) yapısı
// örn: time_t time(time_t *) 'out param': fonksiyon outputu
//      fflush(FILE *)

// 4- bir pointer değişken, geçerli değere sahipse:
// - nesnenin adresini gösterir ya da 
// - dizinin bittiği yeri gösterir ya da
// - değeri NULL pointerdır ve hiçbir nesneyi göstermez.

int main() {

    // usage like boolen values
    // int *ptr = NULL;

    // if(???)
    // {
    //     ptr = &x;
    // }

    // if(ptr != NULL)
    // {
    //     // this code executes
    // }

    // ptr is indetermined value OR garbage value
    int *ptr;
    ptr = NULL; // preferred
    ptr = 0; // it is also legal

    // dangling pointer : bir nesneyi gösteriyordu, gösterdiği nesnenin hayatı bitti
    // onu gösteren pointer hala hayatta.
    // allacote
    ptr = malloc(10);

    // codes

    // deallocate
    free(ptr);

    // dangling olmaması için NULL ptr ataması
    ptr = NULL;


    return 0;
}