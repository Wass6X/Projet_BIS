#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "Fonction_Jeu.h"



int main(int argc, char **  argv) {
	
	int delai;	
	
	struct Grille * g;
	
	struct Serpent * serp;


	if (argc != 4) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (3)\n");
		exit(1);
	}
	
	g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}

	serp = creer_serpent(g->n, g->m);

	delai = atoi(argv[3]);
	
	enum element **M = initaliser_mat(g->n, g->m);

	Jouer_Serpent(g, serp, delai);

	Grille_desallouer(&g);

	printf("\n\nAu revoir !\n");


	return EXIT_SUCCESS;
	
}
