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


int afficherTab()
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", tableau [i]);
    }
    return 0;
}

int askNb()
{
    do
    {
        printf("Entrez un chiffre entre 0 et 10 :\n");
        scanf("%d", &chiffre);
    } while(chiffre > 10);
}

int tri()
{
    int i = 0;
    int j = 0;


    for (i = 0; i < 10;  i++)
    {
        for (j = i; j < 10; j++)
        {
           if (tableau [i] > tableau [j])
            {
                tmp = tableau [i];
                tableau [i] = tableau [j];
                tableau [j] = tmp;
            }
        }
    }
}


int verif()
{
    int i = 0;

    while (tableau [i] != chiffre && i < 10)
    {
        i++;
    }

    if (i == 10)
    {
        printf("Votre chiffre n'est pas present dans le tableau.\n");
    }
    else
    {
        printf("Votre chiffre est present dans le tableau.\n");
    }
}
