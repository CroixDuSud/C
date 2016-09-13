/* ========================================================================== */
/* projet : Utilisation de la structure alternative SWITCH                    */
/* fichier : initSwitch.c                                                        */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int n;

    printf("Entrez un nombre entier : ");
    scanf("%d", &n);

    switch(n)
    {
    case 0  :
        printf("nul\n");
        break;
    case 1  :
        printf("un\n");
        break;
    case 2  :
        printf("deux\n");
        break;
    default :
        printf("plus grand que deux\n");
    }

    printf("Au revoir...\n");

    return 0;
}
