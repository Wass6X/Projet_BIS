all: Grille.o main.o
	gcc Grille.o main.o -o exec

Grille.o: Grille.c Grille.h
	gcc -c -Wall -pedantic -std=c99 Grille.c

main.o: main.c Grille.h
	gcc -c -Wall -pedantic -std=c99 main.c

clean:
	rm *.o exec
