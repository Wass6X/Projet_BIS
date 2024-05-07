#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

struct Serpent * creer_serpent(int n, int m) {

	struct Serpent * serp = malloc(sizeof(struct Serpent)); 
    
	serp->cordx = 10;
	serp->cordy = 10;
    
	serp->chaine = creer_liste();
	
	ajout_debut_liste(serp->chaine, creer_section(2, 42));
    
	return serp;
}
