#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"


void Grille_tirage_fruit(struct Grille *g){
        if (g == NULL) {
                return; 
        }
        g->cordx = rand()%g->n;
        g->cordy = rand()%g->m;
}


