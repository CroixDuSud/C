/* ========================================================================== */
/* projet : BIBLIOTHEQUE DE FONCTIONS DE GESTION DES FRACTIONS                */
/* fichier : testFractions.c                                                  */
/* -------------------------------------------------------------------------- */
/* programme de test de la bibliothèque biblioFractions                       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

#include "R:\C\utilitaires\entetes\fractions.h"
/*
||=== Build: Debug in testBiblioFractions (compiler: GNU GCC Compiler) ===|
fatal error: fractions.h: No such file or directory|
||=== Build failed: 1 error(s), 0 warning(s) (0 minute(s), 0 second(s)) ===|

ajouter le chemin de recherche dans code::blocks :
        click droit sur projet -> Build options... -> onglet : Search directories
        -> bouton : Add -> renseigner le chemin
        exemple : ..\BiblioFractions
*/

/*
||=== Build: Debug in testBiblioFractions (compiler: GNU GCC Compiler) ===|
obj\Debug\testFractions.o||In function `main':|
undefined reference to `saisie'|
undefined reference to `saisie'|
undefined reference to `somme'|
undefined reference to `affiche'|
undefined reference to `affiche'|
undefined reference to `affiche'|
||error: ld returned 1 exit status|
||=== Build failed: 7 error(s), 0 warning(s) (0 minute(s), 0 second(s)) ===|

renseigner le linker en lui donnant l'endroit et le nom du résultat de la compilation
du projet BliclioFractions -> biblioFractions.o
        click droit sur projet -> Build options... -> onglet : Linker settings
        -> copier le chemin+nomFichier dans Other linker options
        exemple : ..\BiblioFractions\obj\Debug\fractions.o
*/

/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main()
{
    int r;
    FRACTION f1, f2, f3;

    f2.Num = 5;
    f2.Den = 2;

    /* -------------------------------------------------------------------------- */
    /* Saisie de la fraction f1                                                   */
    /* -------------------------------------------------------------------------- */
    printf("Saisie de la fraction f1\n");
    r = saisie(&f1);

    while(r < 0)
    {
        printf("Denominateur de la fraction f1 nul !\n\n");
        r = saisie(&f1);
    }

    /* -------------------------------------------------------------------------- */
    /* Calcul de la somme (simplifiee)                                            */
    /* -------------------------------------------------------------------------- */
    f3 = somme(f1, f2);

    /* -------------------------------------------------------------------------- */
    /* Affichage de la somme                                                      */
    /* -------------------------------------------------------------------------- */
    printf("\nSomme de ");
    affiche(f1);
    printf(" et de ");
    affiche(f2);
    printf(" = ");
    affiche(f3);
    printf("\n");

    return 0;
}
