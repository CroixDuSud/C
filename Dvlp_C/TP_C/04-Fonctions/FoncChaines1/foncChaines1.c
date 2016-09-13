/* ========================================================================== */
/* projet : chaines de caracteres - fonctions  - Exercice 1                   */
/* fichier : foncChaines1.c                                                   */
/* -------------------------------------------------------------------------- */
/* Compter le nombre de 'e' contenus dans une chaine saisie au clavier        */
/* (maximum 80 caracteres)                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int compteLettres(char* ligne, char lettre);

int main()
{
    char ligne[81];
    char lettre;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    lettre = 'o';

    printf("\nNombre de '%c' : %d.\n", lettre, compteLettres(ligne, lettre));

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction compteLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine examinee                                      */
/*              lettre : lettre cherchee                                      */
/* -------------------------------------------------------------------------- */

int compteLettres(char* ligne, char lettre)
{
    int i;               /* Indice de parcours de ligne                        */
    int compteur;        /* Nombre de 'lettre' deja trouves                    */

    i = 0;
    compteur = 0;
    while (ligne[i] != 0)
    {
        if (ligne[i] == lettre) compteur++;
        i++;
    }

    return compteur;
}
