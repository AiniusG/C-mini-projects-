#include "verbalArithmetics.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WORD_LENGTH 8
#define MAX_WORDS 8

int c2i[256];       //char to int
int i2c[10];        //int to char
int used[10];       //used numbers
int numWords = 0;   //amount of input words (without result)

char words[MAX_WORDS][WORD_LENGTH]; //words in a global char
char result[WORD_LENGTH];   //result in a global char
int limit = 0;  //word length limit


//funckija isspresti kriptoaritmetika
bool solvePuzzle(int digit, int index, int sum) {   //digit - current digit being processed, sum of digits being acumulated
    if (digit == limit) {
        return sum == 0;
    }

    if (index == numWords) {
        if (c2i[(int)result[digit]] == -1 && i2c[sum % 10] == -1) {
            if (sum % 10 == 0 && digit + 1 == limit)
                return false;
            c2i[(int)result[digit]] = sum % 10;
            i2c[sum % 10] = (int)result[digit];
            used[sum % 10] = 1;
            bool tmp = solvePuzzle(digit + 1, 0, sum / 10);
            if (!tmp) {
                c2i[(int)result[digit]] = -1; // Rollback if not solvable
                i2c[sum % 10] = -1;
                used[sum % 10] = 0;
            }
            return tmp;
        } else if (c2i[(int)result[digit]] != -1 && c2i[(int)result[digit]] == sum % 10) {
            if (digit + 1 == limit && 0 == c2i[(int)result[digit]]) {
                return false;
            }
            return solvePuzzle(digit + 1, 0, sum / 10);
        } else {
            return false;
        }
    }

    if (digit >= strlen(words[index]))
        return solvePuzzle(digit, index + 1, sum);

    if (c2i[(int)words[index][digit]] != -1) {
        if (digit + 1 == strlen(words[index]) && strlen(words[index]) > 1 && c2i[(int)words[index][digit]] == 0)
            return false;
        return solvePuzzle(digit, index + 1, sum + c2i[(int)words[index][digit]]);
    }

    for (int i = 0; i < 10; i++) {
        if (digit + 1 == strlen(words[index]) && i == 0 && strlen(words[index]) > 1)
            continue;
        if (used[i])
            continue;
        c2i[(int)words[index][digit]] = i;
        i2c[i] = (int)words[index][digit];
        used[i] = 1;
        bool tmp = solvePuzzle(digit, index + 1, sum + i);
        if (!tmp) {
            c2i[(int)words[index][digit]] = -1; // Rollback if not solvable
            i2c[i] = -1;
            used[i] = 0;
        }
        if (tmp)
            return true;
    }
    return false;
}

//apsukti string (SEND -> DNES)
void reverseString(char* s) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

//ar duotus zodzius imanoma isspresti
bool isSolvable(char inputWords[][WORD_LENGTH], char inputResult[], int n){
    //uzpildom tuscius masyvus masyvus su -1 ir 0;
    memset(c2i, -1, sizeof(c2i));
    memset(i2c, -1, sizeof(i2c));
    memset(used, 0, sizeof(used));
    numWords = n;

    //persikeliam lokalius kintamuosius i globalius
    for(int i = 0; i < numWords; ++i)
        strcpy(words[i], inputWords[i]);
    strcpy(result, inputResult);

    //tikrinam, ar sudeties zodziai nera ilgesni uz rezultato zodi
    limit = strlen(result);
    for(int i = 0; i < numWords; ++i){
        if(strlen(words[i]) > limit)
            return false;
        else
            reverseString(words[i]);
    }
    reverseString(result);
    return solvePuzzle(0, 0, 0);
}

void solve(char inputWords[][WORD_LENGTH], char inputResult[], int n){
    if (isSolvable(inputWords, inputResult, n)) {
        printf("Solvable\n");
        for (int i = 0; i < 256; i++) {
            if (c2i[i] != -1)
                printf("%c -> %d\n", i, c2i[i]);
        }
    } else {
        printf("Not solvable\n");
    }
}
