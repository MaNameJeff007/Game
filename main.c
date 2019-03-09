#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_timer.h>
#include "game.h"


void menuoption(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *music,SDL_Surface *sfx,SDL_Surface *full,SDL_Surface *cursor,SDL_Rect *positionFond,SDL_Rect *position,SDL_Rect *positioncursor)
{
	int x,y;
	SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
	position->x=350;
	position->y=270;
	SDL_BlitSurface(music, NULL, ecran, position);
				
	position->y=355;
	SDL_BlitSurface(sfx, NULL, ecran, position);
	position->y=450;
	SDL_BlitSurface(full, NULL, ecran, position);
	SDL_GetMouseState(&x,&y);
	positioncursor->x=x;
	positioncursor->y=y;
	SDL_BlitSurface(cursor, NULL, ecran, positioncursor);	
	SDL_Flip(ecran);
}

void menu(SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Surface *cursor, SDL_Surface *bouton, SDL_Surface *bouton2, SDL_Surface *bouton3, SDL_Surface *bouton4,SDL_Surface *text,SDL_Rect *positiontext,SDL_Rect *positionFond, SDL_Rect *positionbouton,SDL_Rect *positioncursor)
{ int x,y;
		SDL_BlitSurface(imageDeFond, NULL, ecran, positionFond);
    positionbouton->x = 0;
    positionbouton->y = 10;
    SDL_BlitSurface(bouton, NULL, ecran, positionbouton);
   
   positionbouton->y = 70;
    SDL_BlitSurface(bouton2, NULL, ecran, positionbouton);
	
 positionbouton->y = 130;
    SDL_BlitSurface(bouton3, NULL, ecran, positionbouton);
	
  positionbouton->y = 190;
    SDL_BlitSurface(bouton4, NULL, ecran, positionbouton);
	
	positiontext->x=700;
	positiontext->y=570;
	  SDL_BlitSurface(text, NULL, ecran, positiontext); 

			SDL_GetMouseState(&x,&y);
positioncursor->x=x;
	positioncursor->y=y;
	SDL_BlitSurface(cursor, NULL, ecran, positioncursor);	

  //  SDL_Flip(ecran);
}
void helpFN(SDL_Surface *ecran,int *continuer)
{
  SDL_Surface *help_page=NULL;
  SDL_Event event;
  SDL_Rect pos;
  pos.x=0;
  pos.y=0;
  help_page=IMG_Load("image/help_page.png");


int help=1;
              ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );

			  SDL_BlitSurface(help_page,NULL,ecran,&pos);
				 SDL_Flip(ecran);
		while(help)
		{
			 
				 SDL_WaitEvent (& event ) ; 
			switch ( event . type )
					{
									case SDL_QUIT : 
				help= 0 ; 
				*continuer=0;
			break ;
				
							case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{		
												case SDLK_BACKSPACE: 
															help = 0 ;	
															break;

										}
										break;
										case SDL_MOUSEBUTTONDOWN:
									
										if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>372)&&(event.motion.x<412)&&(event.motion.y>568)&&(event.motion.y<593))
												{
																	help=0;
												}
												break;
					}
		}

}

void optionsFN(SDL_Surface *ecran,SDL_Surface *imageDeFond,Mix_Chunk *son,Mix_Chunk *son1,int *full,int *continuer)
{
  SDL_Surface *flp=NULL,*drn=NULL,*aaarg=NULL,*aaalg=NULL,*aan=NULL,*arg=NULL,*alg=NULL,*an=NULL,*aalg=NULL,*aarg=NULL,*aaan=NULL,*drg=NULL;
SDL_Surface *flg=NULL,*on=NULL,*off=NULL,*s_on=NULL,*s_off=NULL,*cursor;
SDL_Event event;
int x,y;
	SDL_Rect position,positionFond,positioncursor;
	/*position.x=0;
	position.y=0;*/
	positionFond.x=0;
	positionFond.y=0;

	imageDeFond = IMG_Load("image/option/menu.png");
	flp = IMG_Load("image/option/FLP.png");
	drn = IMG_Load("image/option/DRN.png");
	aaarg = IMG_Load("image/option/8RG.png");
	aaalg = IMG_Load("image/option/8LG.png");
	aan=IMG_Load("image/option/4N.png");
	arg = IMG_Load("image/option/2RG.png");
	alg = IMG_Load("image/option/2LG.png");
	an = IMG_Load("image/option/2N.png");
	aalg=IMG_Load("image/option/4LG.png");
	aarg=IMG_Load("image/option/4RG.png");
	aaan = IMG_Load("image/option/8N.png");
	drg = IMG_Load("image/option/DRG.png");
	flg= IMG_Load("image/option/FLG.png");

	s_on = IMG_Load("image/option/on.png");
	s_off = IMG_Load("image/option/off.png");
		cursor=IMG_Load("image/cursor.png");

	SDL_Color couleur={255,255,255};

int options=1,clic=0,clic1=0,o;
if(*full==0)
{
 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
}
else
{
 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN  );


}
				off = TTF_RenderText_Blended(TTF_OpenFont("Font/Only The Strong.ttf", 25), "PRESS A", couleur);

