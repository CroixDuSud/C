#include "foncChaines_5.h"

int main()
{
    char chaine1[80];
    char chaine2[20];

    //Saisie d'une CHAINE

    printf("Saisissez une phrase (limite 80 caracteres) :\n\n");

    fgets(chaine1, 80, stdin);

    //SOUS-CHAINE

    printf("Sous chaine (limite 20 caracteres) :\n\n");

    fgets(chaine2, 20, stdin);

    inclureChaine(chaine1, chaine2);

    return 0;
}
