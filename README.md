# Náplň cvičenia
- pokračovť v plnení úloh z predchádzajúceho cvičenia (vrs_cvicenie_2)
- predstavenie nového zadania
- konzultácie


# Zadanie
- #### Toto zadanie priamo nadväzuje na zadanie z predchádzajúceho cvičenia - zadanie_cv2. Vytvorte aplikáciu pre detegovanie hrany vstupného signálu privedeného na vstup MCU pričom LED pripojená na jeho výstup bude indikovať úspešnú detekciu hrany. Vstupný signál je privedený na pin GPIOA-3. Hrana je generovaná prostredníctvom tlačidla. Výstupný signál je privedený na pin GPIOA-4.

### Úlohy:
 1. #### Vytvoriť repozitár, kde nahrajete svoj projekt z predchádzajúceho zadania.
 2. #### Pracovať s vlastným repozitárom tak, aby boli vydieť "commits" (editačné zmeny). Ideálne od celej dvojice.
 3. #### V súbore "Inc/assignment.h" definovať enum "EDGE_TYPE", ktorý bude enumerovať 3 stavy: žiadna hrana (NONE = 0), nábežná hrana (RISE = 1), dobežná hrana (FALL = 2).
 4. #### V súbore "Inc/assignment.h" deklarujte a v subore "Src/main.c" definujte funkciu "edgeDetect", ktorej úlohou je detegovať hranu (stlačenie tlačidla). Funkcia vracia hodnotu typu "EDGE_TYPE" a má dva vstupné argumenty:
 
```javascript
EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples);
```
  - Vstupný parameter "pin_state" predstavuje aktuálny stav vstupného pinu, na ktorom sa deteguje hrana. Nadobúda hodnotu "1" alebo "0". 
  - Vstupný parameter "samples" definuje koľkokrát v rade musí byť detegovaný nový stav vstupného pinu, aby sa to považovalo za hranu - stlačenie tlačidla.
  - Príklad: 
    - predchádzajúci stav = 0, aktuálny stav = 1, samples = 5
    - aby bola detegovaná hrana, musí sa 5-krát v rade prečítať rovnaký stav tj. 0,1,1,1,1,1 - nábežná hrana bola detegovaná
    - ak by pri čítaní zo vstupného pinu nastala situácia 0,1,1,1,0,1 - pri zmene stavu z 0 na 1 sa na vstupe vyčítala hodnota 1 len 3-krát v rade, vyhodnotí sa to ako "žiadna hrana", pretože nebola splnená podmienka.
   
5. #### Upraviť program vykonávajúci sa v "main" funkcii tak, aby LED zmenila svoj stav (On -> Off, Off -> On) len vtedy, ak bol detegovaný vami zvolený typ hrany. LED bude meniť svoj stav len ak bola detegovaná nábežná hrana alebo bude meniť svoj stav len v prípade detekcie dobežnej hrany. 


6. #### Odovzdáva sa odkaz k vašemu repozitáru.
 
 <p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_2/blob/master/documents/edge_detect.png" width="2000" height="250" title="LED, button and Stm32 - circuit.">
</p>
