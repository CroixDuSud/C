/* ========================================================================== */
/* Projet : presFactures -- Edition des factures                              */
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
   char crNcli[4];
   float remise;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des factures                                          */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "r:\\c\\fichiers\\factures");

   fichierFactures = fopen(nomfich, "r+b");

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
/* Debut programme : lecture initiale                                         */
/* -------------------------------------------------------------------------- */
   fread(&facture, sizeof(FACTURE), 1, fichierFactures);

   while (!feof(fichierFactures))
   {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
      strcpy(crNcli, facture.ncli);
      fprintf(edition, "CLIENT : %s\n\n", facture.ncli);

      while ((strcmp(facture.ncli, crNcli) == 0) && (!feof(fichierFactures)))
      {

/* -------------------------------------------------------------------------- */
/* Debut facture                                                              */
/* -------------------------------------------------------------------------- */
         fprintf(edition, "         %5s     %7.2f", facture.nfac, facture.mont);

         if (facture.mont > 2000.00)
         {

/* -------------------------------------------------------------------------- */
/* Traitement remise                                                          */
/* -------------------------------------------------------------------------- */
            remise = facture.mont * 0.1f;
            fprintf(edition, "   %5.2f", remise);
         }

/* -------------------------------------------------------------------------- */
/* Fin facture                                                                */
/* -------------------------------------------------------------------------- */
         fprintf(edition, "\n");
         fread(&facture, sizeof(FACTURE), 1, fichierFactures);
      }

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
      fprintf(edition, "\n\n");
   }

/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
   fclose(fichierFactures);
   fclose(edition);

   return 0;
}
