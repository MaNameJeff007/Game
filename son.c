#include "son.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void init_son(son *s)
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    s->temps=Mix_LoadMUS("son/time.mp3");
    s->background=Mix_LoadMUS("son/son_continu.mp3");
    //s->score=Mix_LoadMUS("son/score.wav");
    s->defeat=Mix_LoadMUS("son/Youlose.mp3");
    s->piece=Mix_LoadMUS("son/correct.mp3");
    //s->victoire=Mix_LoadMUS("son/victory.wav");
    s->collision=Mix_LoadMUS("son/collision.mp3");
    s->ennemi=Mix_LoadMUS("son/ennemi.mp3");
}

void play_toujours_son(son s)
{
    Mix_PlayMusic(s.background, -1);
}

/*void play_score(son s)
{
    Mix_PlayMusic(s.score, 0);
}*/

void play_temps(son s)
{
    Mix_PlayMusic(s.temps, 0);
}

void play_defeat(son s)
{
    Mix_PlayMusic(s.defeat, 0);
}
/*
void play_victoire(son s)
{
    Mix_PlayMusic(s.victoire, 0);
}
*/
void play_collision(son s)
{
    Mix_PlayMusic(s.collision, 0);
}

void play_ennemi(son s)
{
    Mix_PlayMusic(s.ennemi, 0);
}

void play_piece(son s)
{
    Mix_PlayMusic(s.piece, 0);
}
/*
void pause_son()
{
    Mix_PauseMusic();
}

void resume_son()
{
    Mix_ResumeMusic();
}

void stop_son() //le stop stop complétement et on doit le rejour dès le début(3awed milowel)
{
    Mix_HaltMusic();
}

void free_son(son *s)
{
    Mix_FreeMusic(s->background);
    Mix_FreeMusic(s->collision);
    Mix_FreeMusic(s->defeat);
    Mix_FreeMusic(s->piece);
    Mix_FreeMusic(s->score);
    Mix_FreeMusic(s->victoire);
    Mix_FreeMusic(s->ennemi);
    Mix_CloseAudio();
}*/