#ifndef LISTE_SECTION_H
#define LISTE_SECTION_H


/* Définition de la structure Section */
struct Section {
	int taille;				/* Taille de la section */
	int couleur;				/* Couleur de la section */
	struct Section * suivant;		/* Pointeur vers la section suivante */
};

/* Définition de la structure Liste */
struct Liste {
	struct Section * premier;		/* Pointeur vers la première section de la liste */
	struct Section * dernier;		/* Pointeur vers la dernière section de la liste */
	int longueur; 				/* Longueur de la liste */
};

/* Fonction pour créer une nouvelle section */
struct Section * creer_section(int taille, int couleur);

/* Fonction pour désallouer une section */
void desalouer_section(struct Section ** s);

/* Fonction pour créer une nouvelle liste */
struct Liste * creer_liste();

/* Fonction pour vérifier si une liste est vide */
int est_vide(struct Liste * l);

/* Fonction permettant d'ajouter une section au début de la liste */
void ajout_debut_liste(struct Liste * l, struct Section * s);

/* Fonction permettant d'ajouter une section à la fin de la liste */
void ajout_fin_liste(struct Liste * l, struct Section * s);

/* Fonction pour extraire une section de la liste */
struct Section * extraire_section(struct Liste * l);

/* Fonction pour désallouer une liste */
void desalouer_liste(struct Liste ** l);

#endif
