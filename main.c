#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Fonction_Jeu.h"
#include "Grille.h"
#include "Serpent.h"
#include "Liste_Section.h"



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
  	initscr();            // Initialise l'écran avec ncurses
    	cbreak();             // Les entrées au clavier sont disponibles immédiatement
    	noecho();             // Les entrées clavier ne sont pas affichées à l'écran
    	keypad(stdscr, TRUE); // Permet d'utiliser les touches fléchées


  	halfdelay(atoi(argv[3])); 
	
	Grille_vider(g);
	
	Grille_tirage_fruit(g);
	
	Grille_remplir_rouge(g, g->cordx, g->cordy);
	
	serp = creer_serpent(g->n, g->m);
	
	Grille_remplir_serp(g, serp);
	
	Grille_redessiner(g);

	Jouer_Serpent(g, serp);
	
	Grille_desallouer(&g);

	
	endwin(); /* Doit obligatoirement etre mis en fin de programme pour remettre le terminal en etat */
  
  	printf("\n\nAu revoir !\n");
	
	
	return EXIT_SUCCESS;
}
