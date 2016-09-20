#include <stdio.h>
#include <stdlib.h>


// prototypes

void comptage(char *chaine, char lettre);

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

