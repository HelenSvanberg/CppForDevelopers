# Övningar dag 3 - funktioner, headers och manuella kontroller

Du ska dela upp dag 2:s mätprogram så att domänreglerna kan användas och testas utan konsolen. Arbeta i ordningen A-C. Målet är tydliga ansvar, inte bara fler filer.

Du gör övningarna självständigt och skriver din egen kod. När du är klar visar du helst resultatet för en klasskamrat och förklarar hur du har löst uppgiften. Om ingen klasskamrat är tillgänglig går du själv igenom samma kontroller och antecknar dina observationer.

## Start

Kopiera ditt mätprogram till en egen `dag_3/labb`-mapp. Om du inte har en fungerande dag 2-lösning: använd [dag 2:s sammanhängande exempel](../dag_2/main.cpp) som start. Behåll originalet separat.


## A - definiera kontrakt innan implementation

1. Markera vad i dag 2-koden som är inmatning, validering/klassificering respektive utskrift.
2. Skapa namnrymden `course` och typen `enum class Status { normal, alarm };`.
3. Planera dessa funktioner och inkludera `<string>` i sensor.hpp:

```cpp
Status classify(int value, int threshold);

std::string to_text(Status status);
```

4. Skriv kontraktet: value och threshold måste vara 0-100; annars `std::out_of_range`. Resultatet är alarm när value är minst threshold. `to_text` returnerar `Normal` eller `Alarm` för typens två namngivna statusar.
5. Skriv tre anrop med förväntat resultat: `(79, 80)`, `(80, 80)` och `(85, 90)`.
6. Gör en separat provkörning med [parameterexemplet](02_parameters.cpp). Förklara varför värdeparametern inte ändrar anroparens int men en `int&` kan göra det.

**Klart när:** du kan beskriva funktionernas indata, resultat och fel utan att visa deras kroppar. Fria domänfunktioner ska inte läsa från cin eller skriva till cout.

## B - flytta reglerna till egna filer

Skapa följande struktur:

```text
labb/
    CMakeLists.txt
    main.cpp
    sensor.hpp
    sensor.cpp
```

1. Lägg enum och deklarationer i `sensor.hpp`, i `namespace course`, med include guard.
2. Lägg definitionerna i `sensor.cpp`. Inkludera dess egen header och de bibliotek som implementationen använder.
3. Låt `main.cpp` inkludera `sensor.hpp` och anropa `course::classify(value, 80)` samt `course::to_text(...)`.
4. Behåll radläsning, q/EOF och felutskrift i main. Inkludera inte `sensor.cpp` i någon fil.
5. Lägg både `main.cpp` och `sensor.cpp` i `add_executable(lab3 ...)`. Behåll C++23.
6. Konfigurera och bygg från labbmappen:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/lab3.exe
```

7. Kör samma inmatningsfall som på dag 2. Programmet ska ge samma beteende efter uppdelningen.

**Klart när:** klassificeringen går att anropa med fasta tal utan terminalinmatning och ett bygge i en ny mapp fungerar. [Modulexemplet](05_modules.cpp) visar ett minimalt anrop över filgränsen.

## C - överlagring och manuell kontroll

1. Lägg till `Status classify(int value);` i headern.
2. Implementera den genom att anropa tvåparametersvarianten med tröskel 80. Duplicera inte intervallkontrollen.
3. Ändra main till att använda enparametersvarianten.
4. Anropa funktionerna med fasta värden i ditt vanliga demonstrationsprogram eller mata in motsvarande värden via main. Skriv ut resultaten och jämför dem manuellt med tabellen.
5. Fånga out_of_range för de ogiltiga argumenten och skriv ett felmeddelande.

| Anrop | Förväntat |
|---|---|
| `classify(0)` | normal |
| `classify(79)` | normal |
| `classify(80)` | alarm |
| `classify(100)` | alarm |
| `classify(85, 90)` | normal |
| `classify(-1)`, `classify(101)` | out_of_range |
| `classify(50, -1)`, `classify(50, 101)` | out_of_range |
| `to_text(course::Status::alarm)`, `to_text(course::Status::alarm)` | Normal respektive Alarm |

**Klart när:** utskrifterna stämmer med tabellen. Ändra tillfälligt >= till >, bygg om och observera resultatet för 80. Återställ raden och kontrollera igen. Använd [exemplens byggfil](CMakeLists.txt) och [moduldemon](05_modules.cpp) som stöd.

## Kodgranskning och länkfelsövning

Kontrollera först själv, och gärna med återkoppling från en klasskamrat, att headern inte innehåller `using namespace std`, att ingen cpp-fil inkluderas och att tröskeln inte är en dold global variabel.

Ta tillfälligt bort sensor.cpp från målet lab3, konfigurera och bygg. Anteckna felkategori och en relevant felrad. Förklara varför headern inte räcker för länkning. Lägg tillbaka filen och verifiera ett lyckat bygge.

## Fördjupning

Prova även för tröskel 0 och 100, och verifiera överlagringarnas likvärdighet. Lägg också till en kort `README.md` med filernas ansvar och konfigurering/bygge/körning. Förklara varför små int-parametrar skickas som värden medan en text som bara ska läsas kan passa som const referens.

## Lösningsförslag till delövningarna

Jämför efter ditt eget försök. Filerna visar möjliga lösningar och tekniker; anpassa namn och utskrift till deluppgiftens krav. Det finns fler giltiga lösningar.

| Del | Förslag att jämföra med |
|---|---|
| A | 01_functions.cpp och 02_parameters.cpp |
| B | [sensor.hpp](sensor.hpp), [sensor.cpp](sensor.cpp) och 05_modules.cpp |
| C | [sensor.cpp](sensor.cpp), [05_modules.cpp](05_modules.cpp) och CMakeLists.txt |
| Scope/överlagring | 03_scope.cpp och 04_overloading.cpp |
| Länkfelsövning | 05_modules.cpp tillsammans med [sensor.cpp](sensor.cpp) är ett fungerande bygge |

## Avslutningsövning - återskapa main.cpp

Läs beskrivningen nedan utan att först öppna main.cpp. Skriv en egen fil och kontrollera beteendet.

Använd dina domänfunktioner i sensor.hpp/sensor.cpp och skriv en ny main.cpp. Main ska sköta samma radbaserade inmatning och felutskrift som på dag 2, men klassificering och status till text ska göras genom course::classify(value) och course::to_text. Tröskeln är 80. Ingen cpp-fil får inkluderas; länka implementationen i CMake.

**Testa:** 79 → Normal, 80 → Alarm, abc → formatfel, 101 → fångat intervallfel, sedan 42 → Normal, q/EOF → avslut.

**Klart när:** beteendet är oförändrat efter modulariseringen och ett bygge i en ny mapp fungerar. main.cpp är ett lösningsförslag efter ditt eget försök.

## Visa gärna för en klasskamrat

Visa tre filer, lyckat bygge, ett kontroll vid gränsen och ett provkörning av felväg. Anteckna för egen del: resultat från provkörningen, beskrivning av länkfelet och en egen mening om deklaration kontra definition. Spara projektet till nästa dag.
