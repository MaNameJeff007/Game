#ifndef SCORE_H
#define SCORE_H
#include <SDL/SDL.h>
#include "camera.h"
#include "player1.h"
#include "bg.h"
#include "son.h"


 struct score
{
SDL_Surface *piece[44];
SDL_Surface *gameover[3];
SDL_Surface *heart[4];
SDL_Surface *time[4];
int n_vie;
int n_piece;
int scor;
int over;
int stage;

};
 typedef struct score score;


void init_score(score *sc);
void afficher_image(SDL_Surface *image, int x, int y,SDL_Surface *ecran);
void draw_piece(score sc ,SDL_Surface *ecran);
void draw_piece2(score sc ,SDL_Surface *ecran);
void draw_Vie(score *sc,SDL_Surface *ecran,son s);
void draw_Vie2(score *sc,SDL_Surface *ecran,son s,camera c,background bg,player p1, score sc1);
void effect(camera c,background bg,player p,score sc,int *animation,int *animationpiece,SDL_Surface *ecran,son s);
void effect_2(camera c,background bg,player p,score sc,int *animation,SDL_Surface *ecran,son s);
void effect2(camera c,background bg,player p,score sc,int *animation,int *animationpiece,SDL_Surface *ecran,son s,player p1,score sc1,camera c2);
void effect2_2(camera c,background bg,player p,score sc,int *animation,SDL_Surface *ecran,son s,player p1,score sc1,camera c2);
//void timee (SDL_Surface *ecran);
 int  timeenigme(SDL_Surface *ecran ,score sc,int *i,son s);
  int  timeenigme2(SDL_Surface *ecran ,score sc,int *i,son s);
void free_score(score *sc);

#endif 
