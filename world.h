#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

typedef struct
{
    char **mappage;
    int hauteur;
    int largeur;
}world;

typedef struct
{
    char Alive_state;
    char new_born;
    char Dead_State;
}cell;

int displayWorld(char **world,int height,int largeur,int line,int column);
int newGeneration(char alive,char New,char dead);
#endif // WORLD_H_INCLUDED
