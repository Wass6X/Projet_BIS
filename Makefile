all: liste_Section.o Serpent.o Grille.o  main.o
	gcc liste_Section.o Serpent.o Grille.o main.o -o exec 

liste_Section.o: liste_Section.c liste_Section.h
	gcc -c -Wall -pedantic -std=c99 liste_Section.c

Serpent.o: Serpent.c Serpent.h liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Serpent.c

Grille.o: Grille.c Grille.h Serpent.h liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Grille.c

Fonction_Jeu_1_Serpent.o: Fonction_Jeu_1_Serpent.c Fonction_Jeu.h Grille.h Serpent.h liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Fonction_Jeu_1_Serpent.c

main.o: main.c Fonction_Jeu.h Grille.h Serpent.h liste_Section.h
	gcc -c -Wall -pedantic -std=c99 main.c

clean:
	rm *.o exec