menuoption(ecran,imageDeFond,flp,s_on,off,cursor,&positionFond,&position,&positioncursor);

				 
	while(options)
		{
			 
				 SDL_WaitEvent (& event ) ; 
			switch ( event . type )
					{
						case SDL_QUIT : 
				options = 0 ; 
				*continuer=0;
				
			break ;
							case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{		
												case SDLK_BACKSPACE: 
															options = 0 ;
												break;
												case SDLK_a:
									  						  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN );
															menuoption(ecran,imageDeFond,flg,s_on,off,cursor,&positionFond,&position,&positioncursor);
															*full=1;
												break;
												case SDLK_q:
															 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
						 									menuoption(ecran,imageDeFond,flg,s_on,off,cursor,&positionFond,&position,&positioncursor);
															 *full=0;
												break;
												case SDLK_LEFT:
												 switch(clic)
												 {
													case 0:
														menuoption(ecran,imageDeFond,flg,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME);
														clic=1;
													break;
													case 1:
														menuoption(ecran,imageDeFond,aaan,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME*3/4);
														clic=2;
													break;
													case 2:
														menuoption(ecran,imageDeFond,aan,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME/2);
														clic=3;
													break;
													case 3:
														menuoption(ecran,imageDeFond,an,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);
														clic=4;
				                                    break;																
													case 4:
														menuoption(ecran,imageDeFond,drg,s_off,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME/128);
														Mix_VolumeChunk(son1,MIX_MAX_VOLUME/128);
														clic=5;
													break;
												 }
												break;
												case SDLK_RIGHT:
												switch(clic)
												 {
													case 2:
														menuoption(ecran,imageDeFond,flg,s_on,off,cursor,&positionFond,&position,&positioncursor);
														clic=1;
													break;
													case 3:
														menuoption(ecran,imageDeFond,aaan,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME*3/4);
														clic=2;												
													break;
													case 4:
														menuoption(ecran,imageDeFond,aan,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME/2);
														clic=3;
							
													break;
													case 5:
														menuoption(ecran,imageDeFond,an,s_on,off,cursor,&positionFond,&position,&positioncursor);
														Mix_VolumeChunk(son,MIX_MAX_VOLUME/4);
														Mix_VolumeChunk(son1,MIX_MAX_VOLUME);
														clic=4;
													break;
												 }
										        break;
								}
								break;
												case SDL_MOUSEBUTTONDOWN:
												{
												if(o!=1)
												{
												if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==0)||(clic==1))
												{

																menuoption(ecran,imageDeFond,flp,s_off,off,cursor,&positionFond,&position,&positioncursor);
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME/128);
																o=1;

												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==2))
												{

																menuoption(ecran,imageDeFond,aaan,s_off,off,cursor,&positionFond,&position,&positioncursor);
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME/128);
																o=1;

												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==3))
												{

																menuoption(ecran,imageDeFond,aan,s_off,off,cursor,&positionFond,&position,&positioncursor);
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME/128);
																o=1;
												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==4))
												{

																menuoption(ecran,imageDeFond,an,s_off,off,cursor,&positionFond,&position,&positioncursor);
																o=1;
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME/128);

												}
												}
												else 
												{
												if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==0)||(clic==1))
												{

																menuoption(ecran,imageDeFond,flp,s_on,off,cursor,&positionFond,&position,&positioncursor);
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME);
																o=0;

												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==2))
												{

																menuoption(ecran,imageDeFond,aaan,s_on,off,cursor,&positionFond,&position,&positioncursor);
																o=0;
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME);

												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==3))
												{

																menuoption(ecran,imageDeFond,aan,s_on,off,cursor,&positionFond,&position,&positioncursor);
																o=0;
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME);
												}
												else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>350)&&(event.motion.x<460)&&(event.motion.y>355)&&(event.motion.y<400)&&(clic==4))
												{

																menuoption(ecran,imageDeFond,an,s_on,off,cursor,&positionFond,&position,&positioncursor);
																o=0;
																Mix_VolumeChunk(son1,MIX_MAX_VOLUME);

												}
												}
												if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>372)&&(event.motion.x<412)&&(event.motion.y>568)&&(event.motion.y<593))
												{
																	options=0;
												}	
												}
												break;				
					
								

		}
		SDL_GetMouseState(&x,&y);
		positioncursor.x=x;
	positioncursor.y=y;

	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
	SDL_Flip(ecran);
		}
}


