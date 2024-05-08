#include <stdio.h>
#include <stdlib.h>
#include "verbalArithmetics.h"

#define WORD_LENGTH 8
#define MAX_WORDS 8

int main(){

    char words[MAX_WORDS][WORD_LENGTH] = {"SEND","MORE"};
    char result[WORD_LENGTH] = "MONEY";
    solve(words,result,2);
    printf("\n");

    char words2[MAX_WORDS][WORD_LENGTH] = {"ABC","ABC","ABC"};
    char result2[WORD_LENGTH] = "BBB";
    solve(words2,result2,3);
    printf("\n");

    char words3[MAX_WORDS][WORD_LENGTH] = {"ADS","JAVA"};
    char result3[WORD_LENGTH] = "PAVARGAU";
    solve(words3,result3,2);
    printf("\n");

    char words4[10][8] = {"A","A","A","A","A","A","A","A","A","A"};
    char result4[WORD_LENGTH] = "PAVARGAU";
    solve(words4,result4,10);
    printf("\n");

    solve(words2,result2,1);
    printf("\n");

    return 0;
}
