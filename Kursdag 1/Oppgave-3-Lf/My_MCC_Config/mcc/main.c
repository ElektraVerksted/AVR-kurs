/*
 * Fil:         main.c
 * Kursdag:     1, Oppgave 3 (Løsningsforslag)
 * Beskrivelse: I denne oppgaven skal du blinke en LED periodisk ved hjelp av MCC-genererte drivere.
 */

#define F_CPU 4000000UL

#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include <avr/delay.h>

int main(void)
{
    SYSTEM_Initialize();

    while (1)
    {
        LED_SetHigh();
        _delay_ms(1000);
        LED_SetLow();
        _delay_ms(1000);

        // Alternativ løsning:
        // LED_Toggle();
        // _delay_ms(1000);
    }
}
