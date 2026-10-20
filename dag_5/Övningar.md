# Övningar dag 5 - arv och polymorfism

Du skriver egen kod och gör övningarna självständigt. Visa gärna resultatet för en klasskamrat när du är klar. Använd lösningsförslagen efter ditt eget försök. Om du saknar en klasskamrat gör du själv kontrollerna och antecknar resultatet.

## Start

Skapa en egen labbmapp med C++23/CMake. Arbeta med lokala objekt och referenser; dynamiskt ägande kommer senare. Du får återanvända gränssnittet i Source.hpp när du gör den avslutande uppgiften.

## A - publikt arv

1. Skapa Device med ett namn och en läsande getter. Skapa Sensor som ärver publikt från Device och håller ett heltalsvärde.
2. Initiera basens namn i Sensors konstruktor. Skapa room med värdet 25 och skriv dess namn/värde.
3. Kontrollera att basens privata medlem inte går att ändra direkt från anroparen.

**Klart när:** utskriften är room: 25 och du kan beskriva vad som hör till basdelen och vad som hör till Sensor.

## B - virtuellt gränssnitt

1. Skapa abstrakta Source med read/name och virtuell destructor. read ska ge 0-100.
2. Implementera ConstantSource och OffsetSource. OffsetSource lagrar förskjutningen i value_ och validerar intervallet -50 till 50 i konstruktorn. Dess read() beräknar 50 + value_; ConstantSource::read() returnerar sitt lagrade värde direkt.
3. Skriv en enda show-funktion som tar const Source& och använd den med båda typerna.
4. Prova värde 20, offset 30, och gränserna. Avvisa värde 101 och offset 51 med out_of_range.

**Klart när:** show använder rätt beteende för båda objekten, utan en kontroll av deras konkreta typ i funktionen.

## C - slicing och komposition

1. Skapa en icke-abstrakt Device med virtuell name och en härledd Sensor som returnerar ett annat namn.
2. Jämför en funktion som tar Device som värde med en som tar const Device&. Förklara skillnaden i utskrift.
3. Skapa separat en Monitor som har en AlarmRule, inte ärver från den. Förklara varför har-en passar där.

**Klart när:** du kan visa både slicing och en kompositionsrelation utan ogiltig minnesåtkomst.

## Lösningsförslag till delövningarna

| Del | Förslag att jämföra med |
|---|---|
| A | 01_inheritance.cpp |
| B | [Source.hpp](Source.hpp), 02_virtual.cpp och 03_abstract.cpp |
| C | 04_slicing.cpp och 05_composition.cpp |

## Avslutningsövning - återskapa main.cpp

Utgå från beskrivningen, inte från filen. Skapa ett program med ConstantSource(20) och OffsetSource(30). En enda report-funktion ska ta const Source&, läsa värdet och skriva namn, värde och Normal eller Alarm. Alarm gäller från 80. Försök sedan skapa ConstantSource(101), fånga out_of_range och skriv Rejected. Inga indata från terminalen behövs.

Förväntad utskrift:

```text
constant: 20 Normal
offset: 80 Alarm
Rejected
```

**Klart när:** du får dessa rader och report fungerar med båda källorna. Lösningsförslag: main.cpp. Jämför efter eget försök; namn och filindelning får skilja sig om kontraktet är uppfyllt.

## Visa gärna för en klasskamrat

Visa en lyckad polymorf rapport, avvisad konstruktion och slicing-jämförelsen. Anteckna skillnaden mellan basreferens och basvärde och ett fall där du hellre skulle använda komposition.
