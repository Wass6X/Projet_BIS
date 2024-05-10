#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"
#include"liste_Mouvement.h"


void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai){

        int ch;
    
        int x, y;
        enum Direction sens;

        int couleur, longueur;  
	
        /* Initialisation de ncurses et du clavier*/
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        halfdelay(delai);



        /* initialisation de la grille */
        Grille_tirage_fruit(g);
        Grille_vider(g);
        Grille_remplir_rouge(g, g->cordx, g->cordy); 
        printf("%d", serp->cordx);
        Grille_remplir_serp(g, serp);  
        Grille_redessiner(g);
        refresh();
 
 
        while ((ch = getch()) != '#') { 
                
                x = serp->cordx;
                y = serp->cordy;
                
                switch (ch) {
                    case KEY_UP:
                        serp->cordx--;
                        sens = HAUT;
                        break;
                    case KEY_DOWN:
                        serp->cordx++;
                        sens = BAS;
                        break;
                    case KEY_LEFT:
                        serp->cordy--;
                        sens = GAUCHE;
                        break;
                    case KEY_RIGHT:
                        serp->cordy++;
                        sens = DROITE;
                        break;
                }

                /* Vérifier la collision avec le bord */
                if (serp->cordx < 0 || serp->cordx >= g->n || serp->cordy < 0 || serp->cordy >= g->m) {
                    break;  
                }

                /* Vérifier la collision avec le fruit */
                if (serp->cordx == g->cordx && serp->cordy == g->cordy) {
                
                    longueur = (rand() % 5) + 1;
                    couleur = (rand() % 6) + 41;
                    
                    ajout_fin_liste(serp->chaine, creer_section(longueur, couleur));
                    ajout_fin_liste_mouvement(serp->mouvement, creer_case(x, y, sens));
                
                    Grille_tirage_fruit(g);
                }


                Grille_vider(g);
                Grille_remplir_rouge(g, g->cordx, g->cordy);  
                /* Grille_remplir_serp(g, serp); */ 
                Grille_redessiner(g);
                refresh();

        }


        /* Terminer la session ncurses */
        endwin(); 
        
        printf("Game over\n");

}

