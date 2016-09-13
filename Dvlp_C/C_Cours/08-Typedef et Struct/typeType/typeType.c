/* ========================================================================== */
/* projet : Structures contenant des structures                               */
/* fichier : typeType.c                                                       */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
   char rue[51];
   char code_postal[6];
   char ville[51];
} ADRESSE;

typedef struct
{
   int numero;                     /* Numero de l'employe                     */
   char nom[51];                   /* Nom de l'employe                        */
   char prenom[41];                   /* Preom de l'employe                        */
   ADRESSE adresse;                /* Adresse de l'employe                    */
   int n_agence;                   /* Numero d'agence de l'employe            */
} EMPLOYE;


int main()
{
   EMPLOYE employe;

/* -------------------------------------------------------------------------- */
/* Initialisation des differentes proprietes de la variable employe           */
/* -------------------------------------------------------------------------- */
   employe.numero = 10;
   strcpy(employe.nom, "Dejour");
   strcpy(employe.adresse.rue, "1, rue Marc Seguin");
   strcpy(employe.adresse.code_postal, "94000");
   strcpy(employe.adresse.ville, "CRETEIL");

/* -------------------------------------------------------------------------- */
/* Affichage des differentes proprietes de la variable employe                */
/* -------------------------------------------------------------------------- */
   printf("Taille structure ADRESSE : %d\n\n", sizeof(ADRESSE));
   printf("Taille structure EMPLOYE : %d\n\n", sizeof(EMPLOYE));

   printf("Employe : %3d  %s\n\n%s\n%s\n%s\n", employe.numero,
                                               employe.nom,
                                               employe.adresse.rue,
                                               employe.adresse.code_postal,
    employe.adresse.ville);

   return 0;
}
