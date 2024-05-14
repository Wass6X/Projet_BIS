#ifndef LISTE_MOUVEMENT_H
#define LISTE_MOUVEMENT_H

enum Direction { HAUT, BAS, GAUCHE, DROITE, NEUTRE};

struct Case {
	int cordx;
	int cordy;
	enum Direction sens;
	struct Case * suivant;
};

struct Liste_Mouvement {
	struct Case * premier;
	struct Case * dernier;
	int longueur;		
};

struct Case * creer_case(int cordx, int cordy, enum Direction sens);

void desalouer_case(struct Case ** c);

struct Liste_Mouvement * creer_liste_mouvement();

int est_vide_lm(struct Liste_Mouvement * lm);

/* Fonction permettant d'ajouter une section au début de la liste */
void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

/* Fonction permettant d'ajouter une section à la fin de la liste */
void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

struct Case * extraire_case(struct Liste_Mouvement * lm);

void desalouer_liste_mouvement(struct Liste_Mouvement ** lm);


#endif
