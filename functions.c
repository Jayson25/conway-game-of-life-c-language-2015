#include <time.h>
#include "header.h"

/*timer that will allow the pause of 1 sec between two generations*/
void regulator(void)
{
    /*init time variables using the library time.h*/
    time_t start, end;
    /*double is a float bigger than a normal float in order to be more precise in  the time*/
    double run_time;
    /*initiate the timer*/
    time(&start);

    /*conditional loop*/
    do {
        /*initiate "the variation to the first timer" timer*/
        time(&end);
        /*calculates the variation between the first and second timer and give the result in second*/
        run_time = difftime(end, start);

        }while (run_time<1);
}
