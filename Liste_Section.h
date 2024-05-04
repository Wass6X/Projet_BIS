#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H


struct section {
	int taille;
	int couleur;
	struct section * suivant;
};

struct liste {
	struct section * premier;
	struct section * dernier;
	int longueur; 
};

struct section * creer_section(int taille, int couleur);

void desalouer_section(struct section ** s);

struct liste * creer_liste();

/* Fonction permettant d'ajouter une section au début de la liste */
void ajout_debut_liste(struct liste * l, struct section * s);

/* Fonction permettant d'ajouter une section à la fin de la liste */
void ajout_fin_liste(struct liste * l, struct section * s);

void desalouer_liste(struct liste ** l);

#endif
