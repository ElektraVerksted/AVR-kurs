/*
 * Fil: main.c
 * Kursdag 3, Oppgave 1 (Løsningsforslag)
 * Beskrivelse: I denne oppgaven skal du vise temperatur og brytertilstand på en SSD1306 OLED-skjerm.
 */

#define F_CPU 4000000UL

// Standard bibliotek includes
#include "util/delay.h"
#include <stdio.h>
#include <string.h>

// MCC includes
#include "mcc_generated_files/system/system.h"

// Biblioteks includes
#include "mcp9808.h"
#include "ssd1306.h"

void oppdaterSkjerm();

int main(void)
{
    SYSTEM_Initialize();

    SSD1306_Init();
    SSD1306_Clear();

    while (1)
    {
        _delay_ms(20);
        oppdaterSkjerm();
    }
}

void oppdaterSkjerm()
{
    // Henter ut temperatur og formaterer det som en String(char-array)
    uint16_t temp = MCP9808_temp();
    char temperaturString[18];
    sprintf(temperaturString, "Temperatur: %u", temp);

    /*
     * Starter med tomme strings. Vi har tre mellomrom slik at om vi ikke viser "SWn" vil de andre strengene ha samme
     * posisjon. Merk at det er fire elementer i listen. Det er fordi vi må ha plass til en  "terminerende karakter", en
     * byte som skrives på slutten av en string
     */
    char SW1[4] = "   ";
    char SW2[4] = "   ";
    char SW3[4] = "   ";

    /*
     * Om bryteren er trykket bytter vi ut verdien i variablen med "SWn ". Merk at vi må bruke funksjonen strcpy(),
     * eller string-copy. Det er fordi strings i C egentlig er en liste med enkeltkarakterer(char), så vi må bruke en
     * funksjon som kopierer en bokstav om gangen inn i listen.
     */
    if (SW1_GetValue())
    {
        strcpy(SW1, "SW1");
    }

    if (SW2_GetValue())
    {
        strcpy(SW2, "SW2");
    }

    if (SW3_GetValue())
    {
        strcpy(SW3, "SW3");
    }

    // Så legger vi alt inn i én string
    char brytere[15];
    sprintf(brytere, "%s %s %s", SW1, SW2, SW3);

    // Velger linje en og skriver temperaturen
    SSD1306_SelectPage(0);
    SSD1306_WriteString(temperaturString);

    // Velger linje to og skriver bryterstatus
    SSD1306_SelectPage(1);
    SSD1306_WriteString(brytere);
}
