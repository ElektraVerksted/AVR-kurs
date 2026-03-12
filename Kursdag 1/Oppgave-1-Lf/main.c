/*
    I oppgave 1 skal du få en LED på CNano-brettet til å blinke periodisk. LEDen er koblet til PB3.
    Hint: Dersom du definerer #define F_CPU xxxxxUL øverst i fila kan du bruke funksjonen _delay_ms(). 
*/
#define F_CPU 4000000UL

#include <avr/io.h>
#include <avr/delay.h>

int main(){
    //Vi setter Port B pin 3 til å være en utgang ved å sette tilsvarende bit til 1 i PORTB.DIR
    PORTB.DIR |= PIN3_bm;

    
    while(1){
        //LEDen skrues på ved å sette tilsvarende pin i PORTB.OUT registeret til 1
        PORTB.OUT |= PIN3_bm;
        _delay_ms(1000);
        
        //Deretter settes den til 0 igjen
        PORTB.OUT &= ~PIN3_bm;
        _delay_ms(1000);
    }
    
    return 0;
}
