#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"

struct Grille * Grille_allouer(int n, int m){
        
        int i;
        
        struct Grille *g = malloc(sizeof(struct Grille));
        
        g->n = n;
        g->m = m;
        g->tab = malloc(n * sizeof(char *));

        
        g->tab = malloc(8 * sizeof(char *));
	
	for (i=0; i<m; i++) {
		tab[i] = malloc(8 * sizeof(char));		
	}	


}

struct Grille vider 