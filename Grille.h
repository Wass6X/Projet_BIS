#include<stdio.h>
#include<stdlib.h>


struct Grille {
	int n;
 	int m;
	char ** mat;
	int cordx;
	int cordy;
};


struct Grille * Grille_allouer(int n, int m);
char Grille_vider();
void Grille_tirage_fruit();
void Grille_remplir(struct Grille *g);
void Grille_desallouer(struct Grille *g);
