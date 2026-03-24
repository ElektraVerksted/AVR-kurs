# Dag 1 - Oppgave 2
I oppgave 2 skal du lese av input fra knappen SW0 nederst på CNano-kortet og skru på LED0 så lenge den er trykket. Lyset skal skrues av så lenge knappen ikke er trykket. Oppgaven skal løses uten å bruke MCC.

Hint: Knappen SW0 er koblet til pin PB2, og LED0 er koblet til pin PB3. Knappen er aktiv lav, det vil si at den leser 0 når den er trykket ned og 1 ellers. Finnes det et register som kan invertere dette?

Opprett et nytt prosjekt og skriv koden i _\<prosjektmappe>/main.c_.

```c
#define F_CPU 4000000UL
#include <avr/io.h>

int main() {
    // Definer en pin som ingang som er koblet til SW0

    // Definer en pin som utgang som er koblet til LED0

    while(1){
        // Sjekk om knappen er trykket ned
        
        // Skru på lyset om knappen er trykket, og av ellers

    }

    return 0;
    
}
```
