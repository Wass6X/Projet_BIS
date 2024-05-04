#include <stdlib.h>
#include <stdio.h>
#include "Liste_Section.h"


struct section * creer_section(int taille, int couleur) {
	
	struct section * s = malloc(sizeof(struct section *));
	
	s->taille = taille;
	s->couleur = couleur;
	
	return s;

}

struct section * desalouer_section(struct section ** s) {
	
	if (*s == NULL)
		return;
		
	free(*s);
	
	*s == NULL;

}
