#ifndef _SOKOBAN_H
#define _SOKOBAN_H
#define HAUTEUR 10
#define LARGEUR 8
#define MAXCH 20



typedef enum {FALSE,TRUE} Boolean;
typedef enum {MUR='#',CAISSE='O',CIBLE='o',SOKOBAN='S'}symbole;
typedef enum {HAUT='z',BAS='s',DROITE='d',GAUCHE='q',HELP='h',QUITTER='l'}touche;
typedef enum {NO_SOKOBAN=1,NO_LIGNE=2,NO_EQ=3,NO_GETSTRING=4,PAUS_E=5,EMUR=6,ECAISSE=7}CodeErreur;
typedef struct position {
   int x;
   int y;
}position;

typedef char* Ligne;
typedef struct _grille{
	int lenth;
	int width
	Ligne * grille;
} Grille;

void  afficheGrille(char ** l, int hauteur);
void copiegrille2(Grille l, Grille m);
position  getSokoban(Grille l);
void error(CodeErreur code);
Boolean verif(Grille g);
int compte(Grille g, char c);
Boolean verifcompt(Grille g);
void fgetgetstring(char lol [MAXCH+1]);
position pas(position spos,touche cmd);
void aide();
position joue(Grille jeu, touche dir, position depart, Grille init);
Grille initGrille();
#endif