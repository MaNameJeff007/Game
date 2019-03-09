 #include "enigme.h"

Enigme Init_Enigme()
{
    Enigme E;
    SDL_Color couleur = {0, 0, 0} ;

    E.QuestionPart1 = (char *)malloc(sizeof(char) * 100 );
    E.QuestionPart2 = (char *)malloc(sizeof(char) * 100 );
    E.QuestionPart3 = (char *)malloc(sizeof(char) * 100 );
    E.Answer1 =  (char *)malloc(sizeof(char) * 50 );
    E.Answer2 =  (char *)malloc(sizeof(char) * 50 );
    E.Answer3 =  (char *)malloc(sizeof(char) * 50 );
    strcpy(E.QuestionPart1, "") ;
    strcpy(E.QuestionPart2, "") ;
    strcpy(E.QuestionPart3, "") ;
    strcpy(E.Answer1, "") ;
    strcpy(E.Answer2, "") ;
    strcpy(E.Answer3, "") ;
   E.Font = TTF_OpenFont("Font/Norse-Bold.otf", 30);
  
    E.UserInput = 0 ;
    E.solution = 0 ;
    E.QuestionPart1Pos.x = 0 ;
    E.QuestionPart1Pos.y = 0 ;
    E.QuestionPart2Pos.x = 0 ;
    E.QuestionPart2Pos.y = 0 ;
    E.QuestionPart3Pos.x = 0 ;
    E.QuestionPart3Pos.y = 0 ;
    E.Answer1Pos.x = 0 ;
    E.Answer1Pos.y = 0 ;
    E.Answer2Pos.x = 0 ;
    E.Answer2Pos.y = 0 ;
    E.Answer3Pos.x = 0 ;
    E.Answer3Pos.y = 0 ;
    E.cadre=IMG_Load("image/cadre.png");
    E.indice[0]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"always aim for the top", couleur);
    E.indice[1]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"even rocks hide some secrets", couleur);
    E.indice[2]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"gold can sometimes be found near water", couleur);
    E.indice[3]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"beware of skulls, they bring trouble", couleur);
    E.posindice.x=100;
    E.posindice.y=300;
    return E ;
}


Enigme Init_Enigme2()
{
    Enigme E;
    SDL_Color couleur = {0, 0, 0} ;

    E.QuestionPart1 = (char *)malloc(sizeof(char) * 100 );
    E.QuestionPart2 = (char *)malloc(sizeof(char) * 100 );
    E.QuestionPart3 = (char *)malloc(sizeof(char) * 100 );
    E.Answer1 =  (char *)malloc(sizeof(char) * 50 );
    E.Answer2 =  (char *)malloc(sizeof(char) * 50 );
    E.Answer3 =  (char *)malloc(sizeof(char) * 50 );
    strcpy(E.QuestionPart1, "") ;
    strcpy(E.QuestionPart2, "") ;
    strcpy(E.QuestionPart3, "") ;
    strcpy(E.Answer1, "") ;
    strcpy(E.Answer2, "") ;
    strcpy(E.Answer3, "") ;
   E.Font = TTF_OpenFont("Font/Norse-Bold.otf", 30);
  
    E.UserInput = 0 ;
    E.solution = 0 ;
    E.QuestionPart1Pos.x = 0 ;
    E.QuestionPart1Pos.y = 0 ;
    E.QuestionPart2Pos.x = 0 ;
    E.QuestionPart2Pos.y = 0 ;
    E.QuestionPart3Pos.x = 0 ;
    E.QuestionPart3Pos.y = 0 ;
    E.Answer1Pos.x = 0 ;
    E.Answer1Pos.y = 0 ;
    E.Answer2Pos.x = 0 ;
    E.Answer2Pos.y = 0 ;
    E.Answer3Pos.x = 0 ;
    E.Answer3Pos.y = 0 ;
    E.cadre=IMG_Load("image/cadre.png");
    E.indice[0]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"always aim for the top", couleur);
    E.indice[1]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"even rocks hide some secrets", couleur);
    E.indice[2]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"gold can sometimes be found near water", couleur);
    E.indice[3]= TTF_RenderText_Blended(TTF_OpenFont("Font/Norse-Bold.otf", 70),"beware of skulls, they bring trouble", couleur);
    E.posindice.x=930;
    E.posindice.y=300;
    return E ;
}


