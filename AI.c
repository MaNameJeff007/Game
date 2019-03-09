/**
* @file AI.c
* @brief intellignece artificiel.
* @author Warriors
* @version 0.1
* @date Apr 01, 2015
*
* intelligence artificielle
*
*/
#include "AI.h"

int distance(ennemi E,player H,background bg,camera c)
{  

	int x,y,d,a=2;
	double c2;
		H.pos.x=c.cam.x+H.pos.x;
	H.pos.y=c.cam.y+H.pos.y;
	//E.position.x=E.position.x+c.cam.x;

//E.position.y=E.position.y+c.cam.y;

	x=abs(H.pos.x-E.position.x);
	y=abs(H.pos.y-E.position.y);
	c2=x*x+y*y;
	d=sqrt(c2);
	return d;
}

void transitionn(ennemi *E,player H,background bg,camera c,SDL_Rect pos,score *sc,SDL_Surface *ecran,int *i,int *animation,int *follow,int *wait,int *attack,son s)
{
	int d,d1,d2;
	
	d1=200;// distance entre fen w ennemie ki thebouh ywalli ytaba3
	d2=10;
	d=distance(*E,H,bg,c);
	//printf("dddd=%d\n",d);

if ((*wait==1)&&(d<=d1)&&(d!=d2)){
    *follow=1;
	*wait=0;
}

if ((*follow==1)&&(d<=d2)){
   *attack=1;
   *follow=0;
}

if ((*follow==1)&&(d>d1)){
	*wait=1;
	*follow=0;}

if ((*attack==1)&&(d<d1)&&(d2<=d)){
	*wait=1;
	*attack=0;}


//printf("%d",*follow);


    if(*follow==1) {
 E->STATE=FOLLOWING;
}
   
    if(*attack==1) {
    E->STATE=ATTACKING;
}
    if(*wait==1){
    E->STATE=WAITING;
    }
//	printf("%d\n",*wait);
//	printf("%d %d \n",c.cam.x+H.pos.x,c.cam.y+H.pos.y);
//	printf("%d %d \n",E->position.x,E->position.y);
switch (E->STATE)
{
	case WAITING: 
  	deplacer_aleatoire(E,bg,&c,&pos,ecran,i);
	  *wait=1;
	break;

	case FOLLOWING: 

	H.pos.x=c.cam.x+H.pos.x;
	H.pos.y=c.cam.y+H.pos.y;
//printf("ccccc");	
  if (E->position.x<H.pos.x){
	   E->img=E->right[*i];
	   E->position.x+=1;
  }
  if (E->position.x>H.pos.x){
	   E->img=E->left[*i];
	   E->position.x-=1;
  }
  if (E->position.y<H.pos.y){
	  E->img=E->down[*i];
	  E->position.y+=1;  
  }
  if (E->position.y>H.pos.y){
	  E->img=E->up[*i];
	  E->position.y-=1;
  }
  	
pos.x=E->position.x-c.cam.x;

pos.y=E->position.y-c.cam.y;
 
	break;

	case ATTACKING:
	play_ennemi(s);
	*attack=0;
	*wait=1;
	if(sc->n_vie>0)
	sc->n_vie--;
	*animation=1;
	E->position.x+=200;
	E->position.y+=200;
	break;
}
SDL_BlitSurface(E->img,NULL,ecran,&pos);
                 
                    if(SDL_GetTicks()- E->tempsActuel >50)
{

(*i)++;
if(*i>=3)
*i=0;
                 E->tempsActuel=SDL_GetTicks();
                 }
}