#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

class String {
public:
  String(const char *p)
      : mlen(std::strlen(p)), mp(static_cast<char *>(std::malloc(mlen + 1))) {
    std::strcpy(mp, p);
  }

  String(const String &other)
      : mlen(other.mlen), mp(static_cast<char *>(std::malloc(mlen + 1))) {
    std::strcpy(mp, other.mp);
  }

  String(String &&other) : mlen(other.mlen), mp(other.mp) {
    other.mlen = 0;
    other.mp = nullptr;
  }

  String &operator=(const String &other) {
    // check self assignment
    if (this == &other) {
      return *this;
    }
    std::free(mp);

    mlen = other.mlen;

    mp = static_cast<char *>(std::malloc(mlen + 1));

    std::strcpy(mp, other.mp);

    return *this;
  }

  String &operator=(String &&other) {
    if (this == &other) {
      return *this;
    }

    std::free(mp);

    mlen = other.mlen;
    mp = other.mp;

    other.mp = nullptr;
    other.mlen = 0;

    return *this;
  }

  void reverse() {
    for (size_t i{}; i < mlen / 2; ++i) {
      std::swap(mp[i], mp[mlen - 1 - i]);
    }
  }

  void print() const { std::puts(mp); }

  ~String() {
    if (mp) {
      std::free(mp);
    }
  }

private:
  std::size_t mlen;
  char *mp;
};

void foo(String str) { str.print(); }

int main() { return 0; }
