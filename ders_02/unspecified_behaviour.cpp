#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// === Unspecified Behaviour ===

int foo();

int bar();

int main() {
    
    int x;

    x = foo() + bar() * 5; // hangi fonksiyon daha önce çağrılacak belli değil


    // Example-2: Unspecified Behaviour
    // compiler aynı ya da farklı dizi olarak tutabilir.

    const char* p1 = "hakan";
    const char* p2 = "hakan";

    if(p1==p2)
    {
        std::cout << "dogru\n";
    }
    else
    {
        std::cout << "yanlis\n";
    }

    // Example-3: Unspecified Behaviour
    // üstteki blok 'dogru' bloğuna da girse
    // alttaki kodun garantisi yok

    const char* p3 = "leyla";
    const char* p4 = "leyla";

    if(p3==p4)
    {
        std::cout << "dogru\n";
    }
    else
    {
        std::cout << "yanlis\n";
    }

    return 0;
}