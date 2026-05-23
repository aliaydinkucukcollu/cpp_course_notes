#include <iostream>
#include <string>

class Fighter
{
    public:
        void attack()
        {
            ++debug_call_count;
            // ...
        }

        std::string name() const
        {
            ++debug_call_count;
            // ...
        }

    private:
        // derleyiciye şunu bildiriyoruz:
        // -> bu eleman sınıf nesnesinin problem domaininde temsil ettiği değerle ilgili değil.
        // yani budeğerin değişmesi ya da değişmemesi sınıf nesnesinin problem domainindeki değerini etkilemiyor.
        // -> const member functions için kontrol etmiyor, geçerli sayıcak.
        mutable int debug_call_count;
};

int main() {

    return 0;
}