int main(int argc, char *argv[])
{
   SDL_Surface *affiche=NULL,*img=NULL,*loading[3],*multi=NULL,*multiz=NULL,*single=NULL,*singlez=NULL,*new=NULL,*newz=NULL,*continu=NULL,*continuz=NULL;
    SDL_Surface *cursor=NULL,*ecran = NULL,*ecran1=NULL,*text=NULL,*text1=NULL, *imageDeFond = NULL,*play=NULL,*resume=NULL,*options=NULL,*exit=NULL,*playz=NULL,*resumez=NULL,*optionsz=NULL,*exitz=NULL;
int continuer=1,z,z1,selectedButton=0,c=1,i,press=0,press1=0,coat=1,cinoo=1,newgame=1,modegame=0;
int x=-175,y=-15,x1=-175,y1=-10,x2=-175,y2=-5,x3=-175,y3=0,full=0;
    int tempsPrecedent = 0, tempsActuel = 0,k=0,j,mode=0,button=1;
SDL_Event event;
 TTF_Font *police = NULL;
    SDL_Color couleurNoire = {255,250,250};
    SDL_Rect positionFond,positiontext,position,positioncursor,positionimg,positiontext1,positionbouton,positionmulti;
	SDL_Rect positionplay,positionresume,positionoptions,positionexit;
	positionmulti.x=0;
	positionmulti.y=100;
    SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER);
	
	TTF_Init();
char a[10],image[30],ext[20];
	SDL_Surface *IMG[32],*intro[704],*cino[1713];
	for(i=1;i<=32;i++)
	{
		
		sprintf(a,"%d",i);
        strcpy(image,"image/menu/");
		strcpy(ext,".jpg");
		
		 strcat(image,a);
		 strcat(image,ext);
		IMG[i]=IMG_Load(image);
	}
		for(i=0;i<705;i++)
	{
		if(i<10)
		sprintf(image,"intro/intro_00%d.png",i);
		if(i<100 && i>=10)
				sprintf(image,"intro/intro_0%d.png",i);
				if(i>=100)
						sprintf(image,"intro/intro_%d.png",i);


		intro[i]=IMG_Load(image);
	}


	for(j=0;j<1714;j++)
    {
    if(j<10)
		sprintf(image,"cino/cine_000%d.png",j);
	if(j<100 && j>=10)
		sprintf(image,"cino/cine_00%d.png",j);
	if(j>=100 && j<1000)
		sprintf(image,"cino/cine_0%d.png",j);
		if(j>=1000)
		sprintf(image,"cino/cine_%d.png",j);
	cino[j]=IMG_Load(image);
    }

	i=0;
  positionimg.x=90;
  positionimg.y=15;
	position.x=0;
