# Bonusoppgaver

Bonusoppgavene er til for deg som har fullført dagens oppgaver og ønsker å bryne deg på mer. Oppgavene gir et frampek til temaet for neste kursdag, men er preget av egen læring. Oppgavene er gitt, men du får ingen fremgangsmetode eller løsningsforslag. Derimot får du pekepinner på hvor i databladet du kan lete for å lære det du trenger.

Et veldig generelt tips er: Omtrent alle periferienheter har et punkt som heter "Initialization" under den funksjonelle beskrivelsen. Dette er en avkrysningsliste for de absolutt nødvendige trinnene for at periferienheten skal fungere. Det anbefales å lese et par avsnitt i databladet for å forstå hvordan periferienheten virker.

Et annet tips, dersom du bruker MCC, er å lese de tilgjengelige funksjonene til hver komponent. Disse finner du under _\<prosjektnavn>/My_MCC_Config/mcc/mcc_generated/files_. Funksjonsnavnene er stort sett selvforklarende.

Ta notater når du leser databladet, det hjelper å teste forståelsen. Dersom du klarer å beskrive det med dine egne ord har du antageligvis forstått litt av det.

Lykke til!

## Bonusoppgave 1
Les av posisjonen på potensiometeret nederst til høyre på Curiosity Nano Explorer kortet. Om potensiometeret er vridd under halvveis skal lyset være slått av, om det er over halvveis skal det være slått på. Dersom det er skrudd fullstendig til høyre skal lyset blinke.

For å gjøre denne oppgaven bør du lese kapittel 33 i databladet, som handler om Analog-Digital-omformeren. 

En nyttig ting å reflektere over: Hvilken rolle spiller VREF i ADCen? Hvordan kan den forandre avlesingene?

## Bonusoppgave 2
Få RGB-dioden (til høyre på kortet, over ringen med RGB-lys) til å lyse forskjellige farger. Dioden er koblet til PWM A, B og C, og fargen bestemmes av hvor lyse hver av de tre fargene er i forhold til hverandre.

For å løse oppgaven bør du lese kapittel 23 i databladet om timeren TCA. I delkapittel 23.3.3.4.3 kan du lese om hvordan timeren kan brukes til PWM, men for å forstå det bør du lese om hvordan timeren fungerer til vanlig. Du kan se og velge hvilke porter som brukes i kapittel 17 om Port-multiplekseren.

Dersom du ønsker en enda større utfordring kan du prøve å løse oppgaven uten å bruke MCC.
