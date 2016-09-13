/* ========================================================================== */
/* Projet : presFactures1 -- Edition des factures                             */
/* -------------------------------------------------------------------------- */
/* Premiere version : tests techniques                                        */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
   char  ncli[4];
   char  nfac[6];
   float mont;
} FACTURE;


int main()
{
   FACTURE facture;
   FILE* fichierFactures;
   FILE* edition;
   char nomfich[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des factures                                          */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "r:\\c\\fichiers\\factures");

   fichierFactures = fopen(nomfich, "rb");

   if (fichierFactures == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER DES FACTURES ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "u:\\bip\\formateur\\gnmi\\c\\cours_algo\\fichiers\\editFactures.doc");

   edition = fopen(nomfich, "wt");

   if (edition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER EDITION ***\n");
      exit(0);
   }


/* -------------------------------------------------------------------------- */
/* Test de lecture du fichier facture                                         */
/* Test d'ecriture dans le fichier d'edition                                  */
/* -------------------------------------------------------------------------- */
   fread(&facture, sizeof(FACTURE), 1, fichierFactures);

   fprintf(edition, "%s  %s  %9.2f\n\n", facture.ncli,
                                         facture.nfac,
                                         facture.mont);

   printf("%s  %s  %9.2f\n\n", facture.ncli,
                               facture.nfac,
                               facture.mont);

/* -------------------------------------------------------------------------- */
/* Fermeture des fichiers                                                     */
/* -------------------------------------------------------------------------- */
   fclose(fichierFactures);
   fclose(edition);

   return 0;
}
