#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 200

struct Grille {
  int n;
  int m;
  char mat[MAX][MAX];
  int long_fruit;
  int larg_fruit;
};

struct Grille *Grille_allouer(int n, int m);
char Grille_vider();
void Grille_tirage_fruit();
