#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include "score.h"

void init_score(score *sc)
{
    int i;
sc->n_vie=3;
sc->n_piece=0;
sc->over=0;
sc->stage=1;

char image[30];
	for(i=0;i<45;i++)
	{
		sprintf(image,"image/pieces/piece%d.png",i);	
		sc->piece[i]=IMG_Load(image);
	}
	for(i=0;i<4;i++)
	{	
		sprintf(image,"image/heart%d.png",i);
		sc->heart[i]=IMG_Load(image);
	}
    for(i=0;i<4;i++)
	{	
		sprintf(image,"image/pieces/tmp-%d.png",i);
		sc->time[i]=IMG_Load(image);
	}
     for(i=0;i<3;i++)
	{	
		sprintf(image,"image/g%d.png",i);
		sc->gameover[i]=IMG_Load(image);
	}
    

}


void afficher_image(SDL_Surface *image, int x, int y,SDL_Surface *ecran)
{

       SDL_Rect dest;
       dest.x = x;
       dest.y = y;
       dest.w = image->w;
       dest.h = image->h;

       SDL_BlitSurface(image, NULL, ecran, &dest);
}

void draw_Vie(score *sc,SDL_Surface *ecran,son s)
{
    int i;
if (sc->n_vie == 3) 
{afficher_image(sc->heart[0],0,0,ecran);
afficher_image(sc->heart[0],75,0,ecran);
afficher_image(sc->heart[0],150,0,ecran);
}

if (sc->n_vie == 2) 
{
afficher_image(sc->heart[0],0,0,ecran);
afficher_image(sc->heart[0],75,0,ecran);
}
if (sc->n_vie == 1) 
{ 
afficher_image(sc->heart[0],0,0,ecran);
}
if(sc->n_vie==0 && !sc->over )
{
    play_defeat(s);
    for(i=0;i<3;i++)
    {
        afficher_image(sc->gameover[i],0,0,ecran);
        SDL_Flip(ecran);
        SDL_Delay(500);

    }
    sc->over=1;
}

}

void draw_Vie2(score *sc,SDL_Surface *ecran,son s,camera c,background bg,player p1, score sc1)
{
    int i;
if (sc->n_vie == 3) 
{afficher_image(sc->heart[0],800,0,ecran);
afficher_image(sc->heart[0],875,0,ecran);
afficher_image(sc->heart[0],950,0,ecran);
}

if (sc->n_vie == 2) 
{
afficher_image(sc->heart[0],800,0,ecran);
afficher_image(sc->heart[0],875,0,ecran);
}
if (sc->n_vie == 1) 
{ 
afficher_image(sc->heart[0],800,0,ecran);
}
if(sc->n_vie==0 && !sc->over )
{
    play_defeat(s);
    for(i=0;i<3;i++)
    {
        afficher_image(sc->gameover[i],800,0,ecran);
        afficher_camera(&c,bg,ecran,p1);
        SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
        draw_Vie(&sc1,ecran,s);
        draw_piece(sc1,ecran);
        SDL_Flip(ecran);
        SDL_Delay(500);

    }
    sc->over=1;
}
}

void draw_piece(score sc ,SDL_Surface *ecran)
{

if (sc.n_piece == 0) 
afficher_image(sc.piece[0],800-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 1) 
afficher_image(sc.piece[10],800-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 2) 
afficher_image(sc.piece[21],800-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 3) 
afficher_image(sc.piece[32],800-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 4) 
afficher_image(sc.piece[43],800-sc.piece[0]->w,0,ecran);
}

void draw_piece2(score sc ,SDL_Surface *ecran)
{

if (sc.n_piece == 0) 
afficher_image(sc.piece[0],ecran->w-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 1) 
afficher_image(sc.piece[10],ecran->w-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 2) 
afficher_image(sc.piece[21],ecran->w-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 3) 
afficher_image(sc.piece[32],ecran->w-sc.piece[0]->w,0,ecran);
if (sc.n_piece == 4) 
afficher_image(sc.piece[43],ecran->w-sc.piece[0]->w,0,ecran);
}


void effect(camera c,background bg,player p,score sc,int *animation,int *animationpiece,SDL_Surface *ecran,son s)
{ int i,n,j;
   
   if(sc.n_piece==1)
   {
       i=0;
       n=11;
   }
   if(sc.n_piece==2)
   {
       i=11;
       n=22;
   }  
   if(sc.n_piece==3)
   {
       i=22;
       n=33;
   }
   if(sc.n_piece==4)
   {
       i=34;
       n=45;
       
   }
   if(*animationpiece)
   {
       play_piece(s);
       for(j=i;j<n;j++)
       {
           SDL_Delay(200);
           afficher_camera(&c,bg,ecran,p);
         SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
            afficher_image(sc.piece[j],800-sc.piece[0]->w,0,ecran);
            draw_Vie(&sc,ecran,s);


        SDL_Flip(ecran);
       }




   }
   if(*animation && sc.n_vie==2)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
        
        afficher_camera(&c,bg,ecran,p);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],150,0,ecran);
        afficher_image(sc.heart[0],0,0,ecran);
        afficher_image(sc.heart[0],75,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],800-sc.piece[0]->w,0,ecran);
        SDL_Flip(ecran);
  }
    }
    if(*animation && sc.n_vie==1)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
       
        afficher_camera(&c,bg,ecran,p);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
         afficher_image(sc.heart[i],75,0,ecran);
        afficher_image(sc.heart[0],0,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],800-sc.piece[0]->w,0,ecran);
        SDL_Flip(ecran);

  }
}
*animation=0;
*animationpiece=0;

 }

