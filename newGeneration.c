#include "header.h"

/*this function transit from a generation to another*/
void newGeneration(char carte[12][12], char next[12][12], char alive, char born, char dead, int loop, int height, int width)
{
    int i, j;
    /*we start the evolution starting to the second generation*/
    if (loop >= 1)
        {
            /*we remove the invisible borders from the process. Invisible borders are used to avoid errors when the process are in the real borders*/

            /*      ([i-1][j-1])([i][j-1])([i+1][j-1])
                    ([i-1][j])   ([i][j])  ([i+1][j])        Here is the map of our process for each i, j coordinates.
                    ([i-1][j+1])([i][j+1]) ([i+1][j+1])*/

            for (i=1; i<height+1; i++)
            {
                for(j=1; j<width+1; j++)
                {
                        /*counter of neighbors (max: 8) initiated for one i,j coordinate*/
                        int neighbor = 0;
                        if ((carte[i-1][j-1]==alive)||(carte[i-1][j-1]==born))
                            neighbor++;

                        if ((carte[i][j-1]==alive)||(carte[i][j-1]==born))
                            neighbor++;

                        if ((carte[i+1][j-1]==alive)||(carte[i+1][j-1]==born))
                            neighbor++;

                        if ((carte[i-1][j]==alive)||(carte[i-1][j]==born))
                            neighbor++;

                        if ((carte[i+1][j]==alive)||(carte[i+1][j]==born))
                            neighbor++;

                        if ((carte[i-1][j+1]==alive)||(carte[i-1][j+1]==born))
                            neighbor++;

                        if ((carte[i][j+1]==alive)||(carte[i][j+1]==born))
                            neighbor++;

                        if ((carte[i+1][j+1]==alive)||(carte[i+1][j+1]==born))
                            neighbor++;

                        /*after the process, we count the total of neighbor and judges the state of the coordinate*/
                        if ((neighbor == 2)&&((carte[i][j]==alive)||(carte[i][j]==born)))
                            next[i][j]=alive;

                        else if ((neighbor==3)&&(carte[i][j]==dead))
                            next[i][j]=born;

                        else if ((neighbor==3)&&((carte[i][j]==alive)||(carte[i][j]==born)))
                            next[i][j]=alive;

                        else next[i][j]=dead;
                }
            }
        }
}
