#include <stdlib.h>
#include <stdio.h>
#include "liste_Section.h"


/* Fonction pour créer une nouvelle section */
struct Section * creer_section(int taille, int couleur) {
	
	/* Allocation de mémoire pour la nouvelle section */
	struct Section * s = malloc(sizeof(struct Section));
	
	/* Initialisation des champs de la section */
	s->taille = taille;
	s->couleur = couleur;
	s->suivant = NULL;
	
	return s;

}


/* Fonction pour désallouer une section */
void desalouer_section(struct Section ** s) {
	
	/* Vérification de l'existence de la section */
	if (*s != NULL) {
		/* Libération de la mémoire */	
		free(*s);
		*s = NULL;	
	
	}
	
}

/* Fonction pour créer une nouvelle liste */
struct Liste * creer_liste() {

	/* Allocation de mémoire pour la nouvelle liste */
	struct Liste * l = malloc(sizeof(struct Liste));	
	
	/* Initialisation des champs de la liste */
	l->premier = NULL;
	l->dernier = NULL;
	l->longueur = 0;
		
	return l;
}


/* Fonction pour vérifier si une liste est vide */
int est_vide(struct Liste * l) {
	return (l->longueur == 0);
}


/* Fonction pour ajouter une section au début de la liste */
void ajout_debut_liste(struct Liste * l, struct Section * s) {
	
	/* Si la liste est vide, la nouvelle section est également la dernière */	
	if (est_vide(l)) 
		l->dernier = s;
	
	/* La section pointe vers l'ancienne première section de la liste */
	s->suivant = l->premier;

	/* La nouvelle section devient la première de la liste */	
	l->premier = s;

	/* Incrémentation de la longueur de la liste */
	l->longueur++;
}


/* Fonction pour ajouter une section à la fin de la liste */
void ajout_fin_liste(struct Liste * l, struct Section * s) {
	
	/* La nouvelle section n'a pas de section suivante */
	s->suivant = NULL;
	
	/* Si la liste est vide, la nouvelle section est également la première */
	if (est_vide(l)) {
		l->premier = s;
	}else {
		/* Sinon, la section suivante de l'ancienne dernière section pointe vers la nouvelle */
		l->dernier->suivant = s;
	}	
	
	/* La nouvelle section devient la dernière de la liste */
	l->dernier = s;
	
	/* Incrémentation de la longueur de la liste */
	l->longueur++;

}

/* Fonction pour extraire une section de la liste */
struct Section * extraire_section(struct Liste * l) {
	
	/* Récupération de la première section de la liste */
	struct Section * s = l->premier;
	
	if (s != NULL) {
		
		/* Mise à jour de la première section de la liste */
   		l->premier = s->suivant;

		/* Décrémentation de la longueur de la liste */
    		l->longueur--;
    		
		/* Si la liste devient vide, la dernière section est également NULL */
    		if (est_vide(l)) 
    			l->dernier = NULL; 

		/* Détachement de la section de la liste */
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
