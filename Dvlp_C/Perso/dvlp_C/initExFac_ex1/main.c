/* getch in c example */
#include<stdio.h>
#include<conio.h>
#include <string.h>

main()
{
    char motDePasse [7] = {'f', 'u', 'm', 'i', 'e', 'r', '\0'};
    char mdp [7];
    int i = 0;
    int vrai = 0;

    /* //Recherche du code ASCII de la touche Entrée
    ch = _getch();
    printf("%d", ch);
    printf("%c", ch);
    */

    // %d entier, %p, adresse hexa, %c caractère, %f float, %lf double, %s chaîne de caractère


    // SAISIE MOT DE PASSE


    do
    {
        mdp [i]= _getch();
        _putch(120); // AFFICHAGE DES "X"
        i++;

    }while (i < 6);


    // VERIFICATION MOT DE PASSE


    for(i = 0; i < 6; i++)
    {
        if (mdp [i] == motDePasse [i])
        {
            vrai++;
        }
        else
        {
            vrai = 0;
        }
    }

    if (vrai == 6)
    {
        printf("\n\n");
        printf("BRAVO !\n");
    }
        else
        {
            printf("erreur de mot de passe\n");
        }

    return 0;
}
