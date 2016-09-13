/* ========================================================================== */
/* projet : tableau de caracteres                                             */
/* fichier : chaiTableau.c                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char chaine[81]; /* Tableau destine a recevoir une chaine de 80 caracteres */
    /* plus le zero final                                     */


    printf("Saisir une chaine de caracteres : ");
    gets(chaine);

    printf("\n\nChaine saisie --> ");
    puts(chaine);

    return 0;
}
