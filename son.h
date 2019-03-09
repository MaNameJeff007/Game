#ifndef SON_H_
#define SON_H_
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

struct son
{
    Mix_Music *background;
    Mix_Music *score; //lorsque score-- (damou yon9oss)
    Mix_Music *defeat;
    Mix_Music *victoire;
    Mix_Music *piece;
    Mix_Music *collision;
    Mix_Music *ennemi;  
    Mix_Music *temps;
};
typedef struct son son;

void init_son(son *s);
void play_toujours_son(son s);
void play_score(son s);
void play_defeat(son s);
void play_ennemi(son s);
void play_victoire(son s);
void play_temps(son s);
void play_collision(son s);
void play_piece(son s);
void pause_son();
void resume_son();
void stop_son();
void free_son(son *s);

#endif /* SON_H_ */