void effect_2(camera c,background bg,player p,score sc,int *animation,SDL_Surface *ecran,son s)
{ int i;
 

   
   if(sc.n_vie==2)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
        
        afficher_camera(&c,bg,ecran,p);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],150,0,ecran);
        afficher_image(sc.heart[0],0,0,ecran);
        afficher_image(sc.heart[0],75,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],800-sc.piece[0]->w,0,ecran);
        SDL_Flip(ecran);
  }
    }
    if(sc.n_vie==1)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
       
        afficher_camera(&c,bg,ecran,p);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
         afficher_image(sc.heart[i],75,0,ecran);
        afficher_image(sc.heart[0],0,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],800-sc.piece[0]->w,0,ecran);
        SDL_Flip(ecran);

  }
}
*animation=0;
 }

void effect2(camera c,background bg,player p,score sc,int *animation,int *animationpiece,SDL_Surface *ecran,son s,player p1,score sc1,camera c2)
{ int i,n,j;
   
   if(sc.n_piece==1)
   {
       i=0;
       n=11;
   }
   if(sc.n_piece==2)
   {
       i=11;
       n=22;
   }  
   if(sc.n_piece==3)
   {
       i=22;
       n=33;
   }
   if(sc.n_piece==4)
   {
       i=34;
       n=45;
   }
   if(*animationpiece)
   {
       play_piece(s);
       for(j=i;j<n;j++)
       {
           SDL_Delay(200);
           afficher_camera2(&c2,bg,ecran,p);
            afficher_camera(&c,bg,ecran,p1);
            SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
         SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
            afficher_image(sc.piece[j],ecran->w-sc.piece[0]->w,0,ecran);
            draw_Vie2(&sc,ecran,s,c2,bg,p1,sc1);
            draw_Vie(&sc1,ecran,s);
            draw_piece(sc1,ecran);

        SDL_Flip(ecran);
       }




   }
   if(*animation && sc.n_vie==2)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
        
       afficher_camera2(&c2,bg,ecran,p);
         afficher_camera(&c,bg,ecran,p1);
          SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],950,0,ecran);
        afficher_image(sc.heart[0],800,0,ecran);
        afficher_image(sc.heart[0],875,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],ecran->w-sc.piece[0]->w,0,ecran);
        draw_Vie(&sc1,ecran,s);
            draw_piece(sc1,ecran);
        SDL_Flip(ecran);
  }
    }
    if(*animation && sc.n_vie==1)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
       
        afficher_camera2(&c2,bg,ecran,p);
        afficher_camera(&c,bg,ecran,p1);
        SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],875,0,ecran);
        afficher_image(sc.heart[0],800,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],ecran->w-sc.piece[0]->w,0,ecran);
        draw_Vie(&sc1,ecran,s);
            draw_piece(sc1,ecran);
        SDL_Flip(ecran);

  }
}
*animation=0;
*animationpiece=0;

} 

void effect2_2(camera c,background bg,player p,score sc,int *animation,SDL_Surface *ecran,son s,player p1,score sc1,camera c2)
{ int i;

   if(sc.n_vie==2)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
        
       afficher_camera2(&c2,bg,ecran,p);
         afficher_camera(&c,bg,ecran,p1);
          SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],950,0,ecran);
        afficher_image(sc.heart[0],800,0,ecran);
        afficher_image(sc.heart[0],875,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],ecran->w-sc.piece[0]->w,0,ecran);
        draw_Vie(&sc1,ecran,s);
            draw_piece(sc1,ecran);
        SDL_Flip(ecran);
  }
    }
    if(sc.n_vie==1)
    {
  for(i=0;i<4;i++)
  {
        SDL_Delay(200);
       
        afficher_camera2(&c2,bg,ecran,p);
        afficher_camera(&c,bg,ecran,p1);
        SDL_BlitSurface(p1.fen, NULL, ecran, &p1.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        afficher_image(sc.heart[i],875,0,ecran);
        afficher_image(sc.heart[0],800,0,ecran);
        afficher_image(sc.piece[sc.n_piece*10],ecran->w-sc.piece[0]->w,0,ecran);
        draw_Vie(&sc1,ecran,s);
            draw_piece(sc1,ecran);
        SDL_Flip(ecran);

  }
}
*animation=0;


} 

int  timeenigme(SDL_Surface *ecran ,score sc,int *i,son s)
 {int j=0,k=1;
 
 
  if(*i!=0)
  {
        if (*i<=30 )
            j=0;
         if(*i<=20 && j!=1)
              j=1;
         if(*i<=10 && j!=2)
                 j=2;
                  
            if(*i==1 && j!=3)
                  j=3;
                 
                  
afficher_image(sc.time[j],510,435,ecran);

play_temps(s);
SDL_Delay(200);
*i=*i-1;

  }
  if(*i==0){
afficher_image(sc.time[3],510,435,ecran);
*i=30;
k=0;
}


return k;

 }


int  timeenigme2(SDL_Surface *ecran ,score sc,int *i,son s)
 {int j=0,k=1;
 
 
  if(*i!=0)
  {
        if (*i<=30 )
            j=0;
         if(*i<=20 && j!=1)
              j=1;
         if(*i<=10 && j!=2)
                 j=2;
                  
            if(*i==1 && j!=3)
                  j=3;
                 
                  
afficher_image(sc.time[j],1310,435,ecran);

play_temps(s);
SDL_Delay(200);
*i=*i-1;

  }
  if(*i==0){
afficher_image(sc.time[3],1310,435,ecran);
*i=30;
k=0;
}


return k;

 }