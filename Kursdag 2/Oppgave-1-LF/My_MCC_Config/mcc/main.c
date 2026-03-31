/*
 * Fil:         main.c
 * Kursdag:     2, Oppgave 1 (Løsningsforslag)
 * Beskrivelse: I denne oppgaven skal du lese av et potensiometer via ADC og skriver resultatet over UART.
 */

#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/adc/adc_types.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include <avr/io.h>
#include <stdio.h>

int main(void)
{
    SYSTEM_Initialize();

    ADC0_Enable();
    ADC0_ChannelSelect(ADC0_CHANNEL_AIN6);

    VREF.ADC0REF = 0x05; // VDD as ADC reference

    while (1)
    {
        ADC0_ConversionStart();
        while (!ADC0_IsConversionDone())
        {
        }
        adc_result_t resultat = ADC0_ConversionResultGet();

        (void)printf("%d\r\n", resultat);

        if (resultat > (adc_result_t)2048)
        {
            LED_SetHigh();
        }
        else
        {
            LED_SetLow();
        }
    }
}
