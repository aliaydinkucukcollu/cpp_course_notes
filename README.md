# C++ Kurs Notları (Mart,2026) - Necati Ergin

Necati Ergin, Mart-2026 C++ Kursu Ders Notları.

## Ders Tarihleri

- [X] Ders-1  (17 Mart    2026 - Salı)
- [X] Ders-2  (19 Mart    2026 - Perşembe)
- [X] Ders-3  (24 Mart    2026 - Salı)
- [X] Ders-4  (26 Mart    2026 - Perşembe)
- [X] Ders-5  (27 Mart    2026 - Cuma)
- [X] Ders-6  (31 Mart    2026 - Salı)
- [X] Ders-7  (02 Nisan   2026 - Perşembe)
- [X] Ders-8  (03 Nisan   2026 - Cuma)
- [X] Ders-9  (07 Nisan   2026 - Salı)
- [X] Ders-10 (09 Nisan   2026 - Perşembe)
- [X] Ders-11 (10 Nisan   2026 - Cuma)
- [X] Ders-12 (14 Nisan   2026 - Salı)
- [X] Ders-13 (17 Nisan   2026 - Cuma)
- [ ] Ders-14 (21 Nisan   2026 - Salı)
- [ ] Ders-15 (23 Nisan   2026 - Perşembe)
- [ ] Ders-16 (24 Nisan   2026 - Cuma)
- [ ] Ders-17 (28 Nisan   2026 - Salı)
- [ ] Ders-18 (30 Nisan   2026 - Perşembe)
- [ ] Ders-19 (01 Mayıs   2026 - Cuma)
- [ ] Ders-20 (05 Mayıs   2026 - Salı)
- [ ] Ders-21 (07 Mayıs   2026 - Perşembe)
- [ ] Ders-22 (12 Mayıs   2026 - Salı)
- [ ] Ders-23 (14 Mayıs   2026 - Perşembe)
- [ ] Ders-24 (15 Mayıs   2026 - Cuma)
- [ ] Ders-25 (21 Mayıs   2026 - Perşembe)
- [ ] Ders-26 (22 Mayıs   2026 - Cuma)
- [ ] Ders-27 (02 Haziran 2026 - Salı)
- [ ] Ders-28 (04 Haziran 2026 - Perşembe)
- [ ] Ders-29 (05 Haziran 2026 - Cuma)
- [ ] Ders-30 (09 Haziran 2026 - Salı)
- [ ] Ders-31 (11 Haziran 2026 - Perşembe)
- [ ] Ders-32 (12 Haziran 2026 - Cuma)
- [ ] Ders-33 (16 Haziran 2026 - Salı)


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
