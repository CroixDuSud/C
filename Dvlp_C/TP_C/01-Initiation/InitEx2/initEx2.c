/* ========================================================================== */
/* projet : TP_Initiation                                                     */
/* fichier : initEx2.c                                                        */
/* -------------------------------------------------------------------------- */
/* Afficher la liste des premiers nombres avec leur racine carree, le cumul   */
/* des racines carrees, jusqu'a ce que le cumul soit > 30                     */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    // déclaration des variables
    int i;
    double racine, cumul;

    // initialisation des variables
    i = 1;
    cumul = 0;

    // début du code
    printf("\nNombre       Racine        Cumul\n\n");

    do
    {
        racine = sqrt(i);
        cumul += racine;
        printf("  %2d        %7.3f      %7.3f\n", i, racine, cumul);
        i++;
    }
    while (cumul < 30);

    return 0;
}
