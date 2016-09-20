#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch [80];
    char ch_traite [80];
    int i = 0;
    int j = 0;
    //int cpt = 0;
    unsigned int lgr;

/*
    do
    {
        //ch = getchar();
        fgets(ch, 81, stdin);
    } while (ch[i] != 'e' && ch[i] == '\r');

    printf("%s", ch);

*/




    //Saisie d'une chaine

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(ch, 80, stdin);
    lgr = strlen(ch);

    printf("Vous avez tape :\n\n%s\n\n", ch);

    //TEST printf("%c", ch[5]);

    //Supprimer les 'e'

    //printf("%d\n",lgr);
    while (ch [i] != '\0')
    {
        if (ch[i] != 'e')
        {
            ch_traite [j] = ch [i];
            j++;
        }
        i++;
    }
    ch_traite [j-1] = '\0';

    //printf("%d\n",lgr - j);
    //for (i = 0, i < 10, i++)
    printf("%s", ch_traite);



    return 0;
}
