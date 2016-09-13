/* ========================================================================== */
/* projet : Utilisation de la structure alternative IF                        */
/* fichier : initIf1.c                                                        */
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
        printf("Croissant\n\n");
    else
        printf("Decroissant\n\n");

    return 0;
}



