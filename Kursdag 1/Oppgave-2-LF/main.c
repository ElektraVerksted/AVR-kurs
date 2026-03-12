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

    PORTB.DIRSET = PIN3_bm;
    PORTB.DIRCLR = PIN2_bm;
    
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


