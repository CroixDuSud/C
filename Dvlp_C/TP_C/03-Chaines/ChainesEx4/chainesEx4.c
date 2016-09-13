/* ========================================================================== */
/* projet : TP_Chaine       exercice 4                                        */
/* fichier : chaineEx4.c                                                      */
/* -------------------------------------------------------------------------- */
/* Indices des Premier et dernier caracteres non blanc d'une chaine           */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char ligne[81];
    int indicePremier;
    int indiceDernier;
    int longueurLigne;

    /* -------------------------------------------------------------------------- */
    /* Saisie de ligne                                                            */
    /* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);
    longueurLigne = strlen(ligne);

    /* -------------------------------------------------------------------------- */
    /* Chaine vide                                                                */
    /* -------------------------------------------------------------------------- */
    if (longueurLigne == 0)
    {
        printf("La chaine saisie est vide !\n");
    }
    else
    {

        /* -------------------------------------------------------------------------- */
        /* Recherche du premier caractere non blanc                                   */
        /* -------------------------------------------------------------------------- */
        indicePremier = 0;

        while ((ligne[indicePremier] == ' ') && (indicePremier < longueurLigne))
        {
            indicePremier++;
        }

        /* -------------------------------------------------------------------------- */
        /* La ligne est entierement a blanc                                           */
        /* -------------------------------------------------------------------------- */
        if (indicePremier == longueurLigne)
        {
            printf("La chaine saisie est entierement a blanc !\n");
        }
        else
        {

            /* -------------------------------------------------------------------------- */
            /* Recherche du dernier caractere non blanc                                   */
            /* -------------------------------------------------------------------------- */
            indiceDernier = longueurLigne - 1;

            while (ligne[indiceDernier] == ' ')
            {
                indiceDernier--;
            }

            printf("Premier caractere : %d\n", indicePremier);
            printf("Dernier caractere : %d\n", indiceDernier);
        }
    }

    return 0;
}
