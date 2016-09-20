#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main()
{
    char chaine[81];

    printf("Entrez une chaine de caratere : ");
    gets(chaine);

    supprimerE(chaine);

    return 0;
}