position.y=0;
	 positionFond.x = 0;
    positionFond.y = 0;
	positiontext1.x=90;
	positiontext1.y=470;
	positiontext.x=700;
	positiontext.y=470;
	positionbouton.x=0;
	positionbouton.y=0;
	
	
	    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
	
	
		text1 = TTF_RenderText_Blended(TTF_OpenFont("Font/Only The Strong.ttf", 15), "PRESS ANY KEY...", couleurNoire);
				text = TTF_RenderText_Blended(TTF_OpenFont("Font/angelina.TTF", 15), "copyright vikings", couleurNoire);

        SDL_WM_SetCaption("Vikings Fen's Revenge", NULL);
	/*chargement des images*/
	imageDeFond = IMG_Load("image/select/menu.jpg");
	affiche = IMG_Load("image/select/affiche.jpg");
	play = IMG_Load("image/select/play.png");
	resume = IMG_Load("image/select/help.png");
	options = IMG_Load("image/select/options.png");
	exit=IMG_Load("image/select/quit.png");
	playz = IMG_Load("image/select/playz.png");
	resumez = IMG_Load("image/select/helpz.png");
	optionsz = IMG_Load("image/select/optionsz.png");
	exitz=IMG_Load("image/select/quitz.png");
	multi=IMG_Load("image/select/multi.png");
	multiz=IMG_Load("image/select/multiz.png");
	single=IMG_Load("image/select/single.png");
	singlez=IMG_Load("image/select/singlez.png");
	cursor=IMG_Load("image/select/cursor.png");
	loading[0]=IMG_Load("image/loading1.png");
	loading[1]=IMG_Load("image/loading2.png");
	loading[2]=IMG_Load("image/loading3.png");
	new=IMG_Load("image/select/new.png");
	newz=IMG_Load("image/select/newz.png");
	continu=IMG_Load("image/select/continu.png");
	continuz=IMG_Load("image/select/continuz.png");


	 
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *mus,*cinematique,*introson;
   Mix_Chunk *son;
   Mix_Chunk *son2;
	  son = Mix_LoadWAV("son/viking.wav"); 
   son2 = Mix_LoadWAV("son/son.wav");
mus=Mix_LoadMUS("son/sword.mp3");
cinematique=Mix_LoadMUS("son/mus.mp3");
introson=Mix_LoadMUS("son/mus_intro.mp3");
 // Mix_PlayChannel(1, son, -1);
 SDL_ShowCursor(SDL_DISABLE);
