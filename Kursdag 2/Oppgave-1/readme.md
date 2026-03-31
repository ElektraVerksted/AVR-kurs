# Dag 2 - Oppgave 1
Les posisjonen til potensiometeret på Curiosity Nano Explorer kortet og send den til PCen.

Info: Potensiometeret er koblet til PD6. For å kunne kunne sende UART til PCen gjennom USB må du bruke UART3, med pinner PB0 og PB1

Opprett et nytt prosjekt, lag en MCC konfigurasjon og skriv koden i _\<prosjektmappe>/My_MCC_Config/mcc/main.c_.


```
int main(void)
{
    SYSTEM_Initialize();
    
    // Skru på ADCen

    // Velg riktig kanal for å lese fra. Dette bestemmer hvilken pinne ADCen leser fra

    while(1)
    {
        // Begynn å måle spenningen
        
        // Hvordan kan vi sørge for at vi ikke prøver å lese av resultatet før målingen er ferdig?

        // Lagre resultatet i en variabel

        // Skriv posisjonen til UART

    }    
}
```
