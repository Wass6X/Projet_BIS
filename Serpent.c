#include <stdlib.h>
#include <stdio.h>
#include "Serpent.h"

/* Fonction pour créer un serpent */
struct Serpent * creer_serpent(int n, int m) {

	/* Allocation de mémoire pour le serpent */
	struct Serpent * serp = malloc(sizeof(struct Serpent)); 
	
	/* Initialisation des coordonnées du serpent au milieu de la grille */	
	serp->cordx = (n/4);
	serp->cordy = (m/4);
	
	/* Création de la liste de sections formant le serpent */
	serp->chaine = creer_liste();
	ajout_debut_liste(serp->chaine, creer_section(1, 0));
	
	/* Création de la liste de mouvements du serpent */
	serp->mouvement = creer_liste_mouvement();
	ajout_debut_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, NEUTRE));  

	/* Retour du serpent créé */
	return serp;
}

