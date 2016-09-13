/* ========================================================================== */
/* projet : Pointeurs sur des structures                                      */
/* fichier : typePointeurs.c                                                  */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/* -------------------------------------------------------------------------- */
/* La declaration suivante permet de definir un nouveau type de donnees.      */
/* Elle ne reserve pas d'espace en memoire.                                   */
/* -------------------------------------------------------------------------- */

typedef struct
{
    int numero;                     /* Numero de l'employe                     */
    char nom[51];                   /* Nom de l'employe                        */
    char prenom[41];                /* Prenom de l'employe                     */
    int n_agence;                   /* Numero d'agence de l'employe            */
} EMPLOYE;


int main()
{
    EMPLOYE* p_employe;          /* Pointeur sur un EMPLOYE                    */

    /* -------------------------------------------------------------------------- */
    /* Allocation d'une variable de type EMPLOYE "pointee" par p_employe          */
    /* -------------------------------------------------------------------------- */
    p_employe = (EMPLOYE*) calloc(1, sizeof(EMPLOYE));

    /* -------------------------------------------------------------------------- */
    /* Initialisation des differentes proprietes de la variable employe           */
    /* Utilisation de l'operateur ->                                              */
    /* -------------------------------------------------------------------------- */
    (*p_employe).numero = 10;
    strcpy((*p_employe).nom, "Dejour");
    strcpy(p_employe->prenom, "Adan");
    p_employe->n_agence = 1;

    /* -------------------------------------------------------------------------- */
    /* Affichage des differentes proprietes de la variable employe                */
    /* -------------------------------------------------------------------------- */
    printf("Employe : %3d  %s %s\n\n", p_employe->numero,
           p_employe->prenom,
           p_employe->nom);

    return 0;
}
