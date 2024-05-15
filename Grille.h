#ifndef GRILLE_H
#define GRILLE_H

#include "Serpent.h"
#include "liste_Mouvement.h"

/* Structure représentant la grille de jeu */
struct Grille {
	int n;			/* Nombre de lignes dans la grille */
 	int m;			/* Nombre de colonnes dans la grille */
	char *** tab;		/* Tableau à trois dimensions représentant la grille */
	int cordx;		/* Coordonnée x de la tête du serpent sur la grille */
	int cordy;		/* Coordonnée y de la tête serpent sur la grille */
};


/* Enumération des différents éléments présents dans la matrice d'éléments */
enum element {Rien, Fruit, Corp_serp};


/*Déclarations des fonctions pour Grille.c*/
struct Grille * Grille_allouer(int n, int m);				/* Alloue une nouvelle grille */

void Grille_vider(struct Grille * g);					/* Vide la grille */

void Grille_tirage_fruit(struct Grille * g);				/* Place un fruit aléatoirement sur la grille */


/* Fontion permerttant d'afficher la Grille */
void Grille_remplir_rouge(struct Grille * g, int x, int y);		/* Remplit une cellule de la grille en rouge (Le fruit) */

void Grille_desallouer(struct Grille ** g);				/* Désalloue la mémoire occupée par une grille */

void Grille_redessiner(struct Grille *g);				/* Redessine la grille */

void Grille_remplir_couleur(struct Grille * g, int x, int y, int couleur);			/* Remplit une cellule de la grille avec une couleur spécifique */

int Grille_remplir_serp(struct Grille * g, struct Serpent * serp, enum element **M);		/* Remplit la grille avec les éléments du serpent */


/* Initialisation d'une matrice d'éléments */
enum element **initialiser_mat(int n, int m);

/* Réinitialisation d'une matrice d'éléments */
void reset_mat(enum element  **M, int n, int m);


#endif
