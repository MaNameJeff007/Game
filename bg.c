#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include <SDL/SDL_rotozoom.h>
#include "bg.h"
 
void init_minimap(Minimap *m,SDL_Surface *ecran)
{
    m->minimap = IMG_Load("image/map.png");
    m->minimap=rotozoomSurface(m->minimap,0,0.015,0);
    m->posminimap.x=(ecran->w/2)-96.9;
    m->posminimap.y=(ecran->h)-117;

    m->Down=IMG_Load("image/minimap/a14.png");
    m->Up=IMG_Load("image/minimap/a12.png");
    m->Left=IMG_Load("image/minimap/a15.png");
    m->Right=IMG_Load("image/minimap/a13.png");
    m->image=m->Down;

    m->Down2=IMG_Load("image/minimap/b15.png");
    m->Up2=IMG_Load("image/minimap/b12.png");
    m->Left2=IMG_Load("image/minimap/b13.png");
    m->Right2=IMG_Load("image/minimap/b14.png");
    m->image2=m->Down2;
}

void init_minimap2(Minimap *m,SDL_Surface *ecran)
{
    m->minimap = IMG_Load("image/map_3.png");
    m->minimap=rotozoomSurface(m->minimap,0,0.019,0);
    m->posminimap.x=(ecran->w/2)-71.5;
    m->posminimap.y=(ecran->h)-106.7;

    m->Down=IMG_Load("image/minimap/a14.png");
    m->Up=IMG_Load("image/minimap/a12.png");
    m->Left=IMG_Load("image/minimap/a15.png");
    m->Right=IMG_Load("image/minimap/a13.png");
    m->image=m->Down;

    m->Down2=IMG_Load("image/minimap/b15.png");
    m->Up2=IMG_Load("image/minimap/b12.png");
    m->Left2=IMG_Load("image/minimap/b13.png");
    m->Right2=IMG_Load("image/minimap/b14.png");
    m->image2=m->Down2;
}

void init_Back(background *map)
{
    map->background = IMG_Load("image/map.png");
    map->mapCollision=IMG_Load("image/map_collision.png");

    map->background=rotozoomSurface(map->background,0,0.15,0);

    map->mapCollision=rotozoomSurface(map->mapCollision,0,0.15,0);

    map->pos.x=0;
    map->pos.y=0;
}

void init_Back2(background *map)
{
    map->background = IMG_Load("image/map_3.png");

    map->mapCollision=IMG_Load("image/map_3_collision.png");
    map->background=rotozoomSurface(map->background,0,0.19,0);
        map->mapCollision=rotozoomSurface(map->mapCollision,0,0.19,0);

    map->pos.x=0;
    map->pos.y=0;
}

void drawImage(background map, SDL_Surface *ecran)
{
       SDL_BlitSurface(map.background,NULL,ecran,&map.pos);
}

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color, black= {0,0,0};
    Uint32 col = 0;
    
         //determine pos
        char *pixelpos = (char*)Background->pixels;
         //offset by y
        pixelpos += (Background->pitch * y);
         //offset by x
        pixelpos += (Background->format->BytesPerPixel * x);
         //copy pixel data
        memcpy(&col, pixelpos, Background->format->BytesPerPixel);
         //convert color
        SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);
        return (color);

   
}

void Afficher_Minimap(SDL_Surface * ecran, SDL_Event event,Minimap *minimap,SDL_Rect posplayer)
{
    switch(event.type)
    {
        case SDL_KEYDOWN :
            switch ( event . key . keysym . sym )
            {
            case SDLK_d:
                minimap->image = minimap->Right ;
                break;
            case SDLK_q:
                minimap->image = minimap->Left ;
                break;
            case SDLK_z:
                minimap->image = minimap->Up ;
                break;
            case SDLK_s:
                minimap->image = minimap->Down ;
                break;
            }
        break;
    }

    minimap->pos.x = minimap->posminimap.x + ( posplayer.x ) * 0.23 ;
    minimap->pos.y = minimap->posminimap.y + ( posplayer.y ) * 0.21 ;

    SDL_BlitSurface(minimap->minimap, NULL, ecran,&minimap->posminimap);
    SDL_BlitSurface(minimap->image, NULL, ecran, &minimap->pos);
}

void Afficher_Minimap2(SDL_Surface * ecran, SDL_Event event,Minimap *minimap,SDL_Rect posplayer,SDL_Rect posplayer2)
{
    switch(event.type)
    {
        case SDL_KEYDOWN :
            switch ( event . key . keysym . sym )
            {
            case SDLK_d:
                minimap->image = minimap->Right ;
                break;
            case SDLK_q:
                minimap->image = minimap->Left ;
                break;
            case SDLK_z:
                minimap->image = minimap->Up ;
                break;
            case SDLK_s:
                minimap->image = minimap->Down ;
                break;

            case SDLK_RIGHT:
                minimap->image2 = minimap->Right2 ;
                break;
            case SDLK_LEFT:
                minimap->image2 = minimap->Left2 ;
                break;
            case SDLK_UP:
                minimap->image2 = minimap->Up2 ;
                break;
            case SDLK_DOWN:
                minimap->image2 = minimap->Down2 ;
                break;
            }
        break;
    }

    minimap->pos.x = minimap->posminimap.x + ( posplayer.x ) * 0.23 ;
    minimap->pos.y = minimap->posminimap.y + ( posplayer.y ) * 0.21 ;

    minimap->pos2.x = minimap->posminimap.x + ( posplayer2.x ) * 0.09 ;
    minimap->pos2.y = minimap->posminimap.y + ( posplayer2.y ) * 0.21 ;

    SDL_BlitSurface(minimap->minimap, NULL, ecran,&minimap->posminimap);
    SDL_BlitSurface(minimap->image, NULL, ecran, &minimap->pos);
    SDL_BlitSurface(minimap->image2, NULL, ecran, &minimap->pos2);
}
