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
void Jouer_Serpent_2(struct Grille *g, struct Serpent *serp1, struct Serpent *serp2, int delai, enum element **M){

        int ch;                         /* Variable pour stocker la touche pressée par l'utilisateur */

	int score1=0, score2=0;         /* Variable pour stocker les score */
	
        int couleur, longueur;          /* Variables pour la couleur et la longueur d'une nouvelle section du serpent */
	
	int touche1=0, touche2=0;                 
	
	int perd = 0;
      
        /* Initialisation de ncurses et du clavier */
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        halfdelay(delai);


        /* initialisation de la grille */
        Grille_tirage_fruit(g, M);
        Grille_vider(g);
        reset_mat(M, g->n, g->m);
        Grille_remplir_rouge(g, g->cordx, g->cordy); 
        Grille_remplir_serp(g, serp1, M);
        Grille_remplir_serp(g, serp2, M);  
        Grille_redessiner(g);
        
    	printf("Score Joueur 1: %d - Score Joueur 2: %d\n", score1, score2);
    	
	printf("\033[0m\n");
        
        refresh();
         
        /* Boucle principale du jeu */ 
        while ((ch = getch()) != '#' && perd == 0) {

                
                /* Gestion des déplacements du serpent en fonction des touches pressées */
                switch (ch) {
                    case KEY_UP:
	²		    if (serp1->mouvement->premier->sens != BAS) 
					ajout_debut_liste_mouvement(serp1->mouvement, creer_case(serp1->cordx, serp1->cordy, HAUT));  
			
                        	break;
                        
                    case KEY_DOWN:
                        if (serp1->mouvement->premier->sens != HAUT) 
                        	ajout_debut_liste_mouvement(serp1->mouvement, creer_case(serp1->cordx, serp1->cordy, BAS)); 

                        
                        break;
                        
                    case KEY_LEFT:
			    if (serp1->mouvement->premier->sens != DROITE) 
             		        ajout_debut_liste_mouvement(serp1->mouvement, creer_case(serp1->cordx, serp1->cordy, GAUCHE));           
                        break;
                        
                    case KEY_RIGHT:
			if (serp1->mouvement->premier->sens != GAUCHE) 
                        	ajout_debut_liste_mouvement(serp1->mouvement, creer_case(serp1->cordx, serp1->cordy, DROITE));                        
                        
                        break;

                    case 'w':
			if (serp2->mouvement->premier->sens != BAS) 
				ajout_debut_liste_mouvement(serp1->mouvement, creer_case(serp2->cordx, serp2->cordy, HAUT));  
			
                        break;
                        
                    case 's':
                        if (serp2->mouvement->premier->sens != HAUT) 
                        	ajout_debut_liste_mouvement(serp2->mouvement, creer_case(serp2->cordx, serp2->cordy, BAS)); 
                        
                        break;
                        
                    case 'a':
             		if (serp2->mouvement->premier->sens != DROITE) 
             		        ajout_debut_liste_mouvement(serp2->mouvement, creer_case(serp2->cordx, serp2->cordy, GAUCHE));           
                        
                        break;
                        
                    case 'd':
			if (serp2->mouvement->premier->sens != GAUCHE) 
                        	ajout_debut_liste_mouvement(serp2->mouvement, creer_case(serp2->cordx, serp2->cordy, DROITE));                        
                        
                        break;
                }
		
                /* Mise à jour de la position du serpent en fonction de son dernier mouvement */
		switch (serp1->mouvement->premier->sens) {
                    	case HAUT:
				serp1->cordy--;
                        	break;
                        case BAS:
				serp1->cordy++;
                        	break;
                    	case DROITE:
				serp1->cordx++;
                        	break;
                    	case GAUCHE:
				serp1->cordx--;
                       		break;
                        default:
                                break;
		}

                /* Mise à jour de la position du serpent en fonction de son dernier mouvement */
		switch (serp2->mouvement->premier->sens) {
                    	case HAUT:
				serp2->cordy--;
                        	break;
                        case BAS:
				serp2->cordy++;
                        	break;
                    	case DROITE:
				serp2->cordx++;
                        	break;
                    	case GAUCHE:
				serp2->cordx--;
				break;
		}

                /* Vérifier la collision avec le bord */

		if (serp1->cordx < 0 || serp1->cordx >= g->m || serp1->cordy < 0 || serp1->cordy >= g->n) {
                    perd = 1;  
                }

                if (serp2->cordx < 0 || serp2->cordx >= g->m || serp2->cordy < 0 || serp2->cordy >= g->n) {
                    perd = 2;  
                }
		
                /* Vérifier la collision avec le fruit */
                if (serp1->cordx == g->cordx && serp1->cordy == g->cordy) {
                	
                        /* Ajout d'une nouvelle section au serpent */
			longueur = (rand() % 2) + 1;
			couleur = (rand() % 6) + 41;
                    
                    	ajout_fin_liste(serp1->chaine, creer_section(longueur, couleur));
                    	
                        Grille_tirage_fruit(g, M);

			score1++;	
                
                }

                /* Vérifier la collision avec le fruit */
                if (serp2->cordx == g->cordx && serp2->cordy == g->cordy) {
                	
                        /* Ajout d'une nouvelle section au serpent */
			longueur = (rand() % 2) + 1;
			couleur = (rand() % 6) + 41;
                    
                    	ajout_fin_liste(serp2->chaine, creer_section(longueur, couleur));
                    	
                        Grille_tirage_fruit(g, M);

			score2++;	

			ajout_fin_liste(serp->chaine, creer_section(longueur, couleur));
                    	
                        Grille_tirage_fruit(g, M);

			score++;	
                
                }
                
		/* Mise à jour de la grille */
                Grille_vider(g);
		reset_mat(M, g->n, g->m);
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                touche1 = Grille_remplir_serp(g, serp1, M);
                touche2 = Grille_remplir_serp(g, serp2, M);

                if(touche1 == 1){
                	perd = 1;	
                }

                if(touche2 == 1){
                	perd = 2;	
		}
		
                Grille_redessiner(g);	
               
		printf("\033[0m score joueur 1: %d \033[1E\033[0m\n", score1);

		printf("\033[0m score joueur 2: %d \033[1E\033[0m\n", score2);


                refresh();
        }


        /* Terminer la session ncurses */
        endwin();         	
               
        /* Affichage du message de fin */
        printf("\033[0m Game over\n");
        if(perd==1){
                printf(" Victoire du joueur 2\n");
        }else if(perd==2){
                printf(" Victoire du joueur 1\n");
        }
        
        printf(" Score final joueur 1 est de: %d", score1);

	printf(" Score final joueur 2 est de: %d", score2);
}
