#include <iostream>

class Date {
public:
  Date(int d, int m, int y) : md(d), mm(m), my(y) {}

  void print() const { std::cout << md << '-' << mm << '-' << my << '\n'; }

private:
  int md, mm, my;
};

int main() {
  Date d1(23, 4, 2026);
  Date d2(12, 12, 1998);

  d1.print();
  d2.print();

  d2 = d1; // derleyicinin yazdığı copy assignment function çağrılcak.
  // işimizi gördüğü için ona bırakıyoruz.
  // sınıf elemanı olarak pointer vs varsa o zaman kendimiz yazmalıyız.

  // derleyicinin yazdığı special member functionlara ben yazmıyım işimi
  // görüyorsa ===> Rule of 0(zero)

  d1.print();
  d2.print();

  return 0;
}
