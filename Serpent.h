#ifndef SERPENT_H
#define SERPENT_H

#include "Liste_Section.h"


enum Direction { HAUT, BAS, GAUCHE, DROITE };


struct Case {
	
	enum Direction sens;
	struct Case * suivant;
	
};



struct Liste_Mouvement {

	struct Case * premier;
	struct Case * dernier;
	int longueur;	
	
};

struct Serpent {
	
	int cordx;
	int cordy;
	
	struct Liste * chaine;	
	
	struct Liste_Mouvement * mouvement;
	
	enum Direction sens; 
	
};

/* Fonction permertant d'alouer un espace pour le serpent et qui prend en entrée les dimensions de la grille */
struct Serpent * creer_serpent(int n, int m); 

#endif
