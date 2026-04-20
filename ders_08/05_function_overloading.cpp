// özel durumlar

// const olmayan fonksiyonlar için
void foo(int*);

// const fonksiyonlar
void foo(const int*); // const overloading

int main()
{
    const int kx = 10;
    foo(&kx); // void foo(const int*);

    int x = 4;
    foo(&x); // void foo(int*);

    return 0;
}