# C++ Kurs Notları (Mart,2026) - Necati Ergin

Necati Ergin, Mart-2026 C++ Kursu Ders Notları.

## Ders Tarihleri

- [X] Ders-1  (17 Mart  2026 - Salı)
- [X] Ders-2  (19 Mart  2026 - Perşembe)
- [X] Ders-3  (24 Mart  2026 - Salı)
- [X] Ders-4  (26 Mart  2026 - Perşembe)
- [X] Ders-5  (27 Mart  2026 - Cuma)
- [X] Ders-6  (31 Mart  2026 - Salı)
- [X] Ders-7  (02 Nisan 2026 - Perşembe)
- [X] Ders-8  (03 Nisan 2026 - Cuma)
- Ders-9  (07 Nisan 2026 - Salı)
- Ders-10 (09 Nisan 2026 - Perşembe)
- Ders-11 (10 Nisan 2026 - Cuma)
- Ders-12 (14 Nisan 2026 - Salı)
- Ders-13 (17 Nisan 2026 - Cuma)

## Kod Derleme

### Clang C++ compiler

```bash
# basit kullanım
clang++ main.cpp -o program
./program

# build with C++ standards
# options: -std=c++98 -std=c++03 -std=c++11 -std=c++14 -std=c++17 -std=c++20 ...
clang++ -std=c++17 main.cpp -o program

# uyarılar hataya dönüşsün
clang++ -std=c++17 main.cpp -o program -g -Wall -Werror

# flaglerle kullanım
clang++ -O1 -g -fsanitize=undefined,address undefined_behaviour.cpp -o program
```

### GNU GCC C++ compiler

```bash
# basit kullanım
g++ main.cpp -o program
./program

# flaglerle kullanım
g++ -std=c++17 main.cpp -o program
```
