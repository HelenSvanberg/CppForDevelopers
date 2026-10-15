# Kodguide dag 4

Öppna ett delmoment i taget. Varje numrerad cpp-fil är ett eget litet program med en egen `main`. `main.cpp` är kvar som sammanhängande exempel. Bygg inte alla cpp-filer tillsammans med `g++ *.cpp`, eftersom flera av dem har varsin startpunkt.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_procedural.cpp](01_procedural.cpp) | Procedurell variant och publik data | true; ogiltig tröskel -1 kan skapas |
| [02_objects.cpp](02_objects.cpp) | Klasser, objekt, privat data och medlemsfunktioner | 80/90; värdet 85 ger true/false |
| [03_constructor.cpp](03_constructor.cpp) | Konstruktor, initialisering och misslyckad konstruktion | 80 skapas; -1 ger fångat undantag |
| [04_invariant.cpp](04_invariant.cpp) | Setter, validering före ändring och invariant | 90 både före och efter avvisad ändring |
| [05_const.cpp](05_const.cpp) | Const-objekt och const-metoder | Threshold 80; alarm true |
| [06_copy_lifetime.cpp](06_copy_lifetime.cpp) | Kopiering och automatisk livstid | Original 80, kopia 90; original 80 efter blocket |
| [Sensor.hpp](Sensor.hpp) | Klassgränssnitt och header | Privat tröskel, publika operationer |
| [Sensor.cpp](Sensor.cpp) | Separat klassimplementation | Giltigt tillstånd skyddas i konstruktor/setter |
| [main.cpp](main.cpp) | Avslutning: sammanhängande objektdemo | Två objekt, avvisad ändring och oberoende kopia |
| [extra_rectangle.cpp](extra_rectangle.cpp) | Lösningsförslag till Rectangle-fördjupningen | Area 12; avvisade ändringar bevarar båda måtten |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_4, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day4_01_procedural.exe
```

Körfilen för ett numrerat exempel heter `day4_` följt av filnamnet utan `.cpp`, exempelvis `day4_01_procedural.exe`. Det sammanhängande exemplet heter `day4.exe`. På Linux/macOS saknar CMake-körfiler normalt `.exe`.

För att bygga bara ett exempel:

```sh
cmake --build build --target day4_01_procedural
```

Avkommentera rader med avsiktliga fel först när du vill studera just det felet. Förutsäg utskriften, kör, ändra en sak och kör igen. stdout och stderr kan visas i olika ordning vid omdirigering; jämför dem separat.


## Gör egna övningar

Övningsbladet Övningar.md finns i samma exempel-mapp. Ditt eget arbete görs i en separat labbmapp.

main.cpp är nu uttryckligen lösningsförslag till övningsbladets avslutande uppgift. Skriv själv från beskrivningen innan du jämför. Förslag till övriga delövningar finns i Övningar.md.
