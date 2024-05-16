#ifndef LISTE_MOUVEMENT_H
#define LISTE_MOUVEMENT_H

/* Définition de l'énumération Direction */
enum Direction { HAUT, BAS, GAUCHE, DROITE, NEUTRE};


/* Définition de la structure Case */
struct Case {
	int cordx;			/* Coordonnée x de la case */
	int cordy;			/* Coordonnée y de la case */
	enum Direction sens;		/* Direction associée à la case */
	struct Case * suivant;		/* Pointeur vers la case suivante */
};


/* Définition de la structure Liste_Mouvement */
struct Liste_Mouvement {
	struct Case * premier;		/* Pointeur vers la première case de la liste */
	struct Case * dernier;		/* Pointeur vers la dernière case de la liste */
	int longueur;			 /* Longueur de la liste */
};

/* Fonction pour créer une nouvelle case */
struct Case * creer_case(int cordx, int cordy, enum Direction sens);

/* Fonction pour désallouer une case */
void desalouer_case(struct Case ** c);

/* Fonction pour créer une nouvelle liste de mouvement */
struct Liste_Mouvement * creer_liste_mouvement();

/* Fonction pour vérifier si une liste de mouvement est vide */
int est_vide_lm(struct Liste_Mouvement * lm);

/* Fonction permettant d'ajouter une section au début de la liste */
void ajout_debut_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

/* Fonction permettant d'ajouter une section à la fin de la liste */
void ajout_fin_liste_mouvement(struct Liste_Mouvement * lm, struct Case * c);

/* Fonction pour extraire une case de la liste de mouvement */
struct Case * extraire_case(struct Liste_Mouvement * lm);

/* Fonction pour désallouer une liste de mouvement */
void desalouer_liste_mouvement(struct Liste_Mouvement ** lm);

#endif
