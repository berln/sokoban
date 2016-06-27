#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int main(int argc, char ** argv){

  int hauteur=3;
  Grille initiale;
  initiale=initGrille();
  afficheGrille(initiale,hauteur);


  return 0;
}