/* ========================================================================== */
/* projet : chaines de caracteres - fonctions  - Exercice 3                   */
/* fichier : foncChaines3.c                                                   */
/* -------------------------------------------------------------------------- */
/* Inverser une chaine saisie au clavier                                      */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

char* inverse(char* ligne);


int main()
{
    char ligne[81];

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    inverse(ligne);
    printf("\n");
    puts(ligne);

    printf("\n");
    puts(inverse(ligne));

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction inverse :                                                         */
/* -------------------------------------------------------------------------- */
/* Parametre : ligne  : chaine a inverser                                     */
/* -------------------------------------------------------------------------- */

char* inverse(char* ligne)
{
    int i1;            /* Poste de gauche a inverser                           */
    int i2;            /* Poste de droite a inverser                           */
    char permut;       /* Caractere de permutation                             */

    i1 = 0;
    i2 = strlen(ligne) - 1;

    while (i1 < i2)
    {
        permut = ligne[i1];
        ligne[i1] = ligne[i2];
        ligne[i2] = permut;
        i1++;
        i2--;
    }

    return ligne;
}
