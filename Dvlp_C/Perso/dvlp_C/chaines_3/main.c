#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch [80];
    int i = 0;
    int j;
    int tmp1;
    int tmp2;
    unsigned int lgr;

    //Saisie d'une chaine

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(ch, 80, stdin);
    lgr = strlen(ch); // ! ATTENTION ! lgr prend en compte le caractère '\O'

    printf("Vous avez tape :\n\n%s\n\n", ch);

    //Inversion de la chaîne

    j = (lgr - 1);

    //printf("%d", lgr);
    //printf("%c", ch [lgr - 2]);


    while ( i < j)
    {
    	tmp1 = ch [i];
    	tmp2 = ch [j];
    	ch [i] = tmp2;
    	ch [j] = tmp1;
    	i++;
    	j--;
    }

    printf("%s", ch);

    return 0;
}
