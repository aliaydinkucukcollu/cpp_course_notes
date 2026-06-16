// derleyicinin yazdığı copy constructor
// -> derleyicinin yazdığı işimi görüyorsa dokunma derleyici yazsın
// -> special member function'ı kendimizin yazması için özel bir durum olmalı
// başıma iş açan vs.

// derleyicinin default ettiği copy constructor
// -> sınıfın non-static, inline(class definition içinde), public fonksiyonudur.

class Myclass {
public:
  // derleyici default copy ctor yazdı. => non-static, inline, public.
};

class Zort {
public:
  Zort();

private:
  Zort(const Zort &) = default;
};

class Hort {
public:
  Hort(const Hort &);
};

int main() {

  Zort z1;

  // Zort z2(z1); // Error : erişim kontrolü

  return 0;
}
