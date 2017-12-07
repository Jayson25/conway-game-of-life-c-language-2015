#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*creation of a structure*/
struct world
{
    int height;
    int width;
};

struct cell
{
    char birth;
    char alive;
    char death;
};

/*list of prototypes of functions*/
void init(char carte[12][12], int height, int width);
void newGeneration(char carte[12][12], char next[12][12], char alive, char born, char dead, int loop, int height, int width);
void displayWorld(char carte[12][12],int height, int width, SDL_Renderer* render, SDL_Texture* pict_1, SDL_Texture* pict_2, SDL_Texture* pict_3, SDL_Texture* background);
void destroyInit(SDL_Window* screen, SDL_Renderer* render, SDL_Texture* pict_1, SDL_Texture* pict_2, SDL_Texture* pict_3);
void regulator(void);

#endif // HEADER_H_INCLUDED
