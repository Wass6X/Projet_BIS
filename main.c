#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Fonction_Jeu.h"
#include "Grille.h"
#include "Serpent.h"
#include "liste_Section.h"



int main(int argc, char **  argv) {
		
	struct Grille * g;
	
	struct Serpent * serp;
	
	if (argc != 5) {
		fprintf(stderr, "Veuillez entrer le bon nombre d'argumets (4)\n");
		exit(1);
	}
	
	g = Grille_allouer(atoi(argv[1]), atoi(argv[2]));

	
	if ((g->n < 0) || (g->m<0)) {
		fprintf(stderr, "Un des arguments est négatif\n");
		exit(1);
	}

	

  	/* Initialisation de ncurses et du clavier(4 lignes)*/
  	initscr();
	raw();            
    	noecho();             
    	keypad(stdscr, TRUE); 


  	halfdelay(atoi(argv[3])); 
	
	
	Grille_tirage_fruit(g);
	
	Grille_remplir_rouge(g, g->cordx, g->cordy);
	
	serp = creer_serpent(g->n, g->m);
	
	Grille_remplir_serp(g, serp);
	
	Grille_redessiner(g);

	Jouer_Serpent(g, serp);
	

	printf("\n\nAu revoir !\n");
	
	return EXIT_SUCCESS;
}
