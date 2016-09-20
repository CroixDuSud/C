#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int tableau()
{
    int tableau [10];
    int i = 0;
    int limite = 10;

    // INITIALISATION DU TABLEAU


    srand(time(NULL));
    for (i = 0; i = 9; i++)
    {
        tableau [i] = rand() % limite;
        printf("%d\n", tableau [i]);
    }

    return 0;
}
