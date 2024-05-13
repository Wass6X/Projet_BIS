#include <stdlib.h>
#include <stdio.h>
#include "liste_Mouvement.h"


struct Case * creer_case(int cordx, int cordy, enum Direction sens) {
	
	struct Case * c = malloc(sizeof(struct Case));
	
	c->cordx = cordx;
	c->cordy = cordy;
	c->sens = sens;
	
	c->suivant = NULL;
	
	return c;

}

void desalouer_case(struct Case ** c) {
	
	if (*c != NULL) {
			
		free(*c);
		*c = NULL;	
	
	}
	
}


struct Liste_Mouvement * creer_liste_mouvement() {

	struct Liste_Mouvement * lm = malloc(sizeof(struct Liste_Mouvement));	
	
	lm->premier = NULL;
	lm->dernier = NULL;
	lm->longueur = 0;
		
	return lm;
}


int est_vide_lm(struct Liste_Mouvement * lm) {

	return (lm->longueur == 0);
}



void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {

	
	if (est_vide_lm(lm)) 
		lm->dernier = c;
	
	c->suivant = lm->premier;
		
	lm->premier = c;

	lm->longueur++;

}


void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {

	c->suivant = NULL;
	
	if (est_vide_lm(lm)) {
		lm->premier = c;
	}else {
		lm->dernier->suivant = c;
	}	
	
	lm->dernier = c;
	
	lm->longueur++;

}


struct Case * extraire_case(struct Liste_Mouvement * lm) {
	
	struct Case * c = lm->premier;
	
	if (c != NULL) {
	
   		lm->premier = c->suivant;
    	
    		lm->longueur--;
    		
    		if (est_vide_lm(lm)) 
    			lm->dernier = NULL; 
    
    		c->suivant = NULL;
	
	}
	
	return c;

}


void desalouer_liste_mouvement(struct Liste_Mouvement ** lm) {

	/*On Vérifie d'abord que l'argument entré correspond à une liste déja allouée dans le tas*/	
	if (*lm != NULL) {
		
		/* Création d'une section temporaire qui va servive à garder une trace de la section libérée*/
		struct Case * c;
		
		/* On libère toutes les sections de la liste une par une*/
		while(!est_vide_lm(*lm)) {
			c = extraire_case(*lm);
		}
		
		/* On libère la section temporaire */
		desalouer_case(&c);
		
		/* On désaloue la liste qui est à présent vide */
		free(*lm);
		*lm = NULL;
	}
	
}

