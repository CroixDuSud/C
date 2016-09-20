#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nbr = 0.0;
    double sqrt (double);
    double racine;
    double sum = 0;

    do
    {
        racine = sqrt (nbr);
        printf("Racine de %lf : %lf\n", nbr, racine);
        nbr++;
        sum = sum + racine;
    } while (sum < 30);

    printf("Cumul des racines carrées : %lf\n", sum);

    return 0;
}
