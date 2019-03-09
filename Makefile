prog:main.o game.o player1.o bg.o camera.o enigme.o score.o ennemi.o son.o AI.o
	gcc main.o game.o player1.o bg.o camera.o enigme.o score.o ennemi.o son.o AI.o -lm /usr/include/math.h -o prog -l SDL -l SDL_image -l SDL_ttf -l SDL_mixer -g -l SDL_gfx  
main.o:main.c
	gcc -c main.c -g
game.o:game.c
	gcc -c game.c -g
player1.o:player1.c
	gcc -c player1.c -g
bg.o:bg.c
	gcc -c bg.c -g
camera.o:camera.c
	gcc -c camera.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
score.o:score.c
	gcc -c score.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
son.o:son.c
	gcc -c son.c -g
AI.o:AI.c
	gcc -c AI.c -g 
