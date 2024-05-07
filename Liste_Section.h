#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H


struct Section {
	int taille;
	int couleur;
	struct Section * suivant;
};

struct Liste {
	struct Section * premier;
	struct Section * dernier;
	int longueur; 
};

struct Section * creer_section(int taille, int couleur);

void desalouer_section(struct Section ** s);

struct Liste * creer_liste();

int est_vide(struct Liste * l);

/* Fonction permettant d'ajouter une section au début de la liste */
void ajout_debut_liste(struct Liste * l, struct Section * s);

/* Fonction permettant d'ajouter une section à la fin de la liste */
void ajout_fin_liste(struct Liste * l, struct Section * s);

struct Section * extraire_section(struct Liste * l);

void desalouer_liste(struct Liste ** l);

#endif
