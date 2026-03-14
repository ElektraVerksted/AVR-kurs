/**
 * @file main.c
 * @author husev
 * @date 2026-03-12
 * @brief Main function
 */
#define F_CPU 4000000UL
#include <avr/io.h>
//#include "util/delay.h"



 
int main() {
    //Definer en pin som ingang som er koblet til SW0
    PORTB.DIRSET = PIN3_bm;
    // Definer en pin som utgang som er koblet til LED0
    PORTB.DIRCLR = PIN2_bm;
    
    //Skru av LED0 hvis knappen ikke er trykket ned, og skru på LED0 hvis knappen er trykket ned
    while(1){
        if (PORTB.IN & PIN2_bm){
            PORTB.OUTSET = PIN3_bm;
        }
        else{
        PORTB.OUTCLR = PIN3_bm;
        }
    }
    return 0;
    
}


