/* ========================================================================== */
/* projet : TP_Chaine       exercice 2 (version a)                            */
/* fichier : chaineEx2a.c                                                     */
/* -------------------------------------------------------------------------- */
/* Supprimer tous les caracteres 'e' contenus dans une chaine saisie au       */
/* clavier (maximum 80 caracteres)                                            */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    char ligne[81];
    int i;
    int j;

    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);

    i = 0;             /* Numero du caractere examine                          */
    j = 0;             /* Numero du poste ou on le recopie                     */

    while (ligne[i] != 0)
    {
        if (ligne[i] != 'e')
        {
            ligne[j] = ligne[i];
            j++;
        }
        i++;
    }
    ligne[j] = 0;

    printf("\n\n%s", ligne);

    return 0;
}
