/* ========================================================================== */
/* projet : TP_Initiation                                                     */
/* fichier : initEx1.c                                                        */
/* -------------------------------------------------------------------------- */
/* Afficher la liste des 10 premiers nombres avec leur racine carree et le    */
/* cumul des racines carrees                                                  */
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
    cumul = 0;

    // début du code
    printf("\nNombre       Racine        Cumul\n\n");

    for (i = 1; i <= 10; i++)
    {
        racine = sqrt(i);
        cumul += racine;    // équivalent à cumul = cumul + racine;
        printf("  %2d        %7.3f      %7.3f\n", i, racine, cumul);
    }

    return 0;
}
