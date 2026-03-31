# Dag 1 - Oppgave 4

I oppgave 4 skal dere skru LEDen på CNano-kortet på dersom knappen, SW0, nederst på kortet er trykket inn. SW0 er koblet til PB2 og LED er koblet til PB3. Oppgaven skal løses ved hjelp av MCC.
 
Hint: Etter dere har konfigurert MCC og generert filer kan dere finne alle tilgjengelige funksjoner under _\<prosjektmappe>/MY_MCC_Config/mcc_generated_files/system_. For denne oppgaven er funksjonene i headerfilen "pins.h" relevant.
 
VSCode vil også hjelpe deg med å autofullføre funksjoner. Hvis du skriver navnet på pinnen (IO_PBn eller et egendefinert navn) og trykker ctrl + mellomromstasten vil den gi en liste over alle funksjoner som starter med pin-navnet.

```c
int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {   
        // Sjekk om knappen er trykket eller ikke
        
        // Om knappen er trykket, skru på LEDen
            
        // Hvis knappen ikke er trykket, skru LEDen av
            
    }    
}
```
