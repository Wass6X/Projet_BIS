#ifndef SERPENT_H
#define SERPENT_H

#include "Liste_Section.h"


struct serpent {
	int cordx;
	int cordy;
	struct liste * chaine;	
};

/* Fonction permertant d'alouer un espace pour le serpent et qui prend en entrée les dimensions de la grille */
struct serpent * creer_serpent(int n, int m); 

#endif
