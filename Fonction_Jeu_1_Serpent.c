#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"
#include"liste_Mouvement.h"


/* Fonction principale pour jouer au serpent */
void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai, enum element **M){

        int ch;                         /* Variable pour stocker la touche pressée par l'utilisateur */

	int score=0;                    /* Variable pour stocker le score */
	
        int couleur, longueur;          /* Variables pour la couleur et la longueur d'une nouvelle section du serpent */
	
	int touche;                     /* Variable pour détecter si le serpent entre en collision avec lui-même ou le bord de la grille */
	
      
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
        Grille_remplir_serp(g, serp, M);  
        Grille_redessiner(g);
        
    	printf("Votre score: %d \033[1E", score);
    	
	printf("\033[0m\n");
        
        refresh();
         
        /* Boucle principale du jeu */ 
        while ((ch = getch()) != '#') {
                
                /* Gestion des déplacements du serpent en fonction des touches pressées */
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
		
                /* Mise à jour de la position du serpent en fonction de son dernier mouvement */
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
                        default:
                                break;
		}
                
                /* Vérifier la collision avec le bord */
                if (serp->cordx < 0 || serp->cordx >= g->m || serp->cordy < 0 || serp->cordy >= g->n) {
                    break;  
                }

                /* Vérifier la collision avec le fruit */
                if (serp->cordx == g->cordx && serp->cordy == g->cordy) {
                	
                        /* Ajout d'une nouvelle section au serpent */
			longueur = (rand() % 2) + 1;
			couleur = (rand() % 6) + 41;
                    
                    	ajout_fin_liste(serp->chaine, creer_section(longueur, couleur));
                    	
                    	Grille_tirage_fruit(g);  
			
			score++;	
                }
                
		/* Mise à jour de la grille */
                Grille_vider(g);
		reset_mat(M, g->n, g->m);
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                touche = Grille_remplir_serp(g, serp, M);
                
                if(touche == 1){
                	break;	
                }
                
                Grille_redessiner(g);	
               
    		printf("\033[0m Votre score: %d \033[1E\033[0m\n", score);
                
                refresh();
        }


        /* Terminer la session ncurses */
        endwin(); 
        
        Grille_vider(g);
	reset_mat(M, g->n, g->m);
        Grille_remplir_rouge(g, g->cordx, g->cordy);  
        touche = Grille_remplir_serp(g, serp, M);
        Grille_redessiner(g);	
               

        /* Affichage du message de fin */
        printf("\033[0m Game over\n");
        printf("\033[0m Votre score final est de: %d", score);

}

