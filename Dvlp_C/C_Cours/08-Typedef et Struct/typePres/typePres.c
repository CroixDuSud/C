/* ========================================================================== */
/* projet : Structures de donnees : utilisation de typedef struct             */
/* fichier : typePres.c                                                       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

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
   EMPLOYE employe;             /* Declaration d'une variable de type EMPLOYE */

                                /* Remarque : l'utilisation de typedef struct */
                                /* permet d'utiliser EMPLOYE comme un nouveau */
                                /* type de donnees.                           */


/* -------------------------------------------------------------------------- */
/* Initialisation des differentes proprietes de la variable employe           */
/* -------------------------------------------------------------------------- */
   employe.numero = 10;
   strcpy(employe.nom, "Dejour");
   strcpy(employe.prenom, "Adan");
   employe.n_agence = 1;

/* -------------------------------------------------------------------------- */
/* Affichage des differentes proprietes de la variable employe                */
/* -------------------------------------------------------------------------- */
   printf("Taille structure : %d\n\n", sizeof(EMPLOYE));

   printf("Employe : %3d  %s %s %3d\n\n", employe.numero,
                                      employe.prenom,
                                      employe.nom,
									  employe.n_agence);

   printf("Adresse numero : %p\n", &employe.numero);
   printf("Adresse nom :    %p\n", employe.nom);
   printf("Adresse prenom : %p\n", employe.prenom);
   printf("Adresse agence : %p\n", &employe.n_agence);

   return 0;
}
