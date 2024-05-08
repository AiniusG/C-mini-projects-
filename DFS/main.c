#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "DFS.h"

#define MAX_DALYKAI 28
#define CHAR_LIMIT 64

int main()
{
    srand(time(NULL));
    int dalyku_kiekis = MAX_DALYKAI;
    char dalykai[MAX_DALYKAI][CHAR_LIMIT];
    int graph[MAX_DALYKAI][MAX_DALYKAI];


    FILE *read;
    read = fopen("data.txt","r");
    for(int i = 0; i < MAX_DALYKAI; ++i){
        fgets(dalykai[i], CHAR_LIMIT, read);
        dalykai[i][strcspn(dalykai[i],"\n")] = 0;
    }

    for(int i = 0; i < MAX_DALYKAI; ++i){
        for(int j = 0; j < MAX_DALYKAI; ++j){
            fscanf(read, "%d", &graph[i][j]);
        }
    }
    fclose(read);


    int dalykas1;
    int dalykas2;


    int counter = 0;
    for(int i = 0; i < 10; ++i)
    {
        dalykas1 = rand() % dalyku_kiekis;
        dalykas2 = rand() % dalyku_kiekis;
        if (ar_yra_tranzityvi_priklausomybe(graph, dalykas1, dalykas2, dalyku_kiekis))
        {
            printf("Norint klausyti \"%s\" BŪTINA būti išklausius \"%s\".\n", dalykai[dalykas1], dalykai[dalykas2]);
            ++counter;
        }
        else
        {
            printf("Norint klausyti \"%s\" NEBŪTINA būti išklausius \"%s\".\n", dalykai[dalykas1], dalykai[dalykas2]);
        }
    }
    if(counter == 0) //jeigu visi dalykai buvo nebūtini (parodymas, kad veikia ir kai būtina)
    {
        if (ar_yra_tranzityvi_priklausomybe(graph, 4, 1, dalyku_kiekis))
        {
            printf("Norint klausyti \"%s\" BŪTINA būti išklausius \"%s\".\n", dalykai[4], dalykai[1]);
            ++counter;
        }
        else
        {
            printf("Norint klausyti \"%s\" NEBŪTINA būti išklausius \"%s\".\n", dalykai[4], dalykai[1]);
        }
    }

    printf("\n\nGrafinė priklausomybė: \n");
    for(int i = 0; i < MAX_DALYKAI; ++i){
        for(int j = 0; j < MAX_DALYKAI; ++j){
            if(graph[i][j] == 1){
                printf("%s -> %s\n", dalykai[i], dalykai[j]);
            }
        }
    }



    return 0;
}
