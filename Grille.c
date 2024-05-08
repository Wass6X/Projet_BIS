#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"

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
			strcpy(g->tab[i][j], "\033[40m  ");	
		}
	}
}

void Grille_tirage_fruit(struct Grille *g){
       
       srand(time(NULL));
       
        g->cordx = rand() % g->n;
        g->cordy = rand() % g->m;
        
}



void Grille_remplir_rouge(struct Grille * g, int x, int y) {
	strcpy(g->tab[x][y], "\033[101m  ");	
}


void Grille_desallouer(struct Grille ** g) {

	int i, j;	
	
	if (*g == NULL)
       		return;
	
	for (i=0; i<(*g)->n; i++) {
		for (j=0; j<(*g)->m; j++) {
			free((*g)->tab[i][j]);
			(*g)->tab[i][j] = NULL;
		}
		
		free((*g)->tab[i]);
		(*g)->tab[i] = NULL;
	}
	
	
	free(*g);
	*g = NULL;
}

void Grille_redessiner(struct Grille *g){

	int i,j;

	printf("\033[2J");
	printf("\033[H");
	
	for (j=0; j<g->m+2; j++) {
		printf("\033[42m  ");
       	}
	
	printf("\033[1E");
	
	for (i=0; i<g->n; i++) {
		printf("\033[42m  ");
		for (j=0; j<g->m; j++) {
                	printf("%s\033[0m", g->tab[i][j]);
		}
		printf("\033[42m  ");
		printf("\033[1E"); 
	}
	
	for (j=0; j<g->m+2; j++) {
		printf("\033[42m  ");
	}
	
	printf("\033[0m\n");

}

void Grille_remplir_couleur(struct Grille * g, int x, int y, int couleur) {
	
	if (couleur>39 && couleur<48){
		snprintf(g->tab[x][y], 8, "\033[%dm  ", couleur);
	}
}


void Grille_remplir_serp(struct Grille * g, struct Serpent * serp) {
	
	int i=0, j;
	int stop = 0;
	
	struct Section * s;
	
	serp = creer_serpent(g->n, int g->m);


	if (g == NULL || serp == NULL || est_vide(serp->chaine))
        	return;
	

	while(!(est_vide(serp->chaine)) && !(stop)) {
		
		s = extraire_section(serp->chaine);
		
		for(j=0; (j<s->taille) && !(stop); j++) {
		
			if (serp->cordy+i < g->m){	
				Grille_remplir_couleur(g, serp->cordx, serp->cordy + i, s->couleur);			
				i++;	
			}
			
			else
				stop=1;
			
		}
			
	}
	
	desalouer_section(&s);
		

}


// simplification de grille remplir pour une seule case
/*void Grille_remplir_serp(struct Grille * g, struct Serpent * serp) {
    
    Grille_remplir_couleur(g, section->x, section->y, s->couleur);

}*/
