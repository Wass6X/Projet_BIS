#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"
#include"liste_Mouvement.h"


void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai){

        int ch;

	int score=0;
	
	enum Direction sens=NEUTRE;
	
        int couleur, longueur;  
	
        /* Initialisation de ncurses et du clavier*/
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        halfdelay(delai);


        /* initialisation de la grille */
        Grille_tirage_fruit(g);
        Grille_vider(g);
        Grille_remplir_rouge(g, g->cordx, g->cordy); 
        Grille_remplir_serp(g, serp, &sens);  
        Grille_redessiner(g);
        
    	printf("\nVotre score: %d\n", score);
        
        refresh();
         
        while ((ch = getch()) != '#') {
                
                switch (ch) {
                    case KEY_UP:
			if (sens != BAS) {
				ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, HAUT));  
				sens = HAUT;
			}
                        break;
                    case KEY_DOWN:
                        if (sens != HAUT) {
                        	ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, BAS));     
                       		sens = BAS;                   
                        }
                        break;
                    case KEY_LEFT:
             		if (sens != DROITE) {
             		        ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, GAUCHE));           
                        	sens = GAUCHE;             
                        }
                        break;
                    case KEY_RIGHT:
			if (sens != GAUCHE) {
                        	ajout_fin_liste_mouvement(serp->mouvement, creer_case(serp->cordx, serp->cordy, DROITE));                        
                    		sens = DROITE;    
                        }
                        break;
                }
		
		switch (sens) {
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
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                Grille_remplir_serp(g, serp, &sens);
                Grille_redessiner(g);	
               
    		printf("\nVotre score: %d\n", score);
                
                refresh();
        }


        /* Terminer la session ncurses */
        endwin(); 
        
        printf("Game over\n");
        
	printf("Votre score final est de: %d", score);

}

