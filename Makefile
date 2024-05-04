all: Liste_Section.o Serpent.o Grille.o main.o
	gcc Liste_Section.o Serpent.o Grille.o main.o -o exec


Liste_Section.o: Liste_Section.c Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Liste_Section.c

Serpent.o: Serpent.c Serpent.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Serpent.c

Grille.o: Grille.c Grille.h Serpent.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Grille.c

main.o: main.c Grille.h Serpent.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 main.c

clean:
	rm *.o exec
