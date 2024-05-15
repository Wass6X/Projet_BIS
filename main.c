#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "Fonction_Jeu.h"


/* Fonction principale du jeu */
int main(int argc, char **  argv) {
	
	int delai;	
	
	struct Grille * g;		/* Déclaration de la grille */
	
	struct Serpent * serp;		 /* Déclaration du serpent */


	/* Vérification du nombre d'arguments */
	if (argc != 4) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (3)\n");
		exit(1);
	}
	

	/* Allocation de mémoire pour la grille avec les dimensions spécifiées */
	g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

	/* Vérification que les dimensions de la grille sont positives */
	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}


	/* Création du serpent avec les dimensions de la grille */
	serp = creer_serpent(g->n, g->m);


	/* Récupération du délai passé en argument */
	delai = atoi(argv[3]);
	

	/* Initialisation de la matrice représentant la grille */
	enum element **M = initialiser_mat(g->n, g->m);


	/* Lancement du jeu avec le serpent et la grille */
	Jouer_Serpent(g, serp, delai, M);


	/* Désallocation de la mémoire allouée pour la grille */
	Grille_desallouer(&g);


	/* Affichage d'un message de fin */
	printf("\n\n Au revoir !\n\n");


	/* Sortie du programme avec succès */
	return EXIT_SUCCESS;

}
