/* ========================================================================== */
/* projet : TP_Chaine       exercice 1 (version b)                            */
/* fichier : chaineEx1b.c                                                     */
/* -------------------------------------------------------------------------- */
/* Compter le nombre de 'e' contenus dans une chaine saisie au clavier        */
/* (maximum 80 caracteres)                                                    */
/* -------------------------------------------------------------------------- */
/* Version utilisant la fonction strchr                                       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char ligne[81];       /* Ligne saisie au clavier                           */
    char* debut;          /* Adresse du debut de la zone de 'ligne' a examiner */
    int compteur;         /* nombre de 'e' trouves                             */

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    compteur = 0;
    debut = strchr(ligne, 'e');          /* Positionnement sur le premier 'e'  */

    while (debut != 0)
    {
        compteur++;
        debut++;                          /* Positionnement APRES le 'e' trouve */
        debut = strchr(debut, 'e');
    }

    printf("\n\nNombre de 'e' : %d\n", compteur);

    return 0;
}
