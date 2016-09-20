#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch [80];
    char ch2 [20];
    char ch3 [80];
    int i = 0;
    int j = 0;
    int position;
    int lgr; //longueur de la chaine 1
    int lgr2; //longueur de la chaine 2

    //Saisie d'une chaine

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(ch, 80, stdin);


    printf("\nVous avez tape :\n\n%s\n\n", ch);

    //SOUS-CHAINE

    printf("Sous chaine (limite 20 caracteres) :\n\n");

    fgets(ch2, 20, stdin);

    lgr = strlen (ch);
    lgr2 = strlen (ch2);// ! ATTENTION ! lgr prend en compte le caractère '\O'


    //POSITION

    do
    {
        printf("\n");
        printf("Position ?\n");
        scanf("%d", &position);
    } while (position < 0 || position + lgr2 > lgr);


    //SAUVEGARDE la partie de ch qui va être masquée


    i = (position + lgr2 - 1);
    do
    {
        ch3 [j] = ch [i];
        i++;
        j++;
    } while (ch [i] != '\0');
    ch3 [j] = '\0';
    //printf("%s", ch3);



    //COPIE de la sous-chaine dans la chaine

    strcpy(&(ch [position]), ch2);

    //printf("%s", ch);

    //COPIE de la sauvegarde dans la chaine


    strcpy(&(ch [position + lgr2 - 1]), ch3);

    printf("\n");
    printf("%s", ch);

    return 0;
}
