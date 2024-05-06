#include <stdlib.h>
#include <stdio.h>
#include "Grille.h"
#include "Serpent.h"

int main(int argc, char **  argv) {
		
	struct Grille * g;
	
	struct serpent * serp;
	
	if (argc != 3) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (2)\n");
		exit(1);
	}
	
	g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

	
	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}
	
	Grille_vider(g);
	
	Grille_tirage_fruit(g);
	
	Grille_remplir_rouge(g, g->cordx, g->cordy);
	
	Grille_redessiner(g);
	
	serp = creer_serpent(g->n, g->m);
	
	Grille_remplir_serp(g, serp);
	
	/* Grille_desallouer(&g); */
	
	printf("\n");
	
	return EXIT_SUCCESS;
}
