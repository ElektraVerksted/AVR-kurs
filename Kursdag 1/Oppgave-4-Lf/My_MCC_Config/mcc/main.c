/*
 * Dag 1 Oppgave 4 - Løsningsforslag
 */

#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"

int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {   // Sjekk om knappen er trykket (1) eller ikke (0) 
        if(SW0_GetValue())
        {
            // Om knappen er trykket, skru på LEDen
            LED_SetHigh();
        } 
        else
        {
            // HVis knappen ikke er trykket, skru LEDen av
            LED_SetLow();
        }
    }    
}