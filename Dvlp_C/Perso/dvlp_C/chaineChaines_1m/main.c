#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"



// programme principal (main)

int main()
{
    char chaine[81];
    char lettre;

    printf("Entrez une chaine de caractere : ");
    gets(chaine);

    printf("Entrez la lettre a compter : ");
    scanf("%c", &lettre);

    comptage(chaine, lettre);

    return 0;
}


