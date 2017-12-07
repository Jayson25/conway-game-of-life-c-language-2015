/*this program is made by Jayson Galante a student of yours*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <time.h>
#include "header.h"

int main(int argc, char *argv[])
{
    /*loop: actual generation; repeat: loop state (0 or 1); count: tester of the number of requested of loops; request: input of the limit of generations generated; cont: tester of do you want to continue*/
    int loop=0, repeat=0, count=0, request=1, choice=0, cont;
    /*mappage: array of evolution; previous: array of last generation; answer: input of the answer of do you want to continue*/
    char mappage[12][12], previous[12][12], *answer[5];

    /*init variable from structure world*/
    struct world size;
    size.height = 10; size.width = 10;

    /*init variable from structure cell*/
    struct cell state;
    state.alive= '+'; state.birth= '0'; state.death= '-';

    /* SDL event tester (used in while loop)*/
    SDL_Event event;
    /*initiate SDL video, music, etc... initiate PNG loader*/
    SDL_Init(SDL_INIT_EVERYTHING); IMG_Init(IMG_INIT_PNG);

    /*creates values in our array*/
    init(mappage, size.height, size.width);
    /*copy values of mappage in previous memcpy is used for all types of variable/arrays(int, char,...)*/
    memcpy(previous, mappage, (size.height + 2)*(size.width + 2));

    /*initiates a window with title, position of the window on the screen, size of the window and special commands(such as resizable)*/
    SDL_Window* window = SDL_CreateWindow("Conway's game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720,NULL);

    /*create renderer that will be copied on the graphics card surfaces and sprites */
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    /*load images*/
    SDL_Surface* fond = IMG_Load("fond.png");
    SDL_Surface* baby  = IMG_Load("baby.png");
    SDL_Surface* adult  = IMG_Load("adult.png");
    SDL_Surface* dead  = IMG_Load("dead.png");

    /*transforms images into textures as if it is part of the window*/
    SDL_Texture* stage_1 = SDL_CreateTextureFromSurface(render, baby);
    SDL_Texture* stage_2 = SDL_CreateTextureFromSurface(render, adult);
    SDL_Texture* stage_3 = SDL_CreateTextureFromSurface(render, dead);
    SDL_Texture* background = SDL_CreateTextureFromSurface(render, fond);

    /*initiate music codec with 22000Hz frequency, AUDIO_S16SYS music codec, 1 channel and 800 chunk size (size of the audio file max)*/
    Mix_OpenAudio(22000, AUDIO_S16SYS, 1, 800);
    /*load music mp3 file as background music and not sound*/
    Mix_Music *sound = Mix_LoadMUS("music.mp3");
    /*play the music in undefined number of loops*/
    Mix_PlayMusic(sound, -1);

    printf("\n\n\n\t\t\t WELCOME TO CONWAY'S GAME OF LIFE\n\t\t\t     Created by Jayson Galante\n\n");
    /* ! means different*/
    while(!repeat)
    {
        /*waits for an event*/
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
              repeat = 1;
              break;
        }
        loop ++;count++;
        /*display the world in SDL2*/
        displayWorld(mappage, size.height, size.width, render, stage_1, stage_2, stage_3, background);

        printf("\tGENERATION %d\n\n\n", loop);
        if (count==request)
        {
            /*reinitialize testers*/
            count=0; cont = 0; choice=0;

            printf("\tDo you want to continue?(yes/no)\n");
            while(!choice)
            {
                printf("\tCommand: "); scanf("%s",answer);

                /*strcmp: test a string and 0 means no difference between the two strings we want to test*/
                if (strcmp(answer, "yes")==0) {choice = 1; cont=1;}

                else if (strcmp(answer, "ye")==0) {choice = 1; cont=1;}

                else if (strcmp(answer, "y")==0) {choice = 1; cont=1;}

                else if (strcmp(answer, "no")==0) {choice = 1;cont=2;}

                else if (strcmp(answer, "n")==0) {choice = 1; cont=2;}

                else printf("\tError: command invalid, please try again.\n");
            }
            if (cont==1)
            {
                printf("\n\tHow many generations do you want to see: ");
                scanf("%d", &request); printf("\n");
            }
             else if (cont==2) {printf("\n\t\t\tGoodbye, see you soon!"); repeat=1;}
        }
        /*this function allows a pause of 1 secs between two generations*/
        regulator();

        /*transition to the next generation*/
        newGeneration(previous, mappage, state.alive, state.birth, state.death, loop, size.height, size.width);

        memcpy(previous, mappage, 12*12);
    }
    /*free memory from SDL2 by releasing textures, render, window, and images*/
    destroyInit(window, render, stage_1, stage_2, stage_3);
    /*free memory from audio file*/
    Mix_FreeMusic(sound);
}
