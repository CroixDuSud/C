/* ========================================================================== */
/* projet : Tableau à une dimension (presentation)                            */
/* fichier : tablPresentation.c                                               */
/*----------------------------------------------------------------------------*/
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    int tab[3];

    tab[0] = 5;
    tab[1] = 15;
    tab[2] = 10;

    printf("tab[1] = %d\n\n", tab[1]);

    printf("tab[0] = %d\n\n", tab[0]);

    printf("tab[-1] = %d\n", tab[-1]);
    tab[-1] = 17;
    printf("tab[-1] = %d\n\n", tab[-1]);

    printf("tab = %d %p\n\n", tab, tab);

    return 0;
}