while(continuer)
	{

SDL_WaitEvent (& event );


switch ( event . type )
{	
			case SDL_QUIT : 
				continuer = 0 ; 
			break ;
			case SDL_KEYDOWN : 
				press=1;
				if((press==1)&&(press1==0))
				press1=0;
				
			//	menu(ecran, imageDeFond,cursor,play,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
switch ( event . key . keysym . sym )
{		
			case SDLK_ESCAPE: 
				continuer = 0 ;

			break;
			case SDLK_a:
			 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN  );
			 				menu(ecran, imageDeFond,cursor,play,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
full=1;
			 break;
            case SDLK_q:
						 ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
						 				menu(ecran, imageDeFond,cursor,play,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
full=0;
						 break;


			case SDLK_KP_ENTER:

			case SDLK_RETURN:

switch(selectedButton)
{
			case 1:
			
			Mix_HaltChannel(1);
			if(!mode)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);}
			while(!mode)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		mode=1;
		else
		mode=2;
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(multi,NULL,ecran,&positionmulti);

		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;

	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(multi,NULL,ecran,&positionmulti);

		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(single,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
		SDL_BlitSurface(single,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}
				if(mode==2)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);}
			while(mode==2)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		{newgame=1;modegame=2;mode=3;}

		else
		{newgame=0;modegame=2;mode=3;}
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}

				if(mode==1)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);}
			while(mode==1)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		{newgame=1;modegame=1;mode=3;}

		else
		{newgame=0;modegame=1;mode=3;}
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}
			
			if(cinoo && newgame==0)
       		{
				   Mix_PlayMusic(cinematique, 0);

                for(i=0;i<1714;i++)
                {
                        SDL_BlitSurface(intro[0],NULL,ecran,&positionFond);

                        SDL_BlitSurface(cino[i],NULL,ecran,&positionFond);
                        SDL_Delay(19);
						SDL_Flip(ecran);
                }


cinoo=0;
    	   }
			for(j=0;j<20;j++){
				
				SDL_Delay(200);
				SDL_BlitSurface(loading[k],NULL,ecran,&positionFond);
				SDL_Flip(ecran);
				k++;
				if(k==3)
				k=0;
				
			}
			
    		
				
         		playgame(ecran,&continuer,&full,modegame,newgame);
				  continu=0;
				
				menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
			break;
			case 2:
			helpFN(ecran,&continuer);
			menu(ecran, imageDeFond,cursor,play,resumez,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
			break;
		 	case 3:
			 	  

		 		optionsFN(ecran,imageDeFond,son,son2,&full,&continuer);
				 	if(full==0)
	{
	
	    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
	}
	else
	{

			    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN  );

	}
		 		menu(ecran, imageDeFond,cursor,play,resume,optionsz,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
        	break;
			case 4:
				continuer=0;
			break;
}
	
	break;
			case SDLK_UP:

				 switch(selectedButton)
                {
                    case 0:
                    menu(ecran, imageDeFond,cursor,play,resume,options,exitz,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=4;
					Mix_PlayChannel(2, son2, 0);
                    break; 
                    case 1:
                    menu(ecran, imageDeFond,cursor,play,resume,options,exitz,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=4;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 2:
                    menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=1;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 3:
                    menu(ecran, imageDeFond,cursor,play,resumez,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=2;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 4:
                    menu(ecran, imageDeFond,cursor,play,resume,optionsz,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=3;
					Mix_PlayChannel(2, son2, 0);
                    break;
					
                }
            break;
				case SDLK_DOWN:
  					switch(selectedButton)
               		 {
                    case 0:
                    menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=1;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 1:
                    menu(ecran, imageDeFond,cursor,play,resumez,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=2;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 2:
                    menu(ecran, imageDeFond,cursor,play,resume,optionsz,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=3;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 3:
                    menu(ecran, imageDeFond,cursor,play,resume,options,exitz,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=4;
					Mix_PlayChannel(2, son2, 0);
                    break;
                    case 4:
                    menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=1;
					Mix_PlayChannel(2, son2, 0);
                    break;
                }
                break;
}
break;
	case SDL_MOUSEBUTTONDOWN:

		if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>400)&&(event.motion.y<600)&&(press==1))
			{
				continuer=0;
			}
		 if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>250)&&(event.motion.y<300))
		{
						Mix_HaltChannel(1);
						if(!mode)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);}
			while(!mode)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		mode=1;
		else
		mode=2;
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(multi,NULL,ecran,&positionmulti);

		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;
	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(multi,NULL,ecran,&positionmulti);

		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(single,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
		SDL_BlitSurface(singlez,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(multiz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(single,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(multi,NULL,ecran,&positionmulti);
		SDL_BlitSurface(single,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}
				if(mode==2)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);}
			while(mode==2)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		{newgame=1;modegame=2;mode=3;}

		else
		{newgame=0;modegame=2;mode=3;}
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}

				if(mode==1)
		{SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);}
			while(mode==1)
			{
				
				SDL_WaitEvent (& event );
switch ( event . type )
{
case SDL_KEYDOWN : 
switch ( event . key . keysym . sym )
{
	case SDLK_RETURN:
	if(button)
		{newgame=1;modegame=1;mode=3;}

		else
		{newgame=0;modegame=1;mode=3;}
		break;
	case SDLK_UP:
	if(button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
		SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);

		button=0;
	}
	else 
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
						SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	break;
	case SDLK_DOWN:
	if(!button)
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
								SDL_BlitSurface(new,NULL,ecran,&positionmulti);

		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
	}
	else
	{
		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
				SDL_BlitSurface(continu,NULL,ecran,&positionFond);
				button=0;

	}
break;
	

}
break;
case SDL_MOUSEMOTION:
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>240  && event.motion.y<285)
					{
						SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continuz,NULL,ecran,&positionFond);
		button=1;
					}
					if(event.motion.x>270 && event.motion.x<510 && event.motion.y>340  && event.motion.y<385)
					{
								SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
				SDL_BlitSurface(newz,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
		button=0;
					}

					
									

					break;
											SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
															SDL_BlitSurface(new,NULL,ecran,&positionmulti);
		SDL_BlitSurface(continu,NULL,ecran,&positionFond);
}

			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
