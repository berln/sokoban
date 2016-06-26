#ifndef _SOKOBAN_H
#define _SOKOBAN_H
#define HAUTEUR 9
#define LARGEUR 11
#define MAXCH 20



typedef enum {FALSE,TRUE} Boolean;
typedef enum {MUR='#',CAISSE='O',CIBLE='o',SOKOBAN='S'}symbole;
typedef enum {HAUT='z',BAS='s',DROITE='d',GAUCHE='q',HELP='h',QUITTER='l'}touche;
typedef enum {NO_SOKOBAN=1,NO_LIGNE=2,NO_EQ=3,NO_GETSTRING=4,PAUS_E=5,EMUR=6,ECAISSE=7}CodeErreur;
typedef struct position {
   int x;
   int y;
}position;

typedef char ligne[LARGEUR+1];
typedef ligne grille[HAUTEUR];
#endif

void  affichegrille(grille l);
void copiegrille2(grille l, grille m);
position  getSokoban(grille l);
void error(CodeErreur code);
Boolean verif(grille g);
int compte(grille g, char c);
Boolean verifcompt(grille g);
void fgetgetstring(char lol [MAXCH+1]);
position pas(position spos,touche cmd);
void aide();
position joue(grille jeu, touche dir, position depart, grille init);