#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch [81];
    int i;
    int cpt = 0;
    unsigned int lgr;

    //Saisie d'une chaine

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(ch, 81, stdin);
    lgr = strlen(ch);

    printf("Vous avez tape :\n\n%s\n\n", ch);

    //Nombre de 'e'

    //printf("%c", ch[5]);

    for (i = 0; i < lgr; i++) // si on ne connait pas la longueur de la chaine, on fait une boucle while et on lui demande de s'arrêter lorsque ch [i] = '\0'.
    {
        if (ch[i] == 'e')
        {
            cpt++;
        }
    }
    printf("%d", cpt);

    return 0;
}
