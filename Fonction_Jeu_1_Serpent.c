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



    // initialisation du la grille
    Grille_tirage_fruit(g);
    Grille_vider(g);
    Grille_remplir_rouge(g, g->cordx, g->cordy);  // Dessine le fruit
    Grille_remplir_serp(g, serp);  // Dessine le serpent
   	Grille_redessiner(g);
    refresh();
    
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

        // Vérifier la collision avec le bord
        if (serp->cordx < 0 || serp->cordx >= g->n || serp->cordy < 0 || serp->cordy >= g->m) {
            break;  // Le serpent a heurté un bord
        }

        // Vérifier la collision avec le fruit
        if (serp->cordx == g->cordx && serp->cordy == g->cordy) {
            int longueur = (rand() % 5) + 1;  // Longueur aléatoire entre 1 et 5
            int couleur = (rand() % (47 - 41 + 1)) + 41;  // Couleur aléatoire entre 41 et 47
            ajout_fin_liste(serp->chaine, creer_section(1, 45));
            Grille_tirage_fruit(g);  // Générer un nouveau fruit
        }


        Grille_vider(g);
        Grille_remplir_rouge(g, g->cordx, g->cordy);  // Dessine le fruit
        Grille_remplir_serp(g, serp);  // Dessine le serpent
        Grille_redessiner(g);
        refresh();

    }


    endwin(); // Termine la session ncurses
    
    printf("Game over\n");

}
