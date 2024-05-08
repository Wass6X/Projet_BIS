#include <stdlib.h>
#include <stdio.h>
#include "liste_Section.h"


struct Section * creer_section(int taille, int couleur) {
	
	struct Section * s = malloc(sizeof(struct Section));
	
	s->taille = taille;
	s->couleur = couleur;
	s->suivant = NULL;
	
	return s;

}

void desalouer_section(struct Section ** s) {
	
	if (*s != NULL) {
			
		free(*s);
		*s = NULL;	
	
	}
	
}

struct Liste * creer_liste() {

	struct Liste * l = malloc(sizeof(struct Liste));	
	
	l->premier = NULL;
	l->dernier = NULL;
	l->longueur = 0;
		
	return l;
}

int est_vide(struct Liste * l) {
	return (l->longueur == 0);
}

void ajout_debut_liste(struct Liste * l, struct Section * s) {
		
	if (est_vide(l)) 
		l->dernier = s;
	
	s->suivant = l->premier;
		
	l->premier = s;

	l->longueur++;
}

void ajout_fin_liste(struct Liste * l, struct Section * s) {
	
	s->suivant = NULL;
	
	if (est_vide(l)) {
		l->premier = s;
	}else {
		l->dernier->suivant = s;
	}	
	
	l->dernier = s;
	
	l->longueur++;

}

struct Section * extraire_section(struct Liste * l) {
	
	struct Section * s = l->premier;
	
	if (s != NULL) {
	
   		l->premier = s->suivant;
    	
    		l->longueur--;
    		
    		if (est_vide(l)) 
    			l->dernier = NULL; 
    
    		s->suivant = NULL;
	
	}
	
	return s;
}


void desalouer_liste(struct Liste ** l) {

	/*On Vérifie d'abord que l'argument entré correspond à une liste déja allouée dans le tas*/	
	if (*l != NULL) {
		
		/* Création d'une section temporaire qui va servive à garder une trace de la section libérée*/
		struct Section * s;
		
		/* On libère toutes les sections de la liste une par une*/
		
		while(!est_vide(*l)) {
			s = extraire_section(*l);
		}
		
		/* On libère la section temporaire */
		desalouer_section(&s);
		
		/* On désaloue la liste qui est à présent vide */
		free(*l);
		*l = NULL;
		
	}
}
