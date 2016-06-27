#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"

position  getSokoban(Grille l){
	int i;
	int j;
	position res;
	res.x=0;
	res.y=0;
	for (i = 0; i < HAUTEUR; ++i)
	{
		for (j= 0; j < LARGEUR; ++j)
		{
			/* code */
			
				if (l[i][j]==SOKOBAN)
			{
				printf("trouver @ i=%d j=%d\n",i,j);
				res.x=i;
				res.y=j;
			}
		}		
	}
	return res;
}

 void error(CodeErreur code)
  {
    switch (code) {
     case NO_SOKOBAN : fprintf(stderr,"pas de Sokoban!\n"); break;
     case NO_LIGNE	: fprintf(stderr,"erreur taille ligne !\n"); break;
     case NO_EQ	: fprintf(stderr,"inegalitée caisse cible !\n"); break;
     case NO_GETSTRING	: fprintf(stderr,"inegalitée caisse cible !\n"); break;
     case PAUS_E	:	fprintf(stderr,"pos nok !\n"); break;
     case EMUR	:	fprintf(stderr,"pos mur !\n"); break;
     case ECAISSE	:	fprintf(stderr,"pos caisse !\n"); break;
     default: fprintf(stderr,"code erreur inconnu!\n");
    }
    exit(code);
  }/*error*/

void  afficheGrille(char ** l, int hauteur){
	int i;
	for (i = 0; i < hauteur; ++i)
	{
		/* code */
		printf("%s %d\n",l[i], i );
	}
}

void copiegrille2(Grille l, Grille m){
	int i;
	int j;

	/*verification taille grille*/
	if (verif(l)==1)
		error(NO_LIGNE);
	/*copie grille*/
	for (i = 0; i < HAUTEUR; ++i)
	{
		for (j = 0; j < LARGEUR+1; ++j)
		{
			/*elimine sokoban et caise*/
			if((l[j][i]==CAISSE)||(l[i][j]==SOKOBAN))
				m[i][j]=' ';
			else
				m[i][j]=l[i][j];
		}
	}
}

Boolean verif(Grille g){
	int i;
	int j;
	int res=0;
	for (i = 0; i < HAUTEUR; ++i)
	{
		res=0;
		for (j = 0; j < LARGEUR+1; ++j)
		{
			res ++;
			if (g[i][j]=='\0'){
				printf("longueur ligne %d = %d\n",i,res );
				if (res!=LARGEUR+1)
					return TRUE;
			}
				
		}
	}
return FALSE;
}

int compte(Grille g, char c){
	int i=0;
	int j;
	int res=0;
	for (i = 0; i < HAUTEUR; ++i)
	{
		for (j = 0; j < LARGEUR+1; ++j)
		{
			if (g[i][j]==c){
				res ++;
			}
				
		}
	}
	printf("nombre total de %c = %d\n",c,res );
	return res;
}

Boolean verifcompt(Grille g){
	if (compte(g,CAISSE)!=compte(g,CIBLE))
	{
		return TRUE;
	}
	return FALSE;
}

void aide(){
	printf("commande \n");
	printf("z pour haut \n");
	printf("s pour bas \n");
	printf("d pour droite \n");
	printf("q pour gauche \n");
	printf("l pour leav\n");

}

void fgetgetstring(char getstring [MAXCH+1]){
	/*int i=0;*/
	if(fgets(getstring,MAXCH,stdin)==NULL)
		error(NO_GETSTRING);
	printf("%s\n",getstring );
	/*
	for (i = 0; getstring[i+1]!='\0'; ++i){
	switch(getstring[i]){
		case HELP : aide();
		break;
		case HAUT : printf("haut\n");
		break;

		case BAS : printf("bas\n");
		break;

		case DROITE : printf("droite\n");
		break;

		case GAUCHE : printf("gauche\n");
		break;

		printf("commande error\n");
		default : aide();
		break;
	}
	}*/
}

position pas(position spos,touche cmd)
{

  switch (cmd) {
     case HAUT:
        spos.x--;
        break;
     case BAS:
        spos.x++;
        break;
     case DROITE:
        spos.y++;
        break;
     case GAUCHE:
        spos.y--;
        break;
     default:
        error(PAUS_E);
        break;
  }
 
  return spos;
}

Boolean possible(Grille init,position pos)
{ 
  if(pos.x < 0 || pos.x > HAUTEUR)
     return FALSE;
  else if(pos.y < 0 || pos.y > LARGEUR+1)
     return FALSE;
  else if(init[pos.x][pos.y] == MUR || init[pos.x][pos.y] == CAISSE)
     return FALSE;
  else return TRUE;
}

void deplace(Grille init,position pos_a,position pos_b, Grille old)
{
  init[pos_b.x][pos_b.y] = init[pos_a.x][pos_a.y];
  init[pos_a.x][pos_a.y]= old[pos_a.x][pos_a.y];
}

position joue(Grille jeu, touche dir, position depart, Grille init)
{
  position new_pos;
  position pos_caisse;

  depart.y--;
  depart.x--;

  new_pos=pas(depart,dir);

  if(possible(jeu, new_pos) == FALSE)
  {
     if(jeu[new_pos.x][new_pos.y] == MUR)
        error(EMUR);
     else if(jeu[new_pos.x][new_pos.y] == CAISSE)
     {
        pos_caisse=pas(new_pos,dir);
        if(possible(jeu, pos_caisse) == FALSE)
           error(ECAISSE);
        else
        {
           deplace(jeu, new_pos, pos_caisse, init);
           deplace(jeu, depart, new_pos, init);
        }
     }
  }
  else {
     deplace(jeu, depart, new_pos, init);
  }
  return new_pos;
}


Grille initGrille(){
	int i;
	Grille g;
	int largeur=13;
	int longueur=3;
	char * init[]  = {
			"########...#",
			"............",
			"########...#"
		};
	g=malloc(longueur*sizeof(char*));
	for (i = 0; i < longueur; ++i)
	{
		/* code */
		g[i]=malloc(largeur*sizeof(char));
		strcpy(g[i], init [i]);
		printf("g=%s,inti=%s i=%d\n",g[i],init[i],i );
	}
	return g;
}

/* lecture chaine caractere
int taille;
char tab [taille];
if(fgets(tab,taille,stdin)==NULL)
	error(io);*/