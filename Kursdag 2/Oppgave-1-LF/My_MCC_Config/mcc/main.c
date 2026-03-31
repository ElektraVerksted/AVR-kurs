/*
 * Fil: main.c
 * Kursdag 2, Oppgave 1 (Løsningsforslag)
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

    // Standard spenningsreferanse er 1.024V. Potensiometeret varierer fra 0-5V, så vi må sette VDD(5V) som spenningsreferanse
    VREF.ADC0REF = VREF_REFSEL_VDD_gc; // VDD as ADC reference

    while (1)
    {
        // Vi starter en måling i ADCen
        ADC0_ConversionStart(); 
        // Så lenge ADCen måler gjør vi ingen ting
        while (!ADC0_IsConversionDone())
        {
        }

        adc_result_t resultat = ADC0_ConversionResultGet();

        (void)printf("%d\r\n", resultat); // \r\n forteller datamaskinen at den skal starte på en ny linje

        // I 12-biters modus gir ADCen et tall mellom 0 og 4096. Om det er over halvveis, skrur vi på lyset
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
