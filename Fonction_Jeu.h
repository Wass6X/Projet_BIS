#ifndef FONCTION_JEU_H
#define FONCTION_JEU_H

#include "Grille.h"
#include "Serpent.h"

/* Fonction principale pour jouer au serpent */
void Jouer_Serpent(struct Grille * g, struct Serpent * serp, int delai, enum element **M);

#endif
