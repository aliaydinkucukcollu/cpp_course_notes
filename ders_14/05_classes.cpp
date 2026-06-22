#include <string>
#include <vector>

class Employee {
public:
  // copy ctor ve copy assignment yazmaya ihtiyaç yok
  // bırak derleyici yazsın.
  // çünkü STL'de bunlar handle edilmiş.
  // Kullanılan 3rd grade güvenilen kütüphaneler için de geçerli.
  //
  // sınıfımın non-static veri elemanları kaynakları gösteren handlelar
  // pointerlar değilse derleyicinin yazdığı move ctor işimizi görür.
private:
  std::string mname;
  std::string msurname;

  std::vector<double> msvec;
};

int main() { return 0; }
