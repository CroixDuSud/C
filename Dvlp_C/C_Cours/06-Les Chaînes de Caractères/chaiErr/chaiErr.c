/* ========================================================================== */
/* projet : saisie d'une chaine de caracteres au clavier                                              */
/* fichier : chaiErr.c                                                     */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */


#include <stdio.h>
#include <conio.h>

int main()
{
    char* adresse;

    printf("Saisir une chaine de caracteres : ");
    gets(adresse);

    printf("\n\nChaine saisie --> ");
    puts(adresse);

    return 0;
}
