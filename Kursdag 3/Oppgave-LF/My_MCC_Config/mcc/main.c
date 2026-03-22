 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
� [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/pins.h"
#include <string.h>
#define F_CPU 4000000UL

#include "mcc_generated_files/system/system.h"
#include "ssd1306.h"
#include "mcp9808.h"
#include <stdio.h>
#include "util/delay.h"

/*
    Main application
*/

void oppdaterSkjerm();

int main(void)
{
    SYSTEM_Initialize();

    SSD1306_Init();
    SSD1306_Clear();

    while(1)
    {
        _delay_ms(20);
        oppdaterSkjerm();  
           
        //SSD1306_Clear();
    }    
}


void oppdaterSkjerm(){
    //Henter ut temperatur og formaterer det som en String(char-array)
    uint16_t temp = MCP9808_temp();
    char temperaturString[18];
    sprintf(temperaturString, "Temperatur: %u", temp);

    //Starter med tomme strings. Vi har tre mellomrom slik at om vi ikke viser "SWn" vil de andre strengene 
    //ha samme posisjon. Merk at det er fire elementer i listen. Det er fordi vi må ha plass til en 
    //"terminerende karakter", en byte som skrives på slutten av en string
    char SW1[4] = "   ";
    char SW2[4] = "   ";
    char SW3[4] = "   ";
    /*
        Om bryteren er trykket bytter vi ut verdien i variablen med "SWn ". Merk at vi må bruke funksjonen
        strcpy(), eller string-copy. Det er fordi strings i C egentlig er en liste med enkeltkarakterer(char),
        så vi må bruke en funksjon som kopierer en bokstav om gangen inn i listen.
    */
    
    if(SW1_GetValue()){strcpy(SW1, "SW1");}
    if(SW2_GetValue()){strcpy(SW2, "SW2");}
    if(SW3_GetValue()){strcpy(SW3, "SW3");}

    //Så legger vi alt inn i én string
    char brytere[15];
    sprintf(brytere, "%s %s %s", SW1, SW2, SW3);


    //Velger linje en, tømmer den og skriver temperaturen
    SSD1306_SelectPage(0);
    SSD1306_WriteString(temperaturString);

    //Velger linje to, tømmer den og skriver tekst
    SSD1306_SelectPage(1);
    SSD1306_WriteString(brytere);

}