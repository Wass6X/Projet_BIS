#include <stdlib.h>
#include <stdio.h>
#include "liste_Mouvement.h"


/* Fonction pour créer une nouvelle case */
struct Case * creer_case(int cordx, int cordy, enum Direction sens) {
	
	/* Allocation de mémoire pour la nouvelle case */
	struct Case * c = malloc(sizeof(struct Case));
	
	/* Initialisation des champs de la case */
	c->cordx = cordx;
	c->cordy = cordy;
	c->sens = sens;
	
	c->suivant = NULL;
	
	return c;

}


/* Fonction pour désallouer une case */
void desalouer_case(struct Case ** c) {
	
	/* Vérification de l'existence de la case */
	if (*c != NULL) {
		/* Libération de la mémoire */	
		free(*c);
		*c = NULL;	
	
	}
	
}


/* Fonction pour créer une nouvelle liste de mouvement */
struct Liste_Mouvement * creer_liste_mouvement() {

	/* Allocation de mémoire pour la nouvelle liste de mouvement */
	struct Liste_Mouvement * lm = malloc(sizeof(struct Liste_Mouvement));	
	
	/* Initialisation des champs de la liste */
	lm->premier = NULL;
	lm->dernier = NULL;
	lm->longueur = 0;
		
	return lm;
}


/* Fonction pour vérifier si une liste de mouvement est vide */
int est_vide_lm(struct Liste_Mouvement * lm) {

	return (lm->longueur == 0);
}


/* Fonction pour ajouter une case au début de la liste de mouvement */
void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {

	/* Si la liste est vide, la nouvelle case est également la dernière */
	if (est_vide_lm(lm)) 
		lm->dernier = c;
	
	/* La case pointe vers l'ancienne première case de la liste */
	c->suivant = lm->premier;

	/* La nouvelle case devient la première de la liste */	
	lm->premier = c;

	/* Incrémentation de la longueur de la liste */
	lm->longueur++;

}


/* Fonction pour ajouter une case à la fin de la liste de mouvement */
void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c) {

	/* La nouvelle case n'a pas de case suivante */
	c->suivant = NULL;
	
	/* Si la liste est vide, la nouvelle case est également la première */
	if (est_vide_lm(lm)) {
		lm->premier = c;
	}else {
		/* Sinon, la case suivante de l'ancienne dernière case pointe vers la nouvelle */
		lm->dernier->suivant = c;
	}	
	
	/* La nouvelle case devient la dernière de la liste */
	lm->dernier = c;
	
	/* Incrémentation de la longueur de la liste */
	lm->longueur++;

}


/* Fonction pour extraire une case de la liste de mouvement */
struct Case * extraire_case(struct Liste_Mouvement * lm) {
	
	/* Récupération de la première case de la liste */
	struct Case * c = lm->premier;
	
	if (c != NULL) {
		/* Mise à jour de la première case de la liste */
   		lm->premier = c->suivant;

		/* Décrémentation de la longueur de la liste */
    		lm->longueur--;
    		
		/* Si la liste devient vide, la dernière case est également NULL */
    		if (est_vide_lm(lm)) 
    			lm->dernier = NULL; 

		/* Détachement de la case de la liste */
    		c->suivant = NULL;
	
	}
	
	return c;
}


void desalouer_liste_mouvement(struct Liste_Mouvement ** lm) {

	/*On Vérifie d'abord que l'argument entré correspond à une liste déja allouée dans le tas*/	
	if (*lm != NULL) {
		
		/* Création d'une case temporaire qui va servive à garder une trace de la case libérée*/
		struct Case * c;
		
		/* On libère toutes les cases de la liste une par une*/
		while(!est_vide_lm(*lm)) {
			c = extraire_case(*lm);
		}
		
		/* On libère la case temporaire */
		desalouer_case(&c);
		
		/* On désaloue la liste qui est à présent vide */
		free(*lm);
		*lm = NULL;
	}

}

