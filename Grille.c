#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"

struct Grille * Grille_allouer(int n, int m){
        struct Grille *g = malloc(sizeof(struct Grille));
        g->n = n;
        g->m = m;
        g->tab = malloc(9*sizeof(char *));
}

struct Grille vider 