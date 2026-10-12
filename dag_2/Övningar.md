# Övningar dag 2 - typer, inmatning och felhantering

Du ska skriva ett konsolprogram som läser mätvärden och visar om ett larm ska aktiveras. Arbeta i ordningen A-C. Varje steg ska fungera innan du går vidare. Dessa är träningsövningar, inte en examinerande inlämning.

Du gör övningarna självständigt och skriver din egen kod. När du är klar visar du helst resultatet för en klasskamrat och förklarar hur du har löst uppgiften. Om ingen klasskamrat är tillgänglig går du själv igenom samma kontroller och antecknar dina observationer.

## Start

Skapa en egen mapp `dag_2/labb` med `main.cpp` och `CMakeLists.txt`. Använd byggfilen från dag 1 som mall, byt målnamnet till `lab2` och behåll C++23. Skriv egen kod; använd [delmomentsexemplen](Kodguide.md) för att förstå en konstruktion du har fastnat på.

Kör från labbmappen:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/lab2.exe
```


Du ska själv kunna förklara din kod. Fördjupning görs först när basen fungerar.

## A - välj typer och förklara divisionen

1. Skapa variabler för sensor-ID, sensornamn, mätvärde och larmstatus. Använd heltal för ID, `std::string` för namn, `double` för mätvärde och `bool` för status. Initiera samtliga.
2. Skriv ut variablerna. Visa status som `true`/`false` med `std::boolalpha`.
3. Skapa `int total{5}` och `int count{2}`. Skriv ut `total / count` och därefter `static_cast<double>(total) / count`.
4. Kontrollera `count == 0` före division. Prova genom att ändra count till 0 och bygg om.
5. Lägg till en `constexpr` övre gräns 100. Försök ändra den och notera kompileringsfelet; återställ därefter raden så att bygget fungerar.

**Klart när:** variablerna skrivs ut korrekt, divisionerna ger 2 respektive 2.5, nollantal hanteras och du kan förklara `auto`, `const` och `constexpr` med hjälp av [initialiseringsexemplet](02_initialization.cpp). `sizeof(int)` får variera mellan plattformar.

## B - läs en hel rad och hantera fel

Gör först en liten I/O-provkörning, sedan programmets mätvärdesloop:

1. Läs ett sensor-ID med `std::cin >> sensorId`. Kontrollera om läsningen lyckas; skriv annars fel på `std::cerr` och avsluta.
2. Läs därefter ett sensornamn med `std::getline`. Hantera kvarvarande radslut mellan `>>` och `getline`. Prova namnet `Sensor i köket` och kontrollera att hela namnet följer med. Spara denna variant som `io_demo.cpp` innan du fortsätter; den behöver inte ingå i mätprogrammet.
3. I `main.cpp`: läs nu mätvärden med `std::getline` i en loop. Använd en separat `std::istringstream` för varje rad.
4. Acceptera exakt ett heltal på raden. Avvisa bokstäver, extra text, två tal och tom rad. Blanksteg runt talet är tillåtna.
5. Skriv `Parsed: <värde>` för en lyckad läsning. Skriv `Enter one integer` på `std::cerr` vid tolkningsfel och fortsätt med nästa rad.
6. Raden `q` avslutar. EOF ska också avsluta utan upprepade fel. På MSYS2 brukar Ctrl+D på en tom rad ge EOF; testa också med en indatafil om tangentkombinationen inte fungerar i din terminal.

**Klart när:** följande följd fungerar utan omstart:

```text
abc
42
12abc
12 13
 7
