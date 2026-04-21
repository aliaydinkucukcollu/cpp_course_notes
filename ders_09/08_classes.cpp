// ---- Classes ----

// class types
// -> struct (C'den farklı, ektra özellikler var)
// -> class
// -> union

// class: problem domaindeki varlıklar yazılımsal domaindeki temsilleri
// - soyutlama sağlıyor

// bir sınıf için ikisi de mümkün.
// -> definition
// -> decleration (forward decleration)

class Dummy; // decleration, incomplete type

class Myclass {}; // definition, C++ için geçerli

// C++'daki scopelar
// 1-) namespace scope
// 2-) block scope
// 3-) class scope
// 4-) function scope
// 5-) function prototype scope

// class definition, complete type
class Data {
public:
  // class scope
  int x;

  // class members

  // neler class members olabilir?
  // -> data member (veri elemanı)
  //      -> static data members
  static int z;
  //      -> non-static data members
  int y;

  // -> member function (üye fonksiyon)
  //      -> non-static member function (ancak bir sınıf nesnesi için
  //      çağrılabilir.)
  void bar(int);
  //      -> static member function
  static void bar(int, int);

  // function overloading mümkün
  void foo(int);
  void foo(int, int);
  void foo(double);

  // sınıfların member functionları için function redecleration yok
  //   void zoo(int);
  //   void zoo(int);

  // -> member type / type member / nested type
  // bir struct, class, union tanımının bir diğer class içinde yapılması
};

// C++'da 2 çeşit foksiyonlar var, dil katmanında
// 1-) free function / global function / standalone function
// 2-) member function

// 1 -> member selection dot operator (mydata.x)
// 2 -> ok operatörü (member selection arraw) (ptr->x)
// 3 -> scope resolution operatörü
//  a - unary (::x)
//  b - binary (mydata::x)
// binary scope resolution operatörünün sol operandı ya namespace ya sınıf ismi
// olması lazım.

// 1.global değişken olabilir
Myclass m;

// 2. fonksiyon parametresi olabilir

// 3. statik ya da otomatik ömürlü yerel değişken olabilir
void foo() { static Myclass m2; }

// 4. dinamik ömürlü nesne olabilir

int main() {
  Myclass ar[10];
  Myclass x;
  Myclass *ptr = &x;
  Myclass &r = x;
  Myclass &&rr = Myclass{};

  return 0;
}