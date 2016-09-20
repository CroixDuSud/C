#include <stdio.h>
#include <stdlib.h>

void fonctionEx1()
{
    double nbr = 0;
    double sqrt (double);
    double racine;
    double sum = 0;

    for (nbr = 0 ; nbr < 10 ; nbr++)
    {
        racine = sqrt (nbr);
        printf("Racine de %lf : %lf\n", nbr, racine);

        sum = sum + racine;
    }

    printf("Cumul des racines carrées : %lf\n", sum);

}

