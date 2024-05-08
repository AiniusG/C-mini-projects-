## Uždavinio esmė: 
Duota mokomųjų dalykų bazė: dalyko pavadinimas, dalykai, kuriuos būtina išklausyti anksčiau. Patikrinti, ar būtina, pavyzdžiui, išklausyti „Mat. analizę“ prieš klausant „Optimizavimo metodus“. (grafo realizacija paremta kaimynystės matrica; naudoti paieškos į gylį metodą)

## Programos naudojimas: 
Paleidus "Go.cmd", susikuria "data.txt" failas, kuriame galite redaguoti duomenis:
1. Dalykų sąrašas, kuriame kiekvieną atskirą dalyką skiria nauja eilutė.
2. Matrica, kuri parodo dalykų priklausomybę nuo vienas kito, t.y. ar reikia x kurso, kad galėtume išklausyti y kursą.

### Pvz.:
Optimizavimo metodai (A)  
Algoritmų teorija (B)  
Dirbtinis intelektas: klasikiniai principai(C)  
Įvadas į kvantinius skaičiavimus (D) 

Norint išklausyti "Optimizavimo metodai", reikia išklausyti "Algoritmų teorijoa" (B -> A)  
Norint išklausyti "Dirbtinis intelektas: klasikiniai principai", reikia išklausyti "Optimizavimo metodai" (A -> C)  
Norint išklausyti "Įvadas į kvantinius skaičiavimu", reikia išklausyti "Algoritmų teorijoa" ir "Optimizavimo metodai" (B -> D; A -> D)  
Matrica:
~~~
    A   B   C   D  
A   0   0   1   1
B   1   0   0   1
C   1   0   0   0
D   0   0   0   0
~~~

## Progoramos limitai:
Programa priima 28 dalykus, nes tarp main.c yra #define MAX_DALYKAI 28, norint kiekį pakeisti, reikia pakeisti MAX_DALYKAI tarp main.c, DFS.h ir DFS.c.

## Autoriai:
Ainius Gecas
Karolina Mačiulevičiūtė
    