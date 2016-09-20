#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


// code source des fonctions


void comptage(char *chaine, char lettre)
{
    //int i;
    int cpt = 0;

    do
    {
        if (*chaine == lettre)
        {
            cpt++;
        }
        chaine++;

    } while (*chaine != '\0');

    printf("\nIl y a %d 'e' dans votre chaine de caratere.\n", cpt);
}
