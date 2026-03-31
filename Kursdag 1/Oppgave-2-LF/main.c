/*
 * Fil:         main.c
 * Kursdag:     1, Oppgave 2 (Løsningsforslag)
 * Beskrivelse: I denne oppgaven skal du styre en LED med en knapp ved hjelp av GPIO-registre.
 */

#define F_CPU 4000000UL
#include <avr/io.h>

int main()
{
    // Definer LED pin som utgang
    PORTB.DIRSET = PIN3_bm;

    // Definer SW0 pin som inngang
    PORTB.DIRCLR = PIN2_bm;

    // Koble SW0 til PULLUP
    PORTB.PIN2CTRL |= PORT_PULLUPEN_bm;

    // Skru av LED0 hvis knappen ikke er trykket ned, og skru på LED0 hvis knappen er trykket ned
    while (1)
    {
        if (PORTB.IN & PIN2_bm)
        {
            PORTB.OUTSET = PIN3_bm;
        }
        else
        {
            PORTB.OUTCLR = PIN3_bm;
        }
    }
    return 0;
}
