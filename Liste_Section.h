#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H


struct section {
	int taille;
	int couleur;
	struct section * suivant;
};

struct liste_section {
	struct section * premiere;
	struct section * derniere;
	int longueur; 
};

struct section * creer_section(int taille, int couleur);

struct section * desalouer_section(struct section ** s);

#endif
