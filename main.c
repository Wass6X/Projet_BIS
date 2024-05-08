#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"
#include "Fonction_jeu.h"



int main(int argc, char **  argv) {

		
	struct Grille * g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));
	
	struct Serpent * serp = creer_serpent(g->n, g->m);


	if (argc != 3) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (2)\n");
		exit(1);
	}
	

	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}


	int delai = atoi(argv[3]);


	
	Grille_tirage_fruit(g);

	Grille_vider(g);

	Grille_remplir_rouge(g, g->cordx, g->cordy);

	Grille_remplir_serp(g, serp);

    	Grille_redessiner(g);

	Jouer_Serpent(g, serp, delai);

	printf("\n\nAu revoir !\n");

	
	return EXIT_SUCCESS;
}
