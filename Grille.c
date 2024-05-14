#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Grille.h"
#include "liste_Mouvement.h"

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
       
        g->cordx = rand() % g->m;
        g->cordy = rand() % g->n;
        
}



void Grille_remplir_rouge(struct Grille * g, int x, int y) {
	strcpy(g->tab[y][x], "\033[101m  ");	
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
	
	if (couleur>40 && couleur<48 && x >= 0 && x<g->m && y >= 0 &&y<g->n){
		snprintf(g->tab[y][x], 8, "\033[%dm  ", couleur);
	}
}


enum element **initialiser_mat(int n, int m){
        enum element **M = malloc(n * sizeof(enum element *));

        int i,j;

        for(i=0; i<=n; i++){
                M[i] = malloc(m * sizeof(enum element));
                for (j = 0; j < m; j++) {
                        M[i][j] = Rien;
                }
        }
	return M;

}

	
void Grille_remplir_serp(struct Grille * g, struct Serpent * serp, enum Direction * sens, enum element **M) {
        
        int i, x=serp->cordx, y=serp->cordy;
        int change = 0;
       
       	struct Section * s = serp->chaine->premier;
       	struct Case * c = serp->mouvement->premier;
       
        if (g == NULL || serp == NULL || est_vide(serp->chaine))
                return;
	
        while (s != NULL) {
		for (i = 0; i < s->taille; i++) {	
	        	
	        	if (c!=NULL && x==c->cordx && y==c->cordy && (!change)) {
	        		*sens = c->sens;
	        		c = c->suivant;
	        		change = 1;
	        	}

	        	
			/* Vérifier la collision avec lui-même */
            		if (M[y][x] == Corp_serp) {
                		printf("Collision détectée! Le jeu est terminé.\n");
                		exit(EXIT_FAILURE);
            		}else{
                		M[y][x] = Corp_serp; 
               			Grille_remplir_couleur(g, x, y, s->couleur);
           		} 

	        	
			switch (*sens) {
                              
				case HAUT:
					y++;
					break;
                                
				case BAS:
					y--;
					break;
				
				case GAUCHE:
					x++;
					break;
				
				case DROITE:
					x--;
					break;
					
			}
		
		}
		s = s->suivant;
	}
	
}
