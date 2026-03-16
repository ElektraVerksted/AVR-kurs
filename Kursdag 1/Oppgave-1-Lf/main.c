/*
    I oppgave 1 skal du få en LED på CNano-brettet til å blinke periodisk. LEDen er koblet til PB3. Oppgaven skal
    løses uten å bruke MCC.
    
    Hint: Dersom du definerer #define F_CPU xxxxxUL øverst i fila kan du bruke funksjonen _delay_ms(). 
*/
#define F_CPU 4000000UL

#include <avr/io.h>
#include <avr/delay.h>

int main(){
    //Definer pinnen som en utgang
    PORTB.DIR |= PIN3_bm;

    //Skru LEDen av og på med en jevn periode. 
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
