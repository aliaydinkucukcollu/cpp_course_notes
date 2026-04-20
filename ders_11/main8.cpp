#include <iostream>

// this keyword
// - this pointer
// - özel bir durum yoksa this için özel bir senaryo yok


class Myclass {
    public:
        void foo(int mx) // doğru değil
        {
            // mx = mx;
            Myclass::mx = mx;
        }
private:
  int mx, my;
};

int main() { return 0; }