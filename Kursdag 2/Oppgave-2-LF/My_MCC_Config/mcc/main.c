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
#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4000000UL

#include "mcc_generated_files/system/system.h"
#include <stdint.h>
#include <util/delay.h>


uint16_t periode;   //Initsialiseres i globalt skop så begge funksjoner kan bruke den
uint16_t nTicks;

void oppdaterDutyCycle(int R, int G, int B){
    //Lager en egen funksjon for å oppdatere duty cycle til 80% av ønsket verdi.
    

    //Den røde LEDen er koblet til CMP0
    TCA0_SINGLE_CMP0 = R * nTicks * 0.8;

    //Den grønne er koblet til CMP1
    TCA0_SINGLE_CMP1 = G * nTicks * 0.8;

    //Og den blå til CMP2 
    TCA0_SINGLE_CMP2 = B * nTicks * 0.8;

}


int main(void)
{
    SYSTEM_Initialize();
    

    periode = TCA0_PeriodGet();
    nTicks = periode / 100;

    //Startverdier
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
