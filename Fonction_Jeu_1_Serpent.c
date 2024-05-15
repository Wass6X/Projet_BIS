#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"
#include"liste_Mouvement.h"


void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai, enum element **M){

        int ch;

	int score=0;
	
        int couleur, longueur;  
	
        /* Initialisation de ncurses et du clavier */
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        halfdelay(delai);


        /* initialisation de la grille */
        Grille_tirage_fruit(g);
        Grille_vider(g);
        reset_mat(M, g->n, g->m);
        Grille_remplir_rouge(g, g->cordx, g->cordy); 
        Grille_remplir_serp(g, serp);  
        Grille_redessiner(g);
        
    	printf("\nVotre score: %d\n", score);
        
        refresh();
         
        while ((ch = getch()) != '#') {
                
                
                
                switch (ch) {
                    case KEY_UP:
			if (serp->mouvement->premier->sens != BAS) 
				ajout_debut_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, HAUT));  
			
                        break;
                        
                    case KEY_DOWN:
                        if (serp->mouvement->premier->sens != HAUT) 
                        	ajout_debut_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, BAS)); 
                        
                        break;
                        
                    case KEY_LEFT:
             		if (serp->mouvement->premier->sens != DROITE) 
             		        ajout_debut_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, GAUCHE));           
                        
                        break;
                        
                    case KEY_RIGHT:
			if (serp->mouvement->premier->sens != GAUCHE) 
                        	ajout_debut_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, DROITE));                        
                        
                        break;
                }
		
		switch (serp->mouvement->premier->sens) {
                    	case HAUT:
				serp->cordy--;
                        	break;
                        case BAS:
				serp->cordy++;
                        	break;
                    	case DROITE:
				serp->cordx++;
                        	break;
                    	case GAUCHE:
				serp->cordx--;
                       		break;
		}
                
                /* Vérifier la collision avec le bord */
                if (serp->cordx < 0 || serp->cordx >= g->m || serp->cordy < 0 || serp->cordy >= g->n) {
                    break;  
                }

                /* Vérifier la collision avec le fruit */
                if (serp->cordx == g->cordx && serp->cordy == g->cordy) {
                	
			longueur = (rand() % 2) + 1;
			couleur = (rand() % 6) + 41;
                    
                    	ajout_fin_liste(serp->chaine, creer_section(longueur, couleur));
                    	
                    	Grille_tirage_fruit(g);  
			
			score++;	
                }
                
		
                Grille_vider(g);
		reset_mat(M, g->n, g->m);
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                Grille_remplir_serp(g, serp);
                Grille_redessiner(g);	
               
    		printf("\nVotre score: %d\n", score);
                
                refresh();
        }


        /* Terminer la session ncurses */
        endwin(); 
        
        printf("Game over\n");
        
	printf("Votre score final est de: %d", score);

}

