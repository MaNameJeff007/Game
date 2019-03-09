#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include <time.h>
#include <SDL/SDL_rotozoom.h>
#include "game.h"

void SaveGame( player player, camera c,score sc,  char filename[50] )
{
    FILE * f = fopen(filename, "wb" ) ;
    fwrite( &c, sizeof(SDL_Rect), 1, f ) ;
    fwrite( &sc.n_vie, sizeof(int), 1, f ) ;
    fwrite( &sc.n_piece, sizeof(int), 1, f ) ;
    fwrite( &player.pos, sizeof(SDL_Rect), 1, f ) ;
    fclose(f);
}

void LoadGame( player *player, camera *c,score *sc, char filename[50] )
{
    int tmp ;
    FILE * f = fopen(filename, "rb" ) ;
    fread( c, sizeof(SDL_Rect), 1, f ) ;
    fread(&sc->n_vie,sizeof(int),1,f);
    fread(&sc->n_piece,sizeof(int),1,f);
    fread( &player->pos, sizeof(SDL_Rect), 1, f ) ;
    fclose(f);
}

void playgame(SDL_Surface *ecran,int *continuer,int *fullscreen,int modegame, int newgame)
{
        SDL_Surface *quit=NULL;
        SDL_Color couleur={0,0,0};
        SDL_Rect posquit;
        SDL_Surface *cursor=NULL;
        int quitgame=0;
        speed sp,sp2;
        saut jump,jump2;
        SDL_Rect pos_e,pos_e2;
        Minimap minimap,minimap2;
        son s;
        ennemi e,e2;
        score sc,sc2;
        Enigme en,en2;
        camera c,c2;
        background bg,bg2;
        player p,p2;
        move m,m2;
        SDL_Rect pos;
        pos.x=0;
        pos.y=0;
        SDL_Surface *crow[17],*war9a=NULL,*war9a2=NULL,*cino[1713],*passage[258];
        char img[20];
        int j;
        system("sudo chmod a+wr /dev/ttyACM0");
	FILE *o = fopen("/dev/ttyACM0", "r+");
        for(j=0;j<258;j++)
        {
                if(j<10)
                sprintf(img,"victory00%d.jpg",j);
                if(j>=10 && j<100)
         sprintf(img,"victory0%d.jpg",j);
         if(j>=100)
                         sprintf(img,"victory%d.jpg",j);
                passage[j]=IMG_Load(img);
        }
        for(j=0;j<18;j++)
        {
                sprintf(img,"crow/crow-%d.png",j);
                crow[j]=IMG_Load(img);
        }
        init_son(&s); 
        war9a=IMG_Load("image/war9a.png");
        war9a2=IMG_Load("image/war9a.png");
        SDL_Rect poscrow,poswar9a,posss;
        SDL_Rect poscrow2,poswar9a2,posss2;
        poscrow.x=10;
        poscrow.y=300;
        poscrow2.x=810;
        poscrow2.y=300;
        SDL_Event event;
        float zoom=0.15;
        int stage=0,deplacement=0,cinoo=1,bye=0;
        SDL_Surface *Fond=NULL,*player=NULL,*Cadre=NULL;
        SDL_Rect posplayer,posplayer2;
        int game=1,animation=0,animationpiece=0,t=30;
        int animation2=0,animationpiece2=0,t2=30;
        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
        srand(time(NULL));
        if (modegame==1)
                ecran = SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
        else if(modegame==2)
                ecran = SDL_SetVideoMode(1600,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
        init_ennemi(&e);
        init_ennemi(&e2);
        init_minimap(&minimap,ecran);
        init_minimap2(&minimap2,ecran);
        init_score(&sc);
        init_score(&sc2);
        init_Back(&bg);
        init_Back2(&bg2);
        int i=0,x=0,d,cro=0,cr=9,w=0,ind=0,hint=0,f=0,f2=0,follow=0,wait=1,attack=0;
        int cro2=0,cr2=9,w2=0,hint2=0,ind2=0,y=0,y2=0,follow2=0,wait2=1,attack2=0;
        init_player(&p,&m,&sp,&jump);
        init_player2(&p2,&m2,&sp2,&jump2);
        init_camera(&c);      
        init_camera2(&c2);
        afficher_camera2(&c2,bg,ecran,p2);
        afficher_camera(&c,bg,ecran,p);
        display_player(&p,ecran);
        display_player(&p2,ecran);
        draw_Vie(&sc,ecran,s);
        draw_piece(sc,ecran);
        draw_Vie2(&sc2,ecran,s,c2,bg,p,sc);
        draw_piece2(sc2,ecran);
        SDL_Flip(ecran);
        en=Init_Enigme();
        en=Generate_Enigme(en);
        en2=Init_Enigme2();
        en2=Generate_Enigme(en2);
        quit=TTF_RenderText_Blended((TTF_OpenFont("Font/Norse-Bold.otf", 52)),"Quit ?  save(Y)  Don't save(N)",couleur);
        if(newgame && modegame==1)
                 LoadGame(&p,&c,&sc,"save/save.bin");
        if(newgame && modegame==2)
        {
                LoadGame(&p,&c,&sc,"save/save1.bin");
                LoadGame(&p2,&c2,&sc2,"save/save2.bin");
        }
        posquit.x=ecran->w/2-200;
        posquit.y=300;
                        play_toujours_son(s);   

        while(game)
        {
                SDL_PollEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                        game=0;
                        *continuer=0;
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                        case SDLK_ESCAPE:
                        quitgame=1;
                        break;
                }
                break;
                          
                }
                if (modegame==1)
                {
        if(!sc.over)
       {
        pos_e.x=e.position.x+c.cam.x;
        pos_e.y=e.position.y+c.cam.y;
        afficher_camera(&c,bg,ecran,p);
        transitionn(&e,p,bg,c,pos_e, &sc,ecran,&f,&animation,&follow,&wait,&attack,s);
        Afficher_Minimap(ecran,event,&minimap,p.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        posplayer.x=p.pos.x+c.cam.x;
        posplayer.y=p.pos.y+c.cam.y;

        handle_input(event, &p,ecran,&bg,&i,posplayer,&m,s,&sp,&jump,o);
        handle_inputsouris(event,&p,ecran,&bg,&i,posplayer,&m,s,&sp);
        test_enigme(event,ecran,en,&sc,bg,posplayer,p,&t,&animation,&animationpiece,poswar9a,war9a,&w,&ind,&hint,s);
      
    
effect(c,bg,p,sc,&animation,&animationpiece,ecran,s);
draw_piece(sc,ecran);
draw_Vie(&sc,ecran,s); 
        if (newgame==0){
 if(!cro)
        {
                        
            
            poscrow.x+=5;
            poscrow.y-=5;
     
                        if(poscrow.x==250)
                        cr=0;
                        if(cr==8 && !w)
                        {
                                poswar9a.x=poscrow.x+c.cam.x;
                                poswar9a.y=poscrow.y+c.cam.y;
                        w=1;
                        }
                        
                        
                        if(cr>17)
                        cr=9;

                        SDL_Delay(20);
                if(poscrow.x>800)
                cro=1;
               SDL_BlitSurface(crow[cr],NULL,ecran,&poscrow);
                     cr++;
        }
        if(w)
        {
                posss.x=poswar9a.x-c.cam.x+50;
                posss.y=poswar9a.y-c.cam.y+200;
          
                
        SDL_BlitSurface(war9a,NULL,ecran,&posss);
        
        }}
        
    


       }
       if(sc.stage==2 && !animationpiece)
       {
               for(j=0;j<258;j++)
               {
                       SDL_BlitSurface(passage[j],NULL,ecran,&pos);
                       SDL_Flip(ecran);
                       SDL_Delay(20);
               }
       }
       if(!sc.over && sc.stage==2)
       {
        afficher_camera(&c,bg2,ecran,p);
        Afficher_Minimap(ecran,event,&minimap2,p.pos);
        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
        posplayer.x=p.pos.x+c.cam.x;
        posplayer.y=p.pos.y+c.cam.y;
        handle_input(event, &p,ecran,&bg2,&i,posplayer,&m,s,&sp,&jump,o);
        test_enigme_2(event,ecran,en,&sc,bg2,posplayer,p,&t,&animation,s);
        //handle_inputsouris(event,&p,ecran,&bg,&i,posplayer,&m,s,&sp);
        effect_2(c,bg,p,sc,&animation,ecran,s);
        draw_Vie(&sc,ecran,s); 

       }
                }

                else if (modegame==2)
                {

                if(!sc2.over)
                {
                        pos_e2.x=e2.position.x+c2.cam.x;
                        pos_e2.y=e2.position.y+c2.cam.y;
                        afficher_camera2(&c2,bg,ecran,p2);
                        SDL_BlitSurface(p2.fen, NULL, ecran, &p2.pos);
                        transitionn(&e2,p2,bg,c2,pos_e2, &sc2,ecran,&f2,&animation2,&follow2,&wait2,&attack2,s);
                        posplayer2.x=p2.pos.x+c2.cam.x;
                        posplayer2.y=p2.pos.y+c2.cam.y;
                        handle_input2(event, &p2,ecran,&bg,&x,posplayer2,&m2,s,&sp2,&jump2);
                        test_enigme2(event,ecran,en2,&sc2,bg,posplayer2,p2,&t2,&animation2,&animationpiece2,poswar9a2,war9a2,&w2,&ind2,&hint2,s);
                        effect2(c,bg,p2,sc2,&animation2,&animationpiece2,ecran,s,p,sc,c2);
                        draw_Vie2(&sc2,ecran,s,c2,bg,p,sc);
                        draw_piece2(sc2,ecran);
                        if(newgame==0)
                        {
                        if(!cro2)
                        {
                                poscrow2.x+=5;
                                poscrow2.y-=5;
     
                                if(poscrow2.x==1050)
                                        cr2=0;
                                if(cr2==8 && !w2)
                                {
                                        poswar9a2.x=poscrow2.x+c2.cam.x;
                                        poswar9a2.y=poscrow2.y+c2.cam.y;
                                        w2=1;
                                }
                                if(cr2>17)
                                        cr2=9;
                                SDL_Delay(20);
                                if(poscrow2.x+139>1600)
                                        cro2=1;
                                SDL_BlitSurface(crow[cr2],NULL,ecran,&poscrow2);
                                cr2++;
                        }    
                        if(w2)
                        {
                                posss2.x=poswar9a2.x-c2.cam.x+50;
                                posss2.y=poswar9a2.y-c2.cam.y+200;       
                                SDL_BlitSurface(war9a,NULL,ecran,&posss2);
                        }
                        }
                }
                if(sc.stage==2 && !animationpiece)
       {
               for(j=0;j<258;j++)
               {
                       SDL_BlitSurface(passage[j],NULL,ecran,&pos);
                       SDL_Flip(ecran);
                       SDL_Delay(20);
               }
       }
       if(!sc2.over && sc2.stage==2)
       {
        afficher_camera(&c2,bg2,ecran,p2);
        SDL_BlitSurface(p2.fen, NULL, ecran, &p2.pos);
        posplayer2.x=p2.pos.x+c2.cam.x;
        posplayer2.y=p2.pos.y+c2.cam.y;
        handle_input2(event, &p2,ecran,&bg2,&x,posplayer2,&m2,s,&sp2,&jump2);
        test_enigme2_2(event,ecran,en2,&sc2,bg2,posplayer2,p2,&t2,&animation2,s);
        //handle_inputsouris(event,&p,ecran,&bg,&i,posplayer,&m,s,&sp);
        effect_2(c2,bg2,p2,sc2,&animation2,ecran,s);
        draw_Vie(&sc2,ecran,s); 

       }
                if(!sc.over)
                {
                        pos_e.x=e.position.x+c.cam.x;
                        pos_e.y=e.position.y+c.cam.y;
                        afficher_camera(&c,bg,ecran,p);
                        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
                        transitionn(&e,p,bg,c,pos_e, &sc,ecran,&f,&animation,&follow,&wait,&attack,s);
                        posplayer.x=p.pos.x+c.cam.x;
                        posplayer.y=p.pos.y+c.cam.y;
                        handle_input(event, &p,ecran,&bg,&i,posplayer,&m,s,&sp,&jump,o);
                        test_enigme(event,ecran,en,&sc,bg,posplayer,p,&t,&animation,&animationpiece,poswar9a,war9a,&w,&ind,&hint,s);
                        effect(c,bg,p,sc,&animation,&animationpiece,ecran,s);
                        draw_Vie(&sc,ecran,s);
                        draw_piece(sc,ecran);
                        if(newgame==0)
                        {

                        if(!cro)
                        {
                                poscrow.x+=5;
                                poscrow.y-=5;
                                
                                if(poscrow.x==250)
                                        cr=0;
                                if(cr==8 && !w)
                                {
                                        poswar9a.x=poscrow.x+c.cam.x;
                                        poswar9a.y=poscrow.y+c.cam.y;
                                        w=1;
                                }
                        
                                if(cr>17)
                                        cr=9;
                                SDL_Delay(20);
                                if(poscrow.x+139>800)
                                        cro=1;
                               
                                SDL_BlitSurface(crow[cr],NULL,ecran,&poscrow);

                                cr++;

                        }
                        if(w)
                        {
                                posss.x=poswar9a.x-c.cam.x+50;
                                posss.y=poswar9a.y-c.cam.y+200;
                                SDL_BlitSurface(war9a,NULL,ecran,&posss);
                        }
                        }
                }
                if(!sc.over && sc.stage==2)
                {
                        afficher_camera(&c,bg2,ecran,p);
                        SDL_BlitSurface(p.fen, NULL, ecran, &p.pos);
                        posplayer.x=p.pos.x+c.cam.x;
                        posplayer.y=p.pos.y+c.cam.y;
                        handle_input(event, &p,ecran,&bg2,&i,posplayer,&m,s,&sp,&jump,o);
                        test_enigme_2(event,ecran,en,&sc,bg2,posplayer,p,&t,&animation,s);
                        //handle_inputsouris(event,&p,ecran,&bg,&i,posplayer,&m,s,&sp);
                        effect_2(c,bg2,p,sc,&animation,ecran,s);
                        draw_Vie(&sc,ecran,s); 
                }
                if(sc.stage==1 || sc2.stage==1)
                        Afficher_Minimap2(ecran,event,&minimap,p.pos,p2.pos);
                
                else
                        Afficher_Minimap2(ecran,event,&minimap2,p.pos,p2.pos);}
                SDL_Flip(ecran);
                 while(game && quitgame)
                {
                SDL_BlitSurface(quit,NULL,ecran,&posquit);
                SDL_Flip(ecran);
                          SDL_WaitEvent(&event);      
                switch(event.type)
                         {
            case SDL_KEYDOWN : 
                switch ( event . key . keysym . sym )
                {
                        case SDLK_y:
                        if(modegame==1)
                         SaveGame(p,c,sc,"save.bin");
                         else if(modegame==2){
                                SaveGame(p,c,sc,"save1.bin");
                                SaveGame(p2,c2,sc2,"save2.bin");
                                }
                        game=0;
                        quitgame=0;
                        *continuer=0;
                        break;
                        case SDLK_n:
                        game=1;
                        quitgame=0;
                        break;
                }
                }
                }
        }
}