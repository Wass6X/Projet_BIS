#ifndef SERPENT_H
#define SERPENT_H

#include "Liste_Section.h"


struct Serpent {
	int cordx;
	int cordy;
	struct Liste * chaine;	
};

/* Fonction permertant d'alouer un espace pour le serpent et qui prend en entrée les dimensions de la grille */
struct Serpent * creer_serpent(int n, int m); 

#endif
