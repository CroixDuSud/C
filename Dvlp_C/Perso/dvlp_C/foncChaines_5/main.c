#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype

void inclureChaine(char *chaine1, char *chaine2);


int main()
{
    char chaine1[80];
    char chaine2[20];

    //Saisie d'une CHAINE

    printf("Saisissez une phrase (limite 80 caracteres) :\n");

    fgets(chaine1, 80, stdin);

    //SOUS-CHAINE

    printf("Sous chaine (limite 20 caracteres) :\n\n");

    fgets(chaine2, 20, stdin);

    inclureChaine(chaine1, chaine2);

    return 0;
}

// code source des fonctions

void inclureChaine(char *chaine1, char *chaine2)
{
    int i = 0;
    int j = 0;
    int position;
    int lgr;
    int lgr2;
    char tmp[81];

    lgr = strlen(chaine1);
    lgr2 = strlen(chaine2);

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
        tmp [j] = chaine1 [i];
        i++;
        j++;
    } while (chaine1 [i] != '\0');
    tmp [j] = '\0';


    //COPIE de la sous-chaine dans la chaine

    strcpy(&(chaine1 [position]), chaine2);

    //printf("%s", ch);

    //COPIE de la sauvegarde dans la chaine


    strcpy(&(chaine1 [position + lgr2 - 1]), tmp);

    printf("\n");
    printf("%s", chaine1);
}