Enigme Generate_Enigme(Enigme e)
{
    int i =rand() % 4 + 1 ;
    
    char filename[50], tmp[4];
    if(i<5){
    sprintf( filename, "enigme/%d.txt", i);
    FILE *f = fopen(filename, "r");

    fscanf(f, "%s", e.QuestionPart1);
    fscanf(f, "%s", e.QuestionPart2);
    fscanf(f, "%s", e.QuestionPart3);
    fscanf(f, "%s", e.Answer1);
    fscanf(f, "%s", e.Answer2);
    fscanf(f, "%s", e.Answer3);
    fscanf(f, "%s", tmp);
    e.solution = tmp[2] - 48 ;

    e.QuestionPart1 = Replace_Hyphen( e.QuestionPart1 ) ;
    e.QuestionPart2 = Replace_Hyphen( e.QuestionPart2 ) ;
    e.QuestionPart3 = Replace_Hyphen( e.QuestionPart3 ) ;
    e.Answer1 = Replace_Hyphen( e.Answer1 ) ;
    e.Answer2 = Replace_Hyphen( e.Answer2 ) ;
    e.Answer3 = Replace_Hyphen( e.Answer3 ) ;

    fclose(f);
    }
        else
    {
        int rand_x = rand() % 9 + 1, rand_y = rand() % 9 + 1, s = rand() % 3 + 1 ;
        float answer1, answer2, answer3 ;

        if( s == 1 )
        {
            answer1 =  - ( (float) rand_y / rand_x ) ;
            answer2 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer3 = (float)( rand() % 1000 + 100 ) / -100 ;
        }
        else if( s == 2 )
        {
            answer1 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer2 =  - ( (float) rand_y / rand_x ) ;
            answer3 = (float)( rand() % 1000 + 100 ) / -100 ;
        }
        else if( s == 3 )
        {
            answer1 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer2 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer3 = - ( (float) rand_y / rand_x ) ;
        }
        sprintf( e.QuestionPart1, "Q: What's The Solution To %dX + %d ?", rand_x, rand_y ) ;
        sprintf( e.Answer1, "1:%.2f", answer1 ) ;
        sprintf( e.Answer2, "2:%.2f", answer2 ) ;
        sprintf( e.Answer3, "3:%.2f", answer3 ) ;
        e.solution = s ;
    }
    return e ;
}


void resultat(Enigme e,score *sc,int *animation,int *animationpiece,int v)
{  
     if(e.UserInput == e.solution) 
     {sc->n_piece++;
     *animationpiece=1;

     }
     else if (e.UserInput != e.solution || !v) 
     {sc->n_vie--;
     *animation=1;
     } 
}

void resultat_2(Enigme e,score *sc,int *animation,int v, int *i)
{  
     if(e.UserInput == e.solution) 
     {
            *i=1;
     }
     else if (e.UserInput != e.solution || !v) 
     {sc->n_vie--;
     *animation=1;
     } 
}

