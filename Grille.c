#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Grille.h"
#include "liste_Mouvement.h"

/* Fonction pour allouer une nouvelle grille */
struct Grille * Grille_allouer(int n, int m){
        
        int i, j;
        
	/* Allocation de mémoire pour la structure Grille */
        struct Grille *g = malloc(sizeof(struct Grille));
        
        g->n = n;
        g->m = m;
	
	/* Allocation de mémoire pour le tableau à trois dimensions */
        g->tab = malloc(n * sizeof(char **));

	/* Allocation de mémoire pour chaque case du tableau */
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


/* Fonction pour vider la grille */
void Grille_vider(struct Grille * g) {

	int i, j;
	
	for (i=0; i<g->n; i++) {
		for (j=0; j<g->m; j++) {
			/* Remplissage des cellules avec un espace noir */
			strcpy(g->tab[i][j], "\033[40m  ");	
		}
	}
}


/* Fonction pour placer un fruit aléatoirement sur la grille */
void Grille_tirage_fruit(struct Grille *g, enum element **M){
       
	srand(time(NULL));

	do {
		g->cordx = rand() % g->m;
        	g->cordy = rand() % g->n;
        	
	} while(M[g->cordy][g->cordx] == Corp_serp);
	
}


/* Fonction pour remplir une cellule de la grille en rouge */
void Grille_remplir_rouge(struct Grille * g, int x, int y) {
	strcpy(g->tab[y][x], "\033[101m00");	
}


/* Fonction pour désallouer la mémoire occupée par la grille */
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


/* Fonction pour redessiner la grille */
void Grille_redessiner(struct Grille *g){

	int i,j;

	/* Effacer l'écran */
	printf("\033[2J");
	printf("\033[H");
	
	/* Dessiner la bordure supérieure */
	for (j=0; j<g->m+2; j++) {
		printf("\033[42m🔵");
       	}
	
	printf("\033[1E");
	
	/* Remplissage des cellules de la grille */
	for (i=0; i<g->n; i++) {
		printf("\033[42m🔵");
		for (j=0; j<g->m; j++) {
                	printf("%s\033[0m", g->tab[i][j]);
		}
		printf("\033[42m🔵");   /*▢▢*/
		printf("\033[1E"); 
	}

	/* Dessiner la bordure inférieure */
	for (j=0; j<g->m+2; j++) {
		printf("\033[42m🔵");
	}
	
	printf("\033[1E"); 
	printf("\033[1E"); 
	
}


/* Fonction pour remplir une cellule de la grille avec une couleur spécifique */
void Grille_remplir_couleur(struct Grille * g, int x, int y, int couleur) {
	
	if (couleur>40 && couleur<48 && x>=0 && x<g->m && y>=0 && y<g->n){
		
		sprintf(g->tab[y][x], "\033[%dm++", couleur);			/* Affichage du corp du serpent */

	}

}


/* Fonction pour initialiser une matrice d'éléments */
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



/* Fonction pour réinitialiser une matrice d'éléments */
void reset_mat(enum element  **M, int n, int m) {
    	int i,j;

	for (i=0; i<n; i++) {
        	for (j=0; j<m; j++) {
            		M[i][j] = Rien;
        	}
    	}
}



/* Fonction pour remplir la grille avec les éléments du serpent */	
int Grille_remplir_serp(struct Grille * g, struct Serpent * serp, enum element **M) {
        
        int i, x=serp->cordx, y=serp->cordy;
       
       	struct Section * s = serp->chaine->premier;
       	struct Case * c = serp->mouvement->premier;
       
        if (g == NULL || serp == NULL || est_vide(serp->chaine))
                return 0;
        
        while (s != NULL) {
		for (i = 0; i < s->taille; i++) {	
	        	
	        	
			if (c->suivant!=NULL) {
	        		if (c->cordx==x && c->cordy==y)
					c = c->suivant;
					
	        	}
	        	
	        	
			/* Vérifier la colliision avec lui-meme*/
			if(M[y][x] == Corp_serp) {
				return 1;
			}else{
				M[y][x] = Corp_serp;
				
				if (y==serp->cordy && x==serp->cordx)
					sprintf(g->tab[serp->cordy][serp->cordx], "\033[41m<>");
				
				else
					Grille_remplir_couleur(g, x, y, s->couleur);
			}
			
	        	
	        	switch (c->sens) {
                              
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
				default:
					break;	
			}
		
		}
		
		s = s->suivant;
	
	}

	return 0;
}


/* Fonction pour remplir la grille avec les éléments des deux serpent */	
int Grille_remplir_serp_2(struct Grille * g, struct Serpent * serp1, struct Serpent * serp2, enum element **M) {
        
        int i, x=serp1->cordx, y=serp1->cordy;
	int x2=serp2->cordx, y2=serp2->cordy;
       
       	struct Section * s = serp1->chaine->premier;
       	struct Case * c = serp1->mouvement->premier;

	struct Section * s2 = serp2->chaine->premier;
       	struct Case * c2 = serp2->mouvement->premier;
       
        if (g == NULL || serp1 == NULL || est_vide(serp1->chaine) || serp2 == NULL || est_vide(serp2->chaine))
                return 0;
        
        while (s != NULL) {
		for (i = 0; i < s->taille; i++) {	
	        	
	        	
			if (c->suivant!=NULL) {
	        		if (c->cordx==x && c->cordy==y)
					c = c->suivant;
					
	        	}
	        	
	        	
			/* Vérifier la colliision avec lui-meme*/
			if(M[y][x] == Corp_serp) {
				return 1;
			}else{
				M[y][x] = Corp_serp;
				
				if (y==serp1->cordy && x==serp1->cordx)
					sprintf(g->tab[serp1->cordy][serp1->cordx], "\033[41m<>");
				
				else
					Grille_remplir_couleur(g, x, y, s->couleur);
			}
			
	        	
	        	switch (c->sens) {
                              
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
				default:
					break;	
			}
		
		}
		
		s = s->suivant;
	
	}

	while (s2 != NULL) {
		for (i = 0; i < s2->taille; i++) {	
	        	
	        	
			if (c2->suivant!=NULL) {
	        		if (c2->cordx==x2 && c2->cordy==y2)
					c2 = c2->suivant;
					
	        	}
	        	
	        	
			/* Vérifier la colliision avec lui-meme*/
			if(M[y2][x2] == Corp_serp) {
				return 2;
			}else{
				M[y2][x2] = Corp_serp;
				
				if (y2==serp2->cordy && x2==serp2->cordx)
					sprintf(g->tab[serp2->cordy][serp2->cordx], "\033[43m<>");
				
				else
					Grille_remplir_couleur(g, x2, y2, s2->couleur);
			}
			
	        	
	        	switch (c2->sens) {
                              
				case HAUT:
					y2++;
					break;
                                
				case BAS:
					y2--;
					break;
				
				case GAUCHE:
					x2++;
					break;
				
				case DROITE:
					x2--;
					break;
				default:
					break;	
			}
		
		}
		
		s2 = s2->suivant;
	
	}


	return 0;

}
