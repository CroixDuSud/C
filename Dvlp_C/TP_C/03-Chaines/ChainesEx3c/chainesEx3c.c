/* ========================================================================== */
/* projet : TP_Chaine       exercice 3 (version c)                            */
/* fichier : chaineEx3c.c                                                     */
/* -------------------------------------------------------------------------- */
/* Inverser une chaine saisie au clavier                                      */
/* Utilisation de la fonction strrev()                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char ligne[81];

    /* -------------------------------------------------------------------------- */
    /* Saisie de ligne1                                                           */
    /* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);

    /* -------------------------------------------------------------------------- */
    /* appel de la fonction strrev()                                              */
    /* -------------------------------------------------------------------------- */

    strrev(ligne);

    printf("\n\n%s", ligne);

    return 0;
}
