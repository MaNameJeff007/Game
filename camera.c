#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "camera.h"
#include "player1.h"

void init_camera(camera *c)  
{
    c->cam.x=0; //x ili bch tabda tafichi menha  
    c->cam.y=0; //y ili bch tabda tafichi menha
    c->cam.w=800;
    c->cam.h=600;
}
void init_camera2(camera *c)
{
    c->cam.x=0; //x ili bch tabda tafichi menha  
    c->cam.y=0; //y ili bch tabda tafichi menha
    c->cam.w=1600;
    c->cam.h=600;
}

void centrer_camera(camera *c,player p)  //t7ot il joueur fil weset
{
    c->cam.x=(p.pos.x)+130;
    c->cam.y=(p.pos.y)+50;
}

void centrer_camera2(camera *c,player p)  //t7ot il joueur fil weset
{
    c->cam.x=(p.pos.x)+130-1600;
    c->cam.y=(p.pos.y)+50;

}

void afficher_camera(camera *c, background bg, SDL_Surface *ecran, player p)
{
    centrer_camera(c,p);
	SDL_BlitSurface(bg.background,&c->cam,ecran,NULL);
}

void afficher_camera2(camera *c, background bg, SDL_Surface *ecran, player p)
{
    centrer_camera2(c,p);
	SDL_BlitSurface(bg.background,&c->cam,ecran,NULL);
}