#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"
#include "time.h"

struct serpent * creer_serpent(int n, int m) {

	struct serpent * serp = malloc(sizeof(struct serpent));

	srand(time(NULL));

	serp->cordx = rand() % n;
	serp->cordy = rand() % m;
	
	serp->chaine = creer_liste();
	
	ajout_debut_liste(serp->chaine, creer_section(5, 42));
	ajout_debut_liste(serp->chaine, creer_section(6, 43));
	ajout_debut_liste(serp->chaine, creer_section(7, 44));
	
	return serp;

}
