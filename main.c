#include "Grille.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **  argv) {
	
	int n, m;	
	
	struct Grille * g;
	
	if (argc != 3) {
		fprintf(strderr, "Veuillez entrer le \n");
		exit(1);
	}
	
	n = atoi(arvg[1]);
	m = atoi(arvg[2]);
	
	if ((n < 0) || (m<0)) {
		fprintf(strderr, "Un des arguments est négatif\n");
		exit(1);
	}
	
	g = Grille_allouer(n, m);
	
	Grille_vider(g);
	
	Grille_tirage_fruit(g);
	
	
	
	return EXIT_SUCCESS;
}
