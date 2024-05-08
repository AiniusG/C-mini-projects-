test.exe : main.c verbalArithmetics.h verbalArithmetics.o
	gcc -std=c99 -o test.exe main.c verbalArithmetics.o

verbalArithmetics.o : verbalArithmetics.c verbalArithmetics.h
	gcc -c -std=c99 verbalArithmetics.c