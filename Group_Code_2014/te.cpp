/* time example */
#include <ctime>       /* time_t, struct tm, difftime, time, mktime */
#include <cstdio>
#include <iostream>

int main ()
{
    time_t timer = time(NULL), timer2 = time(NULL);
    double seconds;

    //time(&timer);  /* get current time; same as: timer = time(NULL)  */

    //seconds = difftime(timer, mktime(&y2k));

    // printf ("%.f seconds since January 1, 2000 in the current timezone", seconds);

    long long t = 0;
    time(&timer);
    for (long long i = 0; i < (long long)9000 * 1000 * 1000; ++i) {
        t++;
    }
    time(&timer2);
    // seconds = difftime(timer, timer2);
    //std::cout << seconds << std::endl;
    std::cout << timer2 - timer << std::endl;

    return 0;
}