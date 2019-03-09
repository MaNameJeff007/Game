#ifndef ENEMIE_H_
#define ENEMIE_H_
# include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bg.h"
#include "camera.h"
typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING};
struct Ennemi
{
    SDL_Surface *right[3],*left[3],*up[3],*down[3],*img;
    SDL_Rect position;
    int x_max,x_min,y_max,y_min,tempsActuel;
    STATE STATE;
};
typedef struct Ennemi ennemi;

void init_ennemi(ennemi *e);
int collision_ennemi(background map,ennemi *e,int d,int decalage,SDL_Rect *pos);
int deplacer_aleatoire(ennemi *e,background map,camera *c,SDL_Rect *pos,SDL_Surface *ecran,int *i);
void free_ennemi(ennemi e);
#endif