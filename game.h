#ifndef GAME_H_
#define GAME_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player1.h"
#include "bg.h"
#include "enigme.h"
#include "score.h"
#include "camera.h"
#include "ennemi.h"
#include "AI.h"

/*
struct game
{
     Enigme en;
     score sc;
     camera c;
     background bg;
     player p;
     move m;
};
typedef struct game game;
*/
void SaveGame( player player, camera c,score sc,  char filename[50] );
void LoadGame( player *player, camera *c,score *sc, char filename[50] );

void playgame(SDL_Surface *ecran,int *continuer,int *fullscreen,int modegame, int newgame);

#endif 
