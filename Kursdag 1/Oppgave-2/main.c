/*
    I oppgave 2 skal du lese av innput fra knappen SW0 og bruke dette til å skru på LED0, og så skru seg av når
    knappen ikke lengre trykkes ned.
    Oppgaven skal løses uten å bruke MCC.

    Hint: Knappen SW0 er koblet til pin PB2, og LED0 er koblet til pin PB3. Knappen er aktiv lav, det vil si at 
          den leser 0 når den er trykket ned og 1 ellers.
 */
#define F_CPU 4000000UL
#include <avr/io.h>

 
int main() {
    //Definer en pin som ingang som er koblet til SW0

    // Definer en pin som utgang som er koblet til LED0

    //Skru av LED0 hvis knappen ikke er trykket ned, og skru på LED0 hvis knappen er trykket ned

    
    return 0;
    
}