void afficher_Enigme(SDL_Surface *ecran, Enigme e)
{
    SDL_Color couleur = {0, 0, 0} ;
    SDL_Rect CadrePos;
    SDL_Surface * tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart1, couleur);
    CadrePos.x = 100;
    CadrePos.y = 200 ;
    SDL_BlitSurface(e.cadre, NULL, ecran, &CadrePos);
    e.QuestionPart1Pos.x = (800)*0.25 ;
    e.QuestionPart1Pos.y = ecran->h *0.6 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart2, couleur);
    e.QuestionPart2Pos.x = (800)*0.25 ;
    e.QuestionPart2Pos.y = ecran->h*0.65;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart3, couleur);
    e.QuestionPart3Pos.x = (800)*0.25 ;
    e.QuestionPart3Pos.y = ecran->h*0.7 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart3Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer1, couleur);
    e.Answer1Pos.x =(800)*0.3 ;
    e.Answer1Pos.y = ecran->h*0.75 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer2, couleur);
    e.Answer2Pos.x = (800) *0.3 ;
    e.Answer2Pos.y = ecran->h *0.8 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer3, couleur);
    e.Answer3Pos.x = (800) *0.3 ;
    e.Answer3Pos.y = ecran->h*0.85 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer3Pos);

    SDL_FreeSurface(tmp);
}

void afficher_Enigme2(SDL_Surface *ecran, Enigme e)
{
    SDL_Color couleur = {0, 0, 0} ;
    SDL_Rect CadrePos;
    SDL_Surface * tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart1, couleur);
    CadrePos.x = 900;
    CadrePos.y = 200 ;
    SDL_BlitSurface(e.cadre, NULL, ecran, &CadrePos);
    e.QuestionPart1Pos.x = (ecran->w/2)*1.25 ;
    e.QuestionPart1Pos.y = ecran->h *0.6 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart2, couleur);
    e.QuestionPart2Pos.x = (ecran->w/2)*1.25 ;
    e.QuestionPart2Pos.y = ecran->h*0.65;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.QuestionPart3, couleur);
    e.QuestionPart3Pos.x = (ecran->w/2)*1.25 ;
    e.QuestionPart3Pos.y = ecran->h*0.7 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.QuestionPart3Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer1, couleur);
    e.Answer1Pos.x =(ecran->w/2)*1.3 ;
    e.Answer1Pos.y = ecran->h*0.75 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer1Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer2, couleur);
    e.Answer2Pos.x = (ecran->w/2) *1.3 ;
    e.Answer2Pos.y = ecran->h *0.8 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer2Pos);
    SDL_FreeSurface(tmp);
    tmp = TTF_RenderText_Blended(e.Font, e.Answer3, couleur);
    e.Answer3Pos.x = (ecran->w/2) *1.3 ;
    e.Answer3Pos.y = ecran->h*0.85 ;
    SDL_BlitSurface(tmp, NULL, ecran, &e.Answer3Pos);

    SDL_FreeSurface(tmp);
}

char * Replace_Hyphen(char *str)
{
    int i, len = strlen(str);

    for( i = 0; i < len; i++ )
        if( str[i] == '_' )
            str[i] = ' ' ;

    return str ;
}

int collision_enigme(background map,player p,SDL_Rect pos)
{
       
        
     SDL_Color col;
  
    col=GetPixel(map.mapCollision,pos.x+p.fen->w,pos.y+p.fen->h);


if ((col.r==255)&&(col.b==255)&&(col.g==255))
 return 1;
if ((col.r==255)&&(col.b==255)&&(col.g==0))
return 2;
if ((col.r==255)&&(col.b==0)&&(col.g==255))
return 3;
if ((col.r==0)&&(col.b==255)&&(col.g==255))
return 4;
else
return 0;
}

void test_enigme(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,int *animationpiece,SDL_Rect poswar9a,SDL_Surface *war9a,int *w,int *ind,int *hint,son s)
{    
    SDL_Color couleur = {0, 0, 0} ;
    SDL_Rect pos_key;
        SDL_Surface *key=TTF_RenderText_Blended(en.Font,"(press G)", couleur);
        pos_key.x= 330;
    pos_key.y=370;

        
int v;
if(pos.x<=poswar9a.x+20 && pos.x>=poswar9a.x-20 && pos.y>=poswar9a.y+110 && pos.y<=poswar9a.y+120 && sc->n_piece==0)
{
        *w=0;
        if (*hint==0 && sc->n_piece==0)
        {
                SDL_BlitSurface(en.indice[0],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        *ind=1;
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_g:
                                        *hint=2;
                                        break;
                        }
                        break;
        }
        }
        
}

