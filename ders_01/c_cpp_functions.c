#include "stdio.h"

// 1: implicit int (C99)

// default int
foo()
{
    return 1;
}

// implicit int for params
int sum(a, b, c)
{
    return a + b + c;
}

// 2: old style function definition
int bar(a, b, c)
int a, b; double c;
{

}

// 3: function decleration with no param
void hoo(); // fonksiyonun parametre değişkenleri hakkında bilgi yok

// function prototype
void voo(void); // fonksiyonun parametre değişkeni yok

int main() {
  
    hoo(2, 4, 6); // no error

    voo(2, 4, 6); // error

    int (*fp)(); // geri dönüş değeri int olan param sayısı ne olursa olsun fonksiyonun adresini tutan func. pointer

    int (*fp2)(void); // param değişkeni olmayan bir fonksiyonun adresini tutar

    // 4: default function decleration OR implicit function decleration
    zoo(1, 3, 5);

  return 0;
}