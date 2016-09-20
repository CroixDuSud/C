#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype

void inverser(char *chaine);

// Programme principal (main)

int main()
{
    char chaine [81];

    printf("Entrez une chaine de caratere : ");
    gets(chaine);

    inverser(chaine);

    return 0;
}

// code source de la fonction

void inverser(char *chaine)
{
    int j;
    int i = 0;
    char tmp1;
    char tmp2;
    int lgr;

    lgr = strlen(chaine);

    j = (lgr - 1);

    while ( i < j)
    {
    	tmp1 = chaine[i];
    	tmp2 = chaine[j];
    	chaine[i] = tmp2;
    	chaine[j] = tmp1;
    	i++;
    	j--;
    }

    printf("%s", chaine);
}
