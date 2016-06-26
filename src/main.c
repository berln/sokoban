#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int main(int argc, char const *argv[])
{
	char getstring[MAXCH+1];
	Boolean boucle=TRUE;
	int score=0;
	int i=0;

	position spos;
	grille stat={
	"###########",
	"###  #    #",
	"##      ###",
	"##     O###",
	"## S     ##",
	"##       ##",
	"##       ##",
	"##      o##",
	"###########"
	};

	/* copie grille */
	grille dyn;
	copiegrille2(stat,dyn);

	affichegrille(stat);
	affichegrille(dyn);

	/* position sokoban*/
	if (getSokoban(stat).x==0 && getSokoban(stat).y==0)
		error(NO_SOKOBAN);
	else{
		spos=getSokoban(stat);
		printf("position sokoban x=%d y=%d\n",spos.x,spos.y);
	}

	if (verifcompt(stat)==TRUE)
		error(NO_EQ);

	

	 while (boucle==TRUE) {
     affichegrille(stat);
     score++;
     printf("\n>");

     fgetgetstring(getstring);

     for(i=0;getstring[i+1]!='\0';i++){
           switch(getstring[i])
              {
                 case QUITTER:
                 boucle=FALSE;
                 break;
                 case HELP:
                 aide();
                 break;
                 case HAUT:
                 spos=joue(dyn, getstring[i], getSokoban(dyn), stat);
                 break;
                 case BAS:
                 spos=joue(dyn, getstring[i], getSokoban(dyn), stat);
                 break;
                 case GAUCHE:
                 spos=joue(dyn, getstring[i], getSokoban(dyn), stat);
                 break;
                 case DROITE:
                 spos=joue(dyn, getstring[i], getSokoban(dyn), stat);
                 break;
                 default:
                 printf("getstring inconnue\n");
              }

          /* if(gagne(dyn, getSokoban(dyn), stat) == true)
           {
              boucle = false;
              afficheGrille(dyn);
              printf(" Bien joué !! \n Tu as gagné en %d tours !\n\n", score);
           }*/
        }
  }
  return 0;
}

	
	
