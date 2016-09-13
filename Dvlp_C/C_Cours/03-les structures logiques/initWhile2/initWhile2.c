/* ========================================================================== */
/* projet : Utilisation de la structure répétitive WHILE                      */
/* fichier : initWhile2.c                                                     */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int indx;

    indx = 1;

    while (indx <= 10)
    {
        printf("Etape %2d\n", indx);
        indx++;
    }

    return 0;
}
