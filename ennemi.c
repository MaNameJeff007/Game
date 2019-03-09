#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
#include <time.h>

void init_ennemi(ennemi *e)
{
    e->right[0]=IMG_Load("ennemi/sright1.png");
    e->right[1]=IMG_Load("ennemi/sright2.png");
    e->right[2]=IMG_Load("ennemi/sright3.png");
    e->left[0]=IMG_Load("ennemi/sleft1.png");
    e->left[1]=IMG_Load("ennemi/sleft2.png");
    e->left[2]=IMG_Load("ennemi/sleft3.png");
    e->down[0]=IMG_Load("ennemi/sface1.png");
    e->down[1]=IMG_Load("ennemi/sface2.png");
    e->down[2]=IMG_Load("ennemi/sface3.png");
    e->up[0]=IMG_Load("ennemi/sdos1.png");
    e->up[1]=IMG_Load("ennemi/sdos2.png");
    e->up[2]=IMG_Load("ennemi/sdos3.png");
    e->img=IMG_Load("ennemi/sleft3.png");
    
    e->tempsActuel=0;
    e->STATE=WAITING;
	e->position.w = 94;
	e->position.h = 98;
    e->position.x=5000*0.15;
    e->position.y=2600*0.15;
}




int collision_ennemi(background map,ennemi *e,int d,int decalage,SDL_Rect *pos)
{    
    SDL_Color col;
    if(d==0)
    {
        col=GetPixel(map.mapCollision,pos->x+(e->img->w)+decalage,pos->y+(e->img->h));
    }
    else  if(d==1)
    {
        col=GetPixel(map.mapCollision,pos->x+(e->img->w) ,pos->y+(e->img->h/2)+decalage);
    }
    else  if(d==2)
    {
        col=GetPixel(map.mapCollision,pos->x+(e->img->w/2)+decalage ,pos->y+(e->img->h/2));
    }
    else  if(d==3)
    {
        col=GetPixel(map.mapCollision,pos->x+(e->img->w/2),pos->y+(e->img->h) +decalage);
    }
    if ((col.r==0)&&(col.b==0)&&(col.g==0))
        return 1;
    if ((col.r==255)&&(col.b==0)&&(col.g==0))
        return 2;
    else 
        return 0;
}

int deplacer_aleatoire(ennemi *e,background map,camera *c,SDL_Rect *pos,SDL_Surface *ecran,int *i)
{
  
    srand(time(0));
    int direction=rand()%4;
    pos->x=e->position.x-c->cam.x;
                     pos->y=e->position.y-c->cam.y;
                     if(SDL_GetTicks()- e->tempsActuel >50)
{

switch(direction)
{

    case 0: if(!collision_ennemi(map,e,5,0,pos))
    {
            e->position.x+=5;
    }
        
    break;
    case 1:  if(!collision_ennemi(map,e,5,1,pos))
             e->position.x-=5;
    break;
    case 2: if(!collision_ennemi(map,e,5,2,pos))
              {e->position.y+=5;
              
                   }   
    break;
    case 3:
  
    if(!collision_ennemi(map,e,5,3,pos))
            {e->position.y-=5;

            }
    break;

}
 
                 e->tempsActuel=SDL_GetTicks();}
    
    switch(direction)
{
 
    case 0:
                e->img=e->right[*i];

           
    break;

    case 1: 
             e->img=e->left[*i];
            
    break;
  
    case 2:  
              e->img=e->down[*i];   
             
    break;
 
    case 3: 
            e->img=e->up[*i];
              

    break;

}

//SDL_BlitSurface(e->img,NULL,ecran,pos);
                 
                    if(SDL_GetTicks()- e->tempsActuel >50)
{

(*i)++;
if(*i>=3)
*i=0;
                 e->tempsActuel=SDL_GetTicks();
                 }
return direction;
}




/*
void free_ennemi(ennemi e)
{
int i;
for(i=0;i<13;i++)
{
SDL_FreeSurface(e->image[i]);
}
}*/