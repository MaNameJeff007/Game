 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "score.h"
#include "bg.h"
#include "player1.h"
#include "son.h"


typedef struct enigme
{
    char * QuestionPart1, * QuestionPart2, * QuestionPart3, * Answer1, * Answer2 , * Answer3 ;
    SDL_Rect QuestionPart1Pos, QuestionPart2Pos, QuestionPart3Pos, Answer1Pos, Answer2Pos, Answer3Pos,posindice;
    TTF_Font *Font;
    int UserInput, solution;
    SDL_Surface *cadre;
    SDL_Surface *indice[4];

} Enigme;


void resultat_2(Enigme e,score *sc,int *animation,int v, int *i);
Enigme Init_Enigme();
Enigme Init_Enigme2();
Enigme Generate_Enigme(Enigme e);
void resultat(Enigme e,score *sc,int *animation,int *animationpiece,int v);
void afficher_Enigme(SDL_Surface *ecran,Enigme e);
void afficher_Enigme2(SDL_Surface *ecran,Enigme e);


char * Replace_Hyphen(char *str);
int collision_enigme(background map,player p,SDL_Rect pos);
void test_enigme(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,int *animationpiece,SDL_Rect poswar9a,SDL_Surface *war9a,int *w,int *ind,int *hint,son s);
void test_enigme2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,int *animationpiece,SDL_Rect poswar9a,SDL_Surface *war9a,int *w,int *ind,int *hint,son s);
void test_enigme_2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,son s);
void test_enigme2_2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,son s);