q
```

Förväntat: fel, Parsed 42, fel, fel, Parsed 7, avslut. Här kontrolleras bara formatet; negativa heltal får ännu läsas. Se [I/O](04_console_io.cpp) och [radtolkning](07_line_parsing.cpp).

## C - skilj tolkningsfel från intervallfel

Utöka loopen från B:

1. Endast värden 0-100 är giltiga. När ett tolkat heltal ligger utanför intervallet: kasta `std::out_of_range` med ett begripligt meddelande.
2. Fånga undantaget med `catch (const std::out_of_range& error)`. Skriv `error.what()` på `std::cerr`. Nästa rad ska fortfarande kunna behandlas.
3. För giltiga värden: skriv `Alarm` när värdet är minst 80 och `Normal` annars.
4. Använd `if`/`else` för klassificeringen så att gränsen är tydlig. Ingen klass eller egen funktion krävs idag.
5. Kör tabellen nedan och notera faktiskt resultat.

| Indata | Förväntat |
|---|---|
| `0`, `79` | Normal |
| `80`, `100` | Alarm |
| `-1`, `101` | Intervallfel, programmet fortsätter |
| `abc`, `12abc`, `12 13`, tom rad | Tolkningsfel, programmet fortsätter |
| ` 42 ` | Normal |
| Ett heltal för stort för int | Tolkningsfel |
| `q`, EOF | Avslut |

**Klart när:** ett fel kan följas av ett giltigt värde och 80 ger Alarm. [Undantagsexemplet](08_exceptions.cpp) visar mekanismen utan inmatningskod.

## Fördjupning - välj en

- **Statistik:** räkna giltiga värden, summera dem och visa medelvärdet vid avslut. Ogiltiga rader räknas inte. Vid noll giltiga värden skriv ”Inga mätvärden” i stället för att dividera med noll. Välj en summa som klarar dina testdata.
- **Kontrollstrukturer:** skriv ett separat litet program som skriver 0-4 med `for`, 3-1 med `while` och kör en `do-while` minst en gång. Lägg till `continue` för att hoppa över 1 och `break` för att avsluta vid 4. Förklara skillnaden. Använd en `switch` för kommandona `s` och `q` med ett `default` för okänt kommando.

## Lösningsförslag till delövningarna

Jämför efter ditt eget försök. Filerna visar möjliga lösningar och tekniker; anpassa namn och utskrift till deluppgiftens krav. Det finns fler giltiga lösningar.

| Del | Förslag att jämföra med |
|---|---|
| A | 01_types.cpp, 02_initialization.cpp och 03_division.cpp |
| B | 04_console_io.cpp och 07_line_parsing.cpp; anpassa namnen i I/O-demon |
| C | 08_exceptions.cpp och 07_line_parsing.cpp |
| Statistik | [extra_statistics.cpp](extra_statistics.cpp) |
| Kontrollstrukturer | 05_conditions.cpp och 06_loops.cpp |

## Avslutningsövning - återskapa main.cpp

Läs beskrivningen nedan utan att först öppna main.cpp. Skriv en egen fil och kontrollera beteendet.

Skriv ett konsolprogram som läser en hel rad i taget. En rad med exakt ett heltal och eventuella omgivande blanksteg tolkas. q eller EOF avslutar. Bokstäver, extra text, två tal och tom rad ger formatfel på stderr och nästa rad kan läsas. Ett tolkat tal utanför 0-100 ger ett typat undantag, som fångas och rapporteras. Giltiga värden minst 80 ger Alarm, andra Normal. Ingen statistik krävs i slutuppgiften.

**Testa:** 0/79 → Normal, 80/100 → Alarm, abc/12abc/12 13/tom rad → formatfel, -1/101 → intervallfel, q/EOF → avslut. Kör ett fel följt av 42 för att kontrollera återhämtning.

**Klart när:** alla fallen fungerar utan omstart. main.cpp är ett lösningsförslag efter ditt eget försök.

## Visa gärna för en klasskamrat

Visa giltigt värde, formatfel följt av giltigt värde, intervallfel och avslut. Skriv fem provfall med förväntat/faktiskt resultat och en mening om skillnaden mellan tolkningsfel och domänfel. Spara mätprogrammet: det används på dag 3.
