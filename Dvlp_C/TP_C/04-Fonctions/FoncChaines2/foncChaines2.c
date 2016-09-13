/* ========================================================================== */
/* projet : chaines de caracteres - fonctions  - Exercice 2                   */
/* fichier : foncChaines2.c                                                   */
/* -------------------------------------------------------------------------- */
/* Supprimer tous les caracteres 'e' contenus dans une chaine saisie au       */
/* clavier (maximum 80 caracteres)                                            */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

void enleveLettres(char* ligne, char lettre);


int main()
{
    char ligne[81];
    char lettre;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    lettre = 'e';

    enleveLettres(ligne, lettre);

    printf("\n\n");
    puts(ligne);

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction enleveLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine a traiter                                     */
/*              lettre : lettre a enlever                                     */
/* -------------------------------------------------------------------------- */

void enleveLettres(char* ligne, char lettre)
{
    int i;
    int j;

    i = 0;             /* Numero du caractere examine                          */
    j = 0;             /* Numero du poste ou on le recopie                     */

    while (ligne[i] != 0)
    {
        if (ligne[i] != lettre)
        {
            ligne[j] = ligne[i];
            j++;
        }
        i++;
    }
    ligne[j] = 0;
}
