#ifndef CAMERA_H_
#define CAMERA_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player1.h"
#include "bg.h"

struct Camera
{
    SDL_Rect cam;
};
typedef struct Camera camera;

void init_camera(camera *c);
void init_camera2(camera *c);
void centrer_camera(camera *c, player p);
void afficher_camera(camera *c, background bg, SDL_Surface *ecran, player p);
void afficher_camera2(camera *c, background bg, SDL_Surface *ecran, player p);

#endif /* CAMERA_H_ */
