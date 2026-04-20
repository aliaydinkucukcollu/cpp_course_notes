#include <stdio.h>
#include <stdlib.h>

/**
 * constant expression(sabit ifadesi) gerektiren yerler
 * 
 * - initializer of global variables
 * - dizi boyutları
 * - case label
 * - bitfield member uzunluk değerleri
 * - designated initializer
 */


 // initializer of global variables
int x = 3;
int y = x; // must be constant


// bitfield member uzunluk değerleri
int size = 4;
struct Data
{
    int x : size; // error
};

int main() {

    int item = 4;
    
    // designated initializer (c99)
    int ar[20] = { [item] = 9, [3] = 34 }; // error: 'item' const olsa dahi error
    
    return 0;
}