/* ========================================================================== */
/* projet : TP_Chaine       exercice 2 (version b)                            */
/* fichier : chaineEx2b.c                                                     */
/* -------------------------------------------------------------------------- */
/* Supprimer tous les caracteres 'e' contenus dans une chaine saisie au       */
/* clavier (maximum 80 caracteres)                                            */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char ligne[81];
    int i;

    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);

    i = 0;

    while (ligne[i] != 0)
    {
        if (ligne[i] == 'e')
        {
            strcpy(ligne + i, ligne + i + 1);
        }
        else
        {
            i++;
        }
    }

    printf("\n\n%s", ligne);

    return 0;
}
