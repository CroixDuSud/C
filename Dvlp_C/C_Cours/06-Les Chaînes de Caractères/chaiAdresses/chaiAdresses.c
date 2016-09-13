/* ========================================================================== */
/* projet : chaines de caracteres                                              */
/* fichier : chaiAdresses.c                                                     */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char* adresse;

    adresse = "Vieux bouc...";

    printf("%c   %3d   %p\n", *adresse, *adresse, adresse);
    do
    {
        adresse++;
        printf("%c   %3d   %p\n", *adresse, *adresse, adresse);
    }
    while(*adresse);

    return 0;
}
