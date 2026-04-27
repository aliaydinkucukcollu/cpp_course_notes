#include <iostream>

// ---- erişim kontrolü (access control) ----
// hangi kodun erişim hakkı var hangisinin yok

// access specifiers:
// 1-) public:      herkese açık, client code erişebilir
// 2-) protected:   inheritance(kalıtım) yoluyla bir sınıf oluşturulursa
// (derived class) bu bölüme erişebilir. 3-) private:     herkese kapalı, client
// code erişemez

class Nec {
  int mval; // default private

public:
  int x;
  void foo();

private:
  void bar();

protected:
  int y; // protected until end of the scope of class
};

int main() { return 0; }