#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"

struct Grille * Grille_allouer(int n, int m){
        
        int i, j;
        
        struct Grille *g = malloc(sizeof(struct Grille));
        
        g->n = n;
        g->m = m;

        g->tab = malloc(8 * sizeof(char **));
	
	for (i=0; i<n; i++) {
		g->tab[i] = malloc(m * sizeof(char*));		
		for (j=0; j<m; j++) {
			g->tab[i][j] = malloc(8 * sizeof(char));
		}
	}	

	return g;
	
}

void Grille_tirage_fruit(struct Grille *g){
        g->cordx = rand()%g->n;
        g->cordy = rand()%g->m;
}