SDL_Flip(ecran);

			}
			
			if(cinoo && newgame==0)
       		{
				   Mix_PlayMusic(cinematique, 0);

                for(i=0;i<1714;i++)
                {
                        SDL_BlitSurface(intro[0],NULL,ecran,&positionFond);

                        SDL_BlitSurface(cino[i],NULL,ecran,&positionFond);
                        SDL_Delay(19);
						SDL_Flip(ecran);
                }


cinoo=0;
    	   }
			for(j=0;j<20;j++){
				
				SDL_Delay(200);
				SDL_BlitSurface(loading[k],NULL,ecran,&positionFond);
				SDL_Flip(ecran);
				k++;
				if(k==3)
				k=0;
				
			}
			
    		
				
         		playgame(ecran,&continuer,&full,modegame,newgame);
				  continu=0;
				
					menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
				
		
		}
		 if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>380)&&(event.motion.y<430))
		{
					optionsFN(ecran,imageDeFond,son,son2,&full,&continuer);
		 			menu(ecran, imageDeFond,cursor,play,resume,optionsz,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
			if(full==0)
	{
	
	    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF  );
	}
	else
	{

			    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN  );

	}
		}
		 if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>320)&&(event.motion.y<370))
		{
					helpFN(ecran,&continuer);
					menu(ecran, imageDeFond,cursor,play,resumez,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    

		}
		

	case SDL_MOUSEMOTION:
		{
		if((event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>250)&&(event.motion.y<300)&&(press==1))
		{
					menu(ecran, imageDeFond,cursor,playz,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=1;
					Mix_PlayChannel(2, son2, 0);
				
		
		}
		else  if((event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>320)&&(event.motion.y<370)&&(press==1))
		{
					menu(ecran, imageDeFond,cursor,play,resumez,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=2;
					Mix_PlayChannel(2, son2, 0);

		}
		else  if((event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>380)&&(event.motion.y<430)&&(press==1))
		{
					menu(ecran, imageDeFond,cursor,play,resume,optionsz,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=3;
					Mix_PlayChannel(2, son2, 0);
		}
		else if((event.motion.x>270)&&(event.motion.x<490)&&(event.motion.y>440)&&(event.motion.y<490)&&(press==1))
		{
					menu(ecran, imageDeFond,cursor,play,resume,options,exitz,text,&positiontext,&positionFond, &positionbouton,&positioncursor);
                    selectedButton=4;
					Mix_PlayChannel(2, son2, 0);
		}
		else if(press==1)
		{
								menu(ecran, imageDeFond,cursor,play,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);

		}
		break;
		
}

		break;
}

/*affichage 1ere image */
if(coat)
{
					   Mix_PlayMusic(introson, 1);

for(i=0;i<705;i++)
{
	SDL_BlitSurface(intro[0],NULL,ecran,&positionFond);
	SDL_BlitSurface(intro[i],NULL,ecran,&positionFond);
	SDL_Flip(ecran);
	SDL_Delay(21);
}
coat=0;

}
		if(press==0 && !coat)
{



tempsActuel = SDL_GetTicks();

        if (tempsActuel - tempsPrecedent > 500) 
        {
			SDL_BlitSurface(affiche, NULL, ecran, &positionFond);
			
            tempsPrecedent = tempsActuel;
        }
		else 
		{
			SDL_BlitSurface(affiche, NULL, ecran, &positionFond);
	  		SDL_BlitSurface(text1, NULL, ecran, &positiontext1); 
		}
	//	SDL_Flip(ecran);
}
else
{	if(press1==0)
				{		
Mix_PlayMusic(mus,0);
					for(i=1;i<=32;i++)
					{
								SDL_Delay(10);
	
						SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
						SDL_BlitSurface(IMG[i],NULL,ecran,&positionFond);
						
						SDL_Flip(ecran);
						
						
					}
					press1=1;
									menu(ecran, imageDeFond,cursor,play,resume,options,exit,text,&positiontext,&positionFond, &positionbouton,&positioncursor);

					
				}
}




			SDL_GetMouseState(&x,&y);
positioncursor.x=x;
	positioncursor.y=y;
	SDL_BlitSurface(cursor, NULL, ecran, &positioncursor);	
	SDL_Flip(ecran);
	
	
	}
		TTF_CloseFont(police);
 		SDL_FreeSurface(text);
   		TTF_Quit();
		Mix_FreeMusic(mus);
		Mix_FreeChunk(son);//Libération du son 1
  		Mix_FreeChunk(son2); 
   		Mix_CloseAudio(); 
  	  	SDL_Quit();
      return EXIT_SUCCESS;
}