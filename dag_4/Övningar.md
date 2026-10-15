# Övningar dag 4 - en klass som skyddar sitt tillstånd

Du ska skapa en Sensor-klass som behåller en egen larmtröskel och alltid skyddar intervallet 0-100. Jämför med fria funktioner från dag 3. Arbeta i ordningen A-C.

Du gör övningarna självständigt och skriver din egen kod. När du är klar visar du helst resultatet för en klasskamrat och förklarar hur du har löst uppgiften. Om ingen klasskamrat är tillgänglig går du själv igenom samma kontroller och antecknar dina observationer.

## Start

Skapa en egen `dag_4/labb` med CMake-projektet `lab4`. Använd byggstrukturen från dag 3 och [kodguiden](Kodguide.md) som stöd. Klassen behöver inga råa pekare, dynamiskt minne, arv eller egen destructor.


## A - visa problemet med publik data

1. Skriv en liten provfil som hanterar data och regler procedurellt med `struct SensorData { int threshold{80}; };` och en fri funktion som klassificerar ett mätvärde.
2. Skapa två datastrukturer med tröskel 80 respektive 90. Visa resultatet för värdet 85.
3. Tilldela sedan tröskeln -1 direkt. Notera att kompilatorn accepterar det trots att domänregeln bryts.
4. Skriv invarianten för den kommande klassen: ”Ett färdigkonstruerat Sensor-objekt har alltid en tröskel mellan 0 och 100.”
5. Skriv två meningar: vad är enkelt med en fri klassificeringsfunktion, och vad tillför en klass när tröskeln ska lagras över tid?

**Klart när:** du kan visa det ogiltiga tillståndet och förklara varför private behövs i just denna modell. [Procedurellt exempel](01_procedural.cpp).

## B - skapa ett giltigt objekt

Skapa `Sensor.hpp` och `Sensor.cpp`. Följ detta gränssnitt; du skriver definitionerna:

```cpp
class Sensor {
public:
    explicit Sensor(int threshold);

    int threshold() const;

    bool is_alarm(int value) const;

private:
    int threshold_;
};
```

1. Konstruktorn använder en initialiseringslista. Den kastar `std::out_of_range` för trösklar utanför 0-100.
2. Gettern returnerar tröskeln som värde. Lämna inte ut en ändringsbar referens till medlemmen.
3. `is_alarm` validerar mätvärdet 0-100 och kastar out_of_range annars. För giltigt värde returnerar den true när värdet är minst objektets tröskel.
4. I `main.cpp`: skapa `Sensor a{80}` och `Sensor b{90}`. Visa att 85 ger true respektive false.
5. Skapa ett const Sensor-objekt och visa att de läsande metoderna kan användas.
6. Lägg main.cpp och Sensor.cpp i CMake-målet lab4. Bygg och kör.

**Klart när:** två objekt kan ha olika trösklar, ogiltig konstruktion ger ett fångat undantag och anroparen inte kan ändra threshold_ direkt. [Objekt](02_objects.cpp), [konstruktor](03_constructor.cpp) och [const](05_const.cpp).

## C - bevara tillståndet vid en misslyckad ändring

1. Lägg till `void set_threshold(int threshold);` i gränssnittet.
2. Validera den nya tröskeln innan du ändrar threshold_. Vid fel: kasta out_of_range och behåll det gamla värdet.
3. Sätt tröskeln från 80 till 90. Försök sedan sätta 101, fånga undantaget och läs tröskeln igen. Den ska fortfarande vara 90.
4. Utöka ditt demonstrationsprogram med utskrifter före och efter anropen. Jämför resultaten manuellt; läs tillståndet genom gettern, inte genom privata medlemmar.
5. Prova följande fall och jämför utskriften:

| Test | Förväntat |
|---|---|
| Konstruktion med 0 och 100 | Lyckas, getter visar rätt värde |
| Konstruktion med -1 och 101 | out_of_range |
| Tröskel 80: värde 79, 80, 81 | false, true, true |
| Tröskel ändras till 90 | Getter visar 90 |
| Ändring till 101 efter det | Undantag; getter visar fortfarande 90 |
| Mätvärde -1 eller 101 | Undantag; tröskeln oförändrad |
| Kopia får tröskel 70 | Originalet behåller 90 |

Kör från labbmappen:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/lab4.exe
```

**Klart när:** du har observerat både felmeddelandet och det bevarade värdet efter en misslyckad setter. Visa också att en giltig operation fortfarande fungerar efter felet. [Invariant-exempel](04_invariant.cpp) och [kopiering/livstid](06_copy_lifetime.cpp).

## Kodgranskning

Hitta själv alla publika vägar som kan påverka tillståndet. Be gärna en klasskamrat granska din förklaring. Bevarar varje väg invarianten? Är läsande metoder const? Finns all konsol-I/O i demonstrationsprogrammet och inte inne i klassen?

Flytta tillfälligt setter-tilldelningen före valideringen. Skriv ut tröskeln efter det avvisade anropet och observera att den nu blivit felaktig. Återställ och kör igen. Detta visar varför ”ett undantag kastades” inte räcker som enda kontroll.

## Fördjupning - Rectangle

Skapa en separat Rectangle med positiva ändliga mått. Konstruktor och en metod som ändrar båda måtten ska validera båda innan någon medlem ändras. Testa area för 3×4 och att ett avvisat ändringsförsök behåller båda gamla måtten. Bestäm och dokumentera hur noll, negativa värden och icke-ändliga flyttal hanteras. Arv krävs inte.

## Lösningsförslag till delövningarna

Jämför efter ditt eget försök. Filerna visar möjliga lösningar och tekniker; anpassa namn och utskrift till deluppgiftens krav. Det finns fler giltiga lösningar.

| Del | Förslag att jämföra med |
|---|---|
| A | 01_procedural.cpp |
| B | [Sensor.hpp](Sensor.hpp), [Sensor.cpp](Sensor.cpp), 02_objects.cpp, 03_constructor.cpp och 05_const.cpp |
| C | 04_invariant.cpp, 06_copy_lifetime.cpp |
| Rectangle | [extra_rectangle.cpp](extra_rectangle.cpp) |

## Avslutningsövning - återskapa main.cpp

Läs beskrivningen nedan utan att först öppna main.cpp. Skriv en egen fil och kontrollera beteendet.

Använd din Sensor-klass eller den tillhandahållna headern/implementationen. Skapa två objekt med trösklar 80 och 90 och visa att värdet 85 ger true respektive false. Sätt det första objektets tröskel till 90. Försök ändra till 101, fånga felet och visa att tröskeln fortfarande är 90. Kopiera objektet, ändra kopians tröskel till 70 och visa att originalet är kvar på 90. Ingen terminalinmatning behövs.

**Förväntat:** true false; felmeddelande på stderr; Threshold after rejected update: 90; Original: 90; copy: 70.

**Klart när:** kopian är oberoende och misslyckad ändring lämnar originalet giltigt. main.cpp är ett lösningsförslag efter ditt eget försök. Textetiketter får skilja sig men resultaten ska vara desamma.

## Visa gärna för en klasskamrat

Visa två objekt, ett misslyckat ändringsförsök och utskrifter som stämmer. Anteckna för egen del: invarianten i en mening, fyra resultat från provkörningen och en kort jämförelse med den procedurella varianten från A. Beskriv när du hellre skulle välja en fri funktion.
