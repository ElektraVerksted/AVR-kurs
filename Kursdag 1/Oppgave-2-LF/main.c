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
    //Definer SW0 pin som inngang
    PORTB.DIRSET = PIN3_bm;
    
    // Definer LED0 pin som utgang
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


