#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"


struct Grille * Grille_allouer(int n, int m){
        
        int i, j;
        
        struct Grille *g = malloc(sizeof(struct Grille));
        
        g->n = n;
        g->m = m;

        g->tab = malloc(n * sizeof(char **));
	
	for (i=0; i<n; i++) {
		g->tab[i] = malloc(m * sizeof(char*));		
		for (j=0; j<m; j++) {
			g->tab[i][j] = malloc(8 * sizeof(char));
		}
	}	
	
	g->cordx=0;
	g->cordy=0;


	return g;	
	
}


void Grille_vider(struct Grille * g) {

	int i, j;
	
	for (i=0; i<g->n; i++) {
		for (j=0; j<g->m; j++) {
			g->tab[i][j] = "\x1b[40m  \x1b[0m";	
		}
	}
}


void Grille_remplir(struct Grille * g) {

	int i, j;
	
	for (i=0; i<g->n; i++) {
		for (j=0; j<g->m; j++) {
			g->tab[i][j] = "\x1b[41m  \x1b[0m";	
		}
	}
}


void Grille_desallouer(struct Grille ** g) {

	int i, j;
	
	for (i=0; i<*g->n; i++) {
		for (j=0; j<*g->m; j++) {
			free(*g->tab[i][j]);
			*g->tab[i][j] = NULL;
		}
		
		free(*g->tab[i]);
		*g->tab[i] = NULL;
	}	
	
	/*à voir si c'est utile:
		free(g->tab);
		g->tab = NULL;
		
		**parceque on a tab = tab[0]
	*/
	
	/* à voir cette partie aussi */	
	free(*g);
	*g = NULL;
	
}



