/* ========================================================================== */
/* Projet : presFacturesUtil -- Edition des factures                          */
/* -------------------------------------------------------------------------- */
/* Utilisation des fonctions de gestion de chaines (chaines.h)                */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\c\utilitaires\entetes\chaines.h"

/* -------------------------------------------------------------------------- */
/* Structure FACTURE                                                          */
/* -------------------------------------------------------------------------- */

typedef struct
{
   char  ncli[4];
   char  nfac[6];
   float mont;
} FACTURE;


/* -------------------------------------------------------------------------- */
/* Programme principal                                                        */
/* -------------------------------------------------------------------------- */

int main()
{
   FACTURE facture;
   FILE* fichierFactures;
   FILE* edition;

   char nomfich[81];
   char crNcli[4];
   float remise;

   char ligneEdition1[81] = "";
   char ligneEdition2[81] = "";

   char chaineNum[81];

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
/* Debut programme : lecture initiale                                         */
/* -------------------------------------------------------------------------- */
   fread(&facture, sizeof(FACTURE), 1, fichierFactures);

   while (!feof(fichierFactures))
   {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
      strcpy(crNcli, facture.ncli);

      placeSousChaine(ligneEdition1, "CLIENT :", 0, 'd');
      placeSousChaine(ligneEdition1, facture.ncli, 9, 'd');
      fprintf(edition, "%s\n\n", ligneEdition1);
      strcpy(ligneEdition1, "");

      while ((strcmp(facture.ncli, crNcli) == 0) && (!feof(fichierFactures)))
      {

/* -------------------------------------------------------------------------- */
/* Debut facture                                                              */
/* -------------------------------------------------------------------------- */
         placeSousChaine(ligneEdition2, facture.nfac, 9, 'd');
         doubleChaine(facture.mont, 2, 1, ' ', chaineNum);
         placeSousChaine(ligneEdition2, chaineNum, 26, 'g');

         if (facture.mont >= 2000.00)
         {

/* -------------------------------------------------------------------------- */
/* Traitement remise                                                          */
/* -------------------------------------------------------------------------- */
            remise = facture.mont * 0.1f;
            doubleChaine(remise, 2, 1, ' ', chaineNum);
            placeSousChaine(ligneEdition2, chaineNum, 35, 'g');
         }

/* -------------------------------------------------------------------------- */
/* Fin facture                                                                */
/* -------------------------------------------------------------------------- */
         fprintf(edition, "%s\n", ligneEdition2);
         strcpy(ligneEdition2, "");

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
