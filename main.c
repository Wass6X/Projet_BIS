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
	
	/* Déclaration des serpent */
	struct Serpent * serp;		 
	struct Serpent * serp1;	
	struct Serpent * serp2;

	/* Vérification du nombre d'arguments */
	if (argc != 5) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (4)\n");
		exit(1);
	}
	

	/* Allocation de mémoire pour la grille avec les dimensions spécifiées */
	g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

	/* Vérification que les dimensions de la grille sont positives */
	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}

	/* Récupération du délai passé en argument */
	delai = atoi(argv[3]);
	

	/* Initialisation de la matrice représentant la grille */
	enum element **M = initialiser_mat(g->n, g->m);

	/* Lancement du jeu avec un serpent */
	if(atoi(argv[4])==1){
		serp1 = creer_serpent(g->n, g->m);
		Jouer_Serpent(g, serp, delai, M);
	}

	/* Lancement du jeu avec deux serpent */
	if(atoi(argv[4])==2){
		serp1 = creer_serpent(g->n, g->m);
		serp2 = creer_serpent_2(g->n, g->m);
		Jouer_Serpent_2(g, serp1, serp2, delai, M);
	}

	/* Désallocation de la mémoire allouée pour la grille */
	Grille_desallouer(&g);


	/* Affichage d'un message de fin */
	printf("\n\n Au revoir !\n\n");


	/* Sortie du programme avec succès */
	return EXIT_SUCCESS;

}
