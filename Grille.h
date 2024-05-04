#ifndef GRILLE_H
#define GRILLE_H


/*Déclaration de la structure Grille*/
struct Grille {
	int n;
 	int m;
	char *** tab;
	int cordx;
	int cordy;
};


/*Déclaration des fonctions pour Grille.c*/
struct Grille * Grille_allouer(int n, int m);

void Grille_vider(struct Grille * g);

void Grille_tirage_fruit(struct Grille * g);

void Grille_remplir(struct Grille * g, int x, int y);

void Grille_desallouer(struct Grille ** g);

#endif
