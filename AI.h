#ifndef AI_H_
#define AI_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player1.h"
#include "ennemi.h"
#include "camera.h"
#include "score.h"
#include "son.h"
#include <math.h>


int distance(ennemi E,player H,background bg,camera c);
void transitionn(ennemi *E,player H,background bg,camera c,SDL_Rect pos,score *sc,SDL_Surface *ecran,int *i,int *animation,int *follow,int *wait,int *attack,son s);


#endif 