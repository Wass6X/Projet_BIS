#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"Fonction_Jeu.h"
#include"Grille.h"
#include "Serpent.h"
#include"liste_Section.h"


void Jouer_Serpent(struct Grille *g, struct Serpent *serp){

    int ch;
    
    Grille_redessiner(g);

    bool gameRunning = true;

    while (gameRunning && (ch = getch()) != '#') { // Continue jusqu'à ce que l'utilisateur appuie sur '#'
        switch (ch) {
            case KEY_UP:
                if (serp->cordx == 0) gameRunning = false; // Stoppe le jeu si on touche un bord
                else serp->cordx--;
                break;
            case KEY_DOWN:
                if (serp->cordx == g->n - 1) gameRunning = false;
                else serp->cordx++;
                break;
            case KEY_LEFT:
                if (serp->cordy == 0) gameRunning = false;
                else serp->cordy--;
                break;
            case KEY_RIGHT:
                if (serp->cordy == g->m - 1) gameRunning = false;
                else serp->cordy++;
                break;
        }

        if (gameRunning) {  
            Grille_remplir_serp(g, serp); // Met à jour la grille avec la nouvelle position du serpent
            Grille_redessiner(g); // Redessine la grille
        }
    }

    endwin(); // Termine la session ncurses

    if (!gameRunning) {
        printf("Game over: Le serpent a heurté un bord!\n");
    }

}
