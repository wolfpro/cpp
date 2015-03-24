#include <stdio.h>
int main()
{
    int a = 426;
    for (; ; a++)
        if (((a % 2 == 1) && (a % 3 == 2) && (a % 7 == 5) && (a % 11 == 7)))
            printf("%d\n",   a);

    return 0;
}