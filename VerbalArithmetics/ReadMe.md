Uždavinio esmė: 
    sukurti programą, kuri sprendžia kriptoaritmetinius uždavinius. Perrininkimas vyksta naudojant "Backtracking" algoritmą.

Programos naudojimas: 
    tarp savo programos iškvieskite solvable() funkciją, kuriai reikia duoti žodžių masyvą, rezultato žodį ir žodžių kiekį(be rezultato). Atlikus skaičiavimus atsakymą išspauzdins į console. Jeigu uždavinys išsprendžiamas išspausdins: "Solvable" kartu su raidžių atitinkamais skaitmeninimis. Jeigu uždavinys neišsprendžiamas išspausdins: "Not solvable".
Pvz.:
    SEND + MORE = MONEY: 
        char words[][] = {"SEND","MORE"};
        char result[] = "MONEY";
        solve(words, result, 2);
        console:
            Solvable
            D -> 7
            E -> 5
            M -> 1
            N -> 6
            O -> 0
            R -> 8
            S -> 9
            Y -> 2


    ABC + ABC + ABC = BBB:
        char words[][] = {"ABC","ABC","ABC"};
        char result[] = "BBB";
        solve(words, result, 3);
        console:
            Solvable
            A -> 1
            B -> 4
            C -> 8


    ADS + JAVA = PAVARGAU:
        char words[][] = {"ADS","JAVA"};
        char result[] = "PAVARGAU";
        solve(words, result, 2);
        console:
            Not solvable


Prgoramos limitai:
     Programa gali priimti 8 žodžius ir vieną rezultato žodį. Žodžiai negali būti ilgesni nei 8 raidės. Programą parodys pirmą rastą atsakymą, atsakymų gali būti ir daugiau. Lygtis turi būti arba didžiosiom arba mažosiomn raidėm (Negali būti SEND + MORE = money).

Šaltiniai: prgorama padaryti su pagalba iš:
    https://leetcode.com/problems/verbal-arithmetic-puzzle/solutions/
    