if(collision_enigme(bg,p,pos)==3 && (sc->n_piece==0) && *hint==2)
{ 
afficher_Enigme(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_c:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_v:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_b:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);


en.UserInput=0;
        }
if(sc->n_piece==1 )
{
      
        en=Generate_Enigme(en);

}
                       
}
     if ((*hint)==2 && sc->n_piece==1)
        {
                SDL_BlitSurface(en.indice[1],NULL,ecran,&en.posindice);
                 SDL_BlitSurface(key,NULL,ecran,&pos_key);
               
        
        switch (event.type)
        {

                printf("%d",*hint);
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_g:
                                        *hint=1;
                                        break;
                        }
                        break;
        }
        }

if(collision_enigme(bg,p,pos)==2 && (sc->n_piece==1))
{                 printf("%d",*hint);

afficher_Enigme(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_c:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_v:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_b:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);


en.UserInput=0;
        }
if(sc->n_piece==2)
{
        
        en=Generate_Enigme(en);

        }
                         
}
if (*hint==1 && sc->n_piece==2)
        {
                SDL_BlitSurface(en.indice[2],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_RETURN:
                                        *hint=3;
                                        break;
                        }
                        break;
        }
}
if(collision_enigme(bg,p,pos)==1 && (sc->n_piece==2))
{ 
afficher_Enigme(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);


en.UserInput=0;
        }
if(sc->n_piece==3)
{
        
        
        en=Generate_Enigme(en);

        }
                           
}
if (*hint==3 && sc->n_piece==3)
        {
                SDL_BlitSurface(en.indice[3],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_g:
                                        *hint=4;
                                        break;
                        }
                        break;
        }
        }

if(collision_enigme(bg,p,pos)==4 && (sc->n_piece==3))
{
afficher_Enigme(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_c:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_v:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_b:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);
en.UserInput=0;
        }
        if(sc->n_piece==4)
        sc->stage=2;
}
}



void test_enigme2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,int *animationpiece,SDL_Rect poswar9a,SDL_Surface *war9a,int *w,int *ind,int *hint,son s)
{    
    SDL_Color couleur = {0, 0, 0} ;
    SDL_Rect pos_key;
        SDL_Surface *key=TTF_RenderText_Blended(en.Font,"(press ENTER)", couleur);
        pos_key.x= 1130;
    pos_key.y=370;

        
        int v;
if(pos.x<=poswar9a.x+20 && pos.x>=poswar9a.x-20 && pos.y>=poswar9a.y+110 && pos.y<=poswar9a.y+120 && sc->n_piece==0)
{
        *w=0;
        if (*hint==0 && sc->n_piece==0)
        {
                SDL_BlitSurface(en.indice[0],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        *ind=1;
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_RETURN:
                                        *hint=2;
                                        break;
                        }
                        break;
        }
        }
        
}

if(collision_enigme(bg,p,pos)==3 && (sc->n_piece==0) && *hint==2)
{ 
afficher_Enigme2(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme2(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);

en.UserInput=0;
        }
if(sc->n_piece==1 )
{
      
        en=Generate_Enigme(en);

}
                       
}
     if ((*hint)==2 && sc->n_piece==1)
        {
                SDL_BlitSurface(en.indice[1],NULL,ecran,&en.posindice);
                 SDL_BlitSurface(key,NULL,ecran,&pos_key);
               
        
        switch (event.type)
        {

                printf("%d",*hint);
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_RETURN:
                                        *hint=1;
                                        break;
                        }
                        break;
        }
        }

if(collision_enigme(bg,p,pos)==2 && (sc->n_piece==1))
{                 printf("%d",*hint);

afficher_Enigme2(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme2(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);


en.UserInput=0;
        }
if(sc->n_piece==2)
{
        
        en=Generate_Enigme(en);

        }
                         
}
if (*hint==1 && sc->n_piece==2)
        {
                SDL_BlitSurface(en.indice[2],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_RETURN:
                                        *hint=3;
                                        break;
                        }
                        break;
        }
}
if(collision_enigme(bg,p,pos)==1 && (sc->n_piece==2))
{ 
afficher_Enigme2(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
v= timeenigme2(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
resultat(en,sc,animation,animationpiece,v);


en.UserInput=0;
        }
if(sc->n_piece==3)
{
        
        
        en=Generate_Enigme(en);

        }
                           
}
if (*hint==3 && sc->n_piece==3)
        {
                SDL_BlitSurface(en.indice[3],NULL,ecran,&en.posindice);
                SDL_BlitSurface(key,NULL,ecran,&pos_key);
                
        
        switch (event.type)
        {
                case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                                case SDLK_RETURN:
                                        *hint=4;
                                        break;
                        }
                        break;
        }
        }

if(collision_enigme(bg,p,pos)==4 && (sc->n_piece==3))
{
afficher_Enigme2(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
									switch ( event . key . keysym . sym )
										{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
        v= timeenigme2(ecran,*sc,timee,s);
        if(en.UserInput!=0 || !v)
        { *timee=30;
        resultat(en,sc,animation,animationpiece,v);
        en.UserInput=0;
        }
}
}

void test_enigme_2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,son s)
{
        SDL_Surface *g[3];
        SDL_Rect abc;
        abc.x=0;
        abc.y=0;
        g[1]=IMG_Load("image/victoire1");
        g[2]=IMG_Load("image/victoire2");
        g[3]=IMG_Load("image/victoire3");
        int i=0,k;
        int v;
        if(collision_enigme(bg,p,pos)==1)
{ 
afficher_Enigme(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
					switch ( event . key . keysym . sym )
					{
                                            case SDLK_c:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_v:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_b:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
        v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
        resultat_2(en,sc,animation,v,&i);
        if (i==1)
        {
                for(k=0;k<3;k++)
                {
                SDL_BlitSurface(g[i], NULL, ecran,&abc );
                SDL_Flip(ecran);
                SDL_Delay(500);
                }
        }


        en.UserInput=0;
        }          
        }

}

void test_enigme2_2(SDL_Event event,SDL_Surface *ecran,Enigme en,score *sc,background bg,SDL_Rect pos,player p,int *timee,int *animation,son s)
{

        SDL_Surface *g[3];
        SDL_Rect abc;
        abc.x=0;
        abc.y=0;
        g[1]=IMG_Load("image/victoire1");
        g[2]=IMG_Load("image/victoire2");
        g[3]=IMG_Load("image/victoire3");
        int v,k;
        int i=0;
        if(collision_enigme(bg,p,pos)==1)
{ 
afficher_Enigme2(ecran,en);
switch(event.type)
        {
            case SDL_KEYDOWN:
					switch ( event . key . keysym . sym )
					{
                                            case SDLK_KP1:
                                            en.UserInput=1;
                                            break;
                                            case SDLK_KP2:
                                            en.UserInput=2;
                                            break;
                                            case SDLK_KP3:
                                            en.UserInput=3;
                                            break;
                                        }
                                        break;
        }
        
        v= timeenigme(ecran,*sc,timee,s);
        
        if(en.UserInput!=0 || !v)
        { *timee=30;
        resultat_2(en,sc,animation,v,&i);
if (i==1)
        {
                for(k=0;k<3;k++)
                {
                SDL_BlitSurface(g[i], NULL, ecran,&abc );
                SDL_Flip(ecran);
                SDL_Delay(500);
                }
        }

        en.UserInput=0;
        }          
        }

}