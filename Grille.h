#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct Grille {
	int n;
 	int m;
	char ** mat;
	int long_fruit;
	int larg_fruit;
};


struct Grille *Grille_allouer(int n, int m);
char Grille_vider();
void Grille_tirage_fruit();
void Grille_remplir(struct Grille *g);
void Grille_desallouer(struct Grille *g);
