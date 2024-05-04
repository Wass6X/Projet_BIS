#include <stdlib.h>
#include <stdio.h>
#include "Liste_Section.h"


struct section * creer_section(int taille, int couleur) {
	
	struct section * s = malloc(sizeof(struct section *));
	
	s->taille = taille;
	s->couleur = couleur;
	s->suivant = NULL;
	
	return s;

}

void desalouer_section(struct section ** s) {
	
	if (*s == NULL)
		return;
		
	free(*s);
	*s = NULL;
	
}

struct liste * creer_liste() {

	struct liste * l = malloc(sizeof(struct liste));	
	
	l->premier = NULL;
	l->dernier = NULL;
	l->longueur = 0;
		
	return l;
}



void ajout_debut_liste(struct liste * l, struct section * s) {
		
	if (l->longueur == 0) 
		l->dernier = s;
	
	s->suivant = l->premier;
	
	l->premier = s;

	l->longueur++;
}

void ajout_fin_liste(struct liste * l, struct section * s) {
	
	s->suivant = NULL;
	
	if (l->longueur == 0) {
		l->premier = s;
	}else {
		l->dernier->suivant = s;
	}	
	
	l->dernier = s;
	
	l->longueur++;

}

void desalouer_liste(struct liste ** l) {

	/*On Vérifie d'abord que l'argument entré correspond à une liste déja allouée dans le tas*/	
	if (*l != NULL) {
		
		/* Création d'une section temporaire qui va servive à garder une trace de la section libérée*/
		struct section * s;
		
		/* On libère toutes les sections de la liste une par une*/
		
		while((*l)->longueur > 0) {
			s = (*l)->premier;
			desalouer_section(&(*l)->premier);
			(*l)->premier = s->suivant;
			(*l)->longueur--;
		}
		
		/* On libère la section temporaire */
		desalouer_section(&s);
		
		/* On désaloue la liste qui est à présent vide */
		free(*l);
		*l = NULL;
		
	}
}
