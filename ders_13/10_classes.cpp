// copy consructor
// -> bir sınıfın copy constructorı her zaman vardır.
//    -> ya user declerad
//    -> ya implicitly decleared

class Nec {};

int main() {
  Nec n1;

  // copy consructor çağrılır her biri için
  Nec n2 = n1;

  Nec n3(n1);

  Nec n4{n1};

  auto n5(n1);
}
