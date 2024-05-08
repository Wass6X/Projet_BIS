#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

struct Serpent * creer_serpent(int n, int m) {

	struct Serpent * serp = malloc(sizeof(struct Serpent)); 
    
	serp->cordx = (n/2);
	serp->cordy = (m/2);
    
	serp->chaine = creer_liste();
	
	ajout_debut_liste(serp->chaine, creer_section(1, 43));
    
	return serp;
}

struct Case * creer_case(enum Direction sens) {
	
	struct Case * c = malloc(sizeof(struct Case));
	
	c->sens = sens;
	c->suivant = NULL;
	
	return c;

}


struct Liste_Mouvement * creer_liste_mouvement() {

	struct Liste_Mouvement * lm = malloc(sizeof(struct Liste_Mouvement));	
	
	lm->premier = NULL;
	lm->dernier = NULL;
	lm->longueur = 0;
		
	return lm;
}

