/*
 * Dag 2 Oppgave 2 - Løsningsforslag
 */

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4000000UL

#include "mcc_generated_files/system/system.h"
#include <stdint.h>
#include <util/delay.h>


uint16_t periode;   // Initsialiseres i globalt skop så begge funksjoner kan bruke den
uint16_t nTicks;

// Lager en egen funksjon for å oppdatere duty cycle til 80% av ønsket verdi.
void oppdaterDutyCycle(int R, int G, int B){
    // Den røde LEDen er koblet til CMP0
    TCA0_SINGLE_CMP0 = R * nTicks * 0.8;

    // Den grønne er koblet til CMP1
    TCA0_SINGLE_CMP1 = G * nTicks * 0.8;

    // Og den blå til CMP2 
    TCA0_SINGLE_CMP2 = B * nTicks * 0.8;
}

int main(void)
{
    SYSTEM_Initialize();
    
    periode = TCA0_PeriodGet();
    nTicks = periode / 100;

    // Startverdier
    int R = 100;
    int G = 0;
    int B = 0;

    while(1)
    {
        for(int i = 0; i < 100; i++){
            oppdaterDutyCycle(R, G, B);
            R--;
            G++;
            _delay_ms(10);

        }

        for(int i = 0; i < 100; i++){
            oppdaterDutyCycle(R, G, B);
            G--;
            B++;
            _delay_ms(10);
        }

        for(int i = 0; i < 100; i++){
            oppdaterDutyCycle(R, G, B);
            B--;
            R++;
            _delay_ms(10);
        }

    }    
}
