#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include"Serpent.h"
#include"liste_Section.h"


void Jouer_Serpent(struct Grille *g, struct Serpent *serp, int delai){

    int ch;
    

    /* Initialisation de ncurses et du clavier*/
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    halfdelay(delai);

    
    while ((ch = getch()) != '#') { // Continue jusqu'à ce que l'utilisateur appuie sur '#'
        switch (ch) {
            case KEY_UP:
                serp->cordx--;
                break;
            case KEY_DOWN:
                serp->cordx++;
                break;
            case KEY_LEFT:
                serp->cordy--;
                break;
            case KEY_RIGHT:
                serp->cordy++;
                break;
        }

        if (serp->cordx < 0 || serp->cordx >= g->n || serp->cordy < 0 || serp->cordy >= g->m) {
            break;  // Le serpent a heurté un bord
        }

        Grille_vider(g);
        Grille_remplir_rouge(g, g->cordx, g->cordy);  // Dessine le fruit
        Grille_remplir_serp(g, serp);  // Dessine le serpent
        Grille_redessiner(g);

    }


    endwin(); // Termine la session ncurses
    
    printf("Game over\n");

}
