#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>


 /* Taille de la fenêtre Hauteur et largeur/ résolution en plein écran */
  #define SCREEN_WIDTH 600
  #define SCREEN_HEIGHT 400

typedef struct background
{
    SDL_Surface *background;
    SDL_Surface *mapCollision;
    SDL_Rect  pos;
} background,background1;

typedef struct MinimapCursor
{
    SDL_Surface *Up, *Down, *Left, *Right, *image, *minimap ;
    SDL_Surface *Up2, *Down2, *Left2, *Right2, *image2;
    SDL_Rect pos,posminimap,pos2;
}Minimap;

//void init(SDL_Surface *ecran);
void init_minimap(Minimap *m,SDL_Surface *ecran);
void init_minimap2(Minimap *m,SDL_Surface *ecran);
void init_Back(background *map);
void init_Back2(background *map);
void drawImage(background map, SDL_Surface *ecran);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
void Afficher_Minimap(SDL_Surface * ecran, SDL_Event event,Minimap *minimap,SDL_Rect posplayer);
void Afficher_Minimap2(SDL_Surface * ecran, SDL_Event event,Minimap *minimap,SDL_Rect posplayer,SDL_Rect posplayer2);
//void collision(background *map,player *p);
void free_back(background *map);

#endif /* BACKGROUND_H_ */
