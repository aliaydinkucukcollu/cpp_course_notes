#include <iostream>

int main() {

    using namespace std;

    int x = 5;
    int y = 10;

    double d = 3.4;

    cout << x << y << d;

    cout.operator<<(x).operator<<(y).operator<<(d);

    return 0;
}
