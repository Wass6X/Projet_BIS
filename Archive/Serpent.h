#ifndef SERPENT_H
#define SERPENT_H

#include "liste_Section.h"
#include "liste_Mouvement.h"

/* Définition de la structure Serpent */
struct Serpent {
	
	int cordx;			/* Coordonnée x du serpent */
	int cordy;			/* Coordonnée y du serpent */
	
	struct Liste * chaine;		/* Liste de sections formant le serpent */
	
	struct Liste_Mouvement * mouvement;		/* Liste des mouvements du serpent */
	
};

/* Fonction permertant d'alouer un espace pour le serpent et qui prend en entrée les dimensions de la grille */
struct Serpent * creer_serpent(int n, int m);

/* Fonction permertant d'alouer un espace pour le deuxieme sserpent et qui prend en entrée les dimensions de la grille */
struct Serpent * creer_serpent_2(int n, int m);

#endif
