#include "Grille.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **  argv) {
	
	int n, m;	
	
	struct Grille * g;
	
	if (argc != 3) {
		fprintf(stderr, "Veuillez entrer le \n");
		exit(1);
	}
	
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	
	if ((n < 0) || (m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}
	
	g = Grille_allouer(n, m);
	
	Grille_vider(g);
	
	Grille_tirage_fruit(g);
	
	
	return EXIT_SUCCESS;
}
