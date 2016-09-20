#include <stdio.h>
#include <stdlib.h>

void supprimerE(char *chaine);

int main()
{
    char chaine[81];

    printf("Entrez une chaine de caratere : ");
    gets(chaine);

    supprimerE(chaine);

    return 0;
}


void supprimerE(char *chaine)
{
    char ch_traite[81];
    int i = 0;
    int j = 0;

    while (chaine[i] != '\0')
    {
        if (chaine[i] != 'e')
        {
            ch_traite[j] = chaine[i];
            j++;
        }
        i++;
    }
    ch_traite[j-1] = '\0';

    printf("\nVoici la chaine sans 'e' :\n%s", ch_traite);
}
