/* ========================================================================== */
/* projet : Utilisation de la structure alternative IF ELSE                   */
/* fichier : initIf2.c                                                        */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int a, b;

    printf("Introduisez deux nombres : ");
    scanf("%d %d", &a, &b);

    if (a <= b)
    {
        printf("Croissant\n");
        printf("Car %d est inferieur a %d\n\n", a, b);
    }
    else
    {
        printf("Decroissant\n");
        printf("Car %d est superieur a %d\n\n", a, b);
    }

    return 0;
}



