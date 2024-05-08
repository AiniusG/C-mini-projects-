#ifndef verbalArithmetics_h
#define verbalArithmetics_h
#include <stdbool.h>
#define WORD_LENGTH 8

bool solvePuzzle(int digit, int index, int sum);
void reverseString(char* s);
bool isSolvable(char inputWords[][WORD_LENGTH], char inputResult[], int n);
void solve(char inputWords[][WORD_LENGTH], char inputResult[], int n);

#endif
