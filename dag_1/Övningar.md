# Övningar dag 1 - kompilering, Make och CMake

Du ska bygga och köra ett litet C++-program, automatisera bygget och undersöka några fel. Gör delarna i ordning. Dessa är träningsövningar, inte en examinerande inlämning.

Du gör övningarna självständigt och skriver din egen kod. När du är klar visar du helst resultatet för en klasskamrat och förklarar hur du har löst uppgiften. Om ingen klasskamrat är tillgänglig går du själv igenom samma kontroller och antecknar dina observationer.

## Start

Öppna UCRT64-terminalen. Kontrollera `g++ --version`, `make --version`, `cmake --version` och `ninja --version`. Om något saknas: anteckna kommandot och felmeddelandet och be om hjälp.

Skapa en egen labbmapp. Använd exempelpaketet som stöd och behåll dess originalfiler. Be gärna en klasskamrat om återkoppling, men genomför byggstegen själv.

## A - skriv, bygg och kör

1. Skapa `main.cpp` med en main-funktion och konsolutskrift. Skriv ditt namn och två saker du vill kunna använda C++ till.
2. Bygg och kör från labbmappen:

```sh
g++ -std=c++23 -Wall -Wextra -Wpedantic main.cpp -o main.exe
./main.exe
```

3. Ändra en utskrift och spara filen. Kör main.exe utan att bygga om. Vad visas?
4. Bygg om och kör igen. Kontrollera att den nya texten visas.

**Klart när:** du kan visa din utskrift och förklara varför en ändrad källfil inte automatiskt ändrar körfilen.

## B - låt Make sköta byggstegen

1. Kopiera paketets Makefile till labbmappen. Läs dess mål, beroenden och recept. Recepten börjar med en riktig tabb.
2. Kör `make` och sedan `./main.exe`.
3. Kör make igen utan att ändra någon fil. Anteckna vad Make rapporterar.
4. Ändra utskriften i main.cpp, spara och kör make igen. Vilka kommandon behöver nu utföras?
5. Kör programmet och kontrollera den nya utskriften.

**Klart när:** du kan förklara varför ett oförändrat bygge inte behöver kompilera igen och hur Make anropar kompilatorn och länkaren.

## C - beskriv projektet med CMake

1. Skapa `CMakeLists.txt` med ett projekt för C++ och målet `lab1`, byggt från main.cpp. Använd paketets byggfil som stöd men behåll bara ditt eget programs mål. Ange C++23.
2. Konfigurera, bygg och kör:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/lab1.exe
```

3. Konfigurera också i en ny mapp och kontrollera att projektet fungerar där:

```sh
cmake -S . -B build-check -G Ninja
cmake --build build-check
./build-check/lab1.exe
```

4. Skriv en kort README.md med de tre kommandona för konfigurering, bygge och körning. Ange att de körs från mappen med CMakeLists.txt.

**Klart när:** en kurskamrat kan följa dina instruktioner och du kan förklara skillnaden mellan CMake, Ninja och kompilatorn.

## D - undersök fel

1. Öppna `main_fel1.cpp` till `main_fel4.cpp` från paketet. Förutsäg först vad som händer. Bygg sedan varje fil separat och anteckna din observation:

```sh
g++ -std=c++23 -Wall -Wextra -Wpedantic main_fel1.cpp -o fault.exe
```

2. Byt filnamnet för varje försök. Om bygget misslyckas ska du inte köra fault.exe: en gammal körfil kan finnas kvar från ett tidigare lyckat bygge.
3. Ange om problemet upptäcks vid kompilering, länkning eller först när du jämför programmets utskrift med avsikten. Spara en relevant felrad eller observerad utskrift som bevis.
4. Rätta ett fel i taget i en egen kopia. För en saknad funktionsdefinition ska du lägga till en definition, inte bara ta bort anropet.
5. Ta bort ett semikolon i ditt eget main.cpp och undersök kompileringsfelet. Återställ raden och kontrollera att programmet bygger igen.

**Klart när:** du kan visa minst ett kompileringsfel, ett länkfel och ett program som bygger men ger fel utskrift. Originalens avsiktliga fel ska finnas kvar.

## Fördjupning - två källfiler

Studera paketets 03_linking.cpp och greeting.cpp. Skapa sedan en egen message.cpp med en funktion som returnerar en hälsning. Deklarera funktionen i main.cpp och anropa den. Lägg båda cpp-filerna i CMake-målet och bygg.

Ta tillfälligt bort message.cpp från målet. Vilket byggsteg misslyckas och varför? Lägg tillbaka filen och verifiera att bygget fungerar.

## Lösningsförslag till delövningarna

Jämför efter ditt eget försök. Filerna visar möjliga lösningar och tekniker; anpassa namn och utskrift till deluppgiftens krav. Det finns fler giltiga lösningar.

| Del | Förslag att jämföra med |
|---|---|
| A | 01_hello.cpp; anpassa hälsningen till deluppgiften |
| B | Makefile och Makefile_v2 |
| C | CMakeLists.txt; behåll ditt eget mål |
| D | [losning_logik.cpp](losning_logik.cpp) för main_fel1; [losning_namn.cpp](losning_namn.cpp) för main_fel2/4; [losning_lankning.cpp](losning_lankning.cpp) för main_fel3 |
| Fördjupning | 03_linking.cpp och [greeting.cpp](greeting.cpp) |

## Avslutningsövning - återskapa main.cpp

Läs beskrivningen nedan utan att först öppna main.cpp. Skriv en egen fil och kontrollera beteendet.

Skapa ett minimalt konsolprogram med en main-funktion, iostream och en hälsning Hello World! följd av radslut. Avsluta med lyckad returstatus. Bygg och kör det först direkt med g++, sedan med CMake. Små skillnader i blanksteg i hälsningen är okej.

**Klart när:** hälsningen visas och returstatus är 0. Paketets main.cpp är ett lösningsförslag för just denna lilla slutuppgift; den behöver inte innehålla alla tidigare bygg-/felsökningsövningar.

## Visa gärna för en klasskamrat

Visa fungerande program, ett Make-bygge och ett CMake-bygge. Anteckna för egen del: dina tre bygg-/körkommandon och en mening om skillnaden mellan kompilator, länkare, Make och CMake. Om miljön ännu inte fungerar: anteckna felmeddelandet och vad du redan har kontrollerat.
