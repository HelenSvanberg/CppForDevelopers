# Övningar dag 15

Arbeta självständigt. Kontrollera vad du väntar dig innan du kör.

## A - Hämta resultat och fel

Starta en uppgift som returnerar 42 och hämta resultatet med get. Gör en separat variant som kastar och fånga felet i huvudtråden. Förklara vilken rad som kan behöva vänta. Jämför efteråt med [resultatexemplet](01_future.cpp) och [felexemplet](02_future_error.cpp).

## B - Följ väntcykeln

Utgå från 03_wait_without_lock.cpp. Beskriv med text vad huvudtråden väntar på om get flyttas in i låsblocket, och vad arbetaren väntar på. Ange vilken kod som behöver köras för att respektive väntan ska avslutas. Analysera den felaktiga placeringen utan att köra den.

Skriv sedan en egen fungerande variant där ett värde börjar på 15 och arbetaren tredubblar det under mutexen. Låt låsblocket i huvudtråden avslutas före get. Förväntad utskrift är 45. Förklara varför result, mutex och det delade värdet har tillräcklig livstid. Jämför efter eget försök med [lösningsförslaget](03_wait_without_lock.cpp), där värdet 21 i stället dubbleras.

## Avslutningsövning - Återskapa mätprogrammet

Skapa en miljon värden enligt index modulo 101. Summera kvadrater i en sekventiell variant och i två halvöppna iteratorintervall med async och huvudtråden. Använd tillräckligt bred heltalstyp. Kontrollera resultatlikhet för varje körning; prova också noll, ett och ett udda antal värden. Mät båda varianterna sju gånger, växla vilken som körs först och skriv ut medianerna. [Lösningsförslag](main.cpp) efter eget försök.

## Visa gärna för en klasskamrat

Visa samma resultat i båda lägena och förklara vad tidtagningen räknar in.
