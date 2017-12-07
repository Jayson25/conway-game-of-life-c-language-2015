#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "header.h"

void init(char carte[12][12], int height, int width)
{
    /*seed(integer value to be used as seed in random) to initiate random and prevent when you restart the program to have the same random as before.*/
    srand(time(NULL));
    int line, column;
    for(line=0; line<height+2; line++)
    {
        for(column=0; column<width+2; column++)
        {
            /*randomized a character between - or 0 repeats the process each time line or column changes*/
            const char caract = "-0"[rand()%2];
            /*apply the random character in the array for coordinates line, column*/
            carte[line][column] = caract;

            /*these characters is used for our invisible borders in orders to be neutral and make the newGeneration function work*/
            if ((line==0)||(line==height+1))
                carte[line][column] = '-';

            if ((column==0)||(column==width+1))
                carte[line][column] = '-';
        }
    }
}

/*same as init but here we do not append values in mappage, we display them with the help of textures*/
void displayWorld(char carte[12][12], int height, int width, SDL_Renderer* render, SDL_Texture* pict_1, SDL_Texture* pict_2, SDL_Texture* pict_3, SDL_Texture* background)
{
     int i,j;
     /*Copy the texture in the graphics card*/
     SDL_RenderCopy(render, background, NULL, NULL);
     for (i=1; i<height+1; i++)
        {
            for(j=1; j<width+1; j++)
            {
                int x = ((65)* i)+200;
                int y = ((65)* j)-20;
                /*x: coordinate of the texture in axis x; y: coordinate of the texture in axis y*/
                SDL_Rect dstrect = {x,y,72,72};
                /*here we transform char values into textures of the window that we will blit*/
                if (carte[i][j] == '0')
                    SDL_RenderCopy(render, pict_1, NULL, &dstrect);

                else if (carte[i][j] == '+')
                    SDL_RenderCopy(render, pict_2, NULL, &dstrect);

                else if (carte[i][j] == '-')
                    SDL_RenderCopy(render, pict_3, NULL, &dstrect);
            }
        }
        /*the graphics carte will display the render that contains all the textures we want to display*/
        SDL_RenderPresent(render);
}

/*free memory from SDL2 processes*/
void destroyInit(SDL_Window* screen, SDL_Renderer* render, SDL_Texture* pict_1, SDL_Texture* pict_2, SDL_Texture* pict_3)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(pict_1);
    SDL_DestroyTexture(pict_2);
    SDL_DestroyTexture(pict_3);
    SDL_DestroyWindow(screen);
    SDL_Quit();
}
