#ifndef GRILLE_H
#define GRILLE_H

#include "Serpent.h"
#include "liste_Mouvement.h"

/*Déclaration de la structure Grille*/
struct Grille {
	int n;
 	int m;
	char *** tab;
	int cordx;
	int cordy;
};



enum element {Rien, Fruit, Corp_serp};

enum element **initialiser_mat(int n, int m);



/*Déclaration des fonctions pour Grille.c*/
struct Grille * Grille_allouer(int n, int m);

void Grille_vider(struct Grille * g);

void Grille_tirage_fruit(struct Grille * g);


/* Fontion permerttant d'afficher le fruit */
void Grille_remplir_rouge(struct Grille * g, int x, int y);

void Grille_desallouer(struct Grille ** g);

void Grille_redessiner(struct Grille *g);

void Grille_remplir_couleur(struct Grille * g, int x, int y, int couleur);

void Grille_remplir_serp(struct Grille * g, struct Serpent * serp, enum Direction * sens, enum element **M);

#endif
