/*
 * Dag 2 Oppgave 3 - Løsningsforslag
 */

#include "mcc_generated_files/timer/tca0.h"
#define F_CPU 4000000UL

#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include <avr/io.h>
#include <util/delay.h>

void OVFCallback(){
    LED_Toggle();
}

int main(void)
{
    SYSTEM_Initialize();

    TCA0_OverflowCallbackRegister(OVFCallback);
    
    while (1) {
    
    }
}
