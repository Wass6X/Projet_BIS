#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

struct Serpent * creer_serpent(int n, int m) {

	struct Serpent * serp = malloc(sizeof(struct Serpent)); 
    
	serp->cordx = (n/2);
	serp->cordy = (m/2);
    
	serp->chaine = creer_liste();
	ajout_debut_liste(serp->chaine, creer_section(1, 45));
	
	serp->mouvement = creer_liste_mouvement();
    
	return serp;
}


/*
void update_liste_mouvement(struct Serpent * serp) {
	
	struct Case * c = serp->mouvement->premier;
	
		
	c->cordx = serp->cordx;
	c->cordy = serp->cordy;
		
	while(c->suivant != NULL) {
		
		c->suivant->cordx = c->cordx;	
		c->suivant->cordy = c->cordy;	
		c->suivant->sens = c->sens;
		
		c = c->suivant; 
			
	}
	
	c = NULL;
	
}
*/
