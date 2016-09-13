/* ========================================================================== */
/* Projet : presFactures2 -- Edition des factures                             */
/* -------------------------------------------------------------------------- */
/* Deuxieme version : tests des structures logiques                           */
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
      fprintf(edition, "CLIENT : %s\n\n", crNcli);
      printf("CLIENT : %s\n\n", crNcli);

      while ((strcmp(facture.ncli, crNcli) == 0) && (!feof(fichierFactures)))
      {

/* -------------------------------------------------------------------------- */
/* Debut facture                                                              */
/* -------------------------------------------------------------------------- */
         if (facture.mont > 2000.00)
         {

/* -------------------------------------------------------------------------- */
/* Traitement remise                                                          */
/* -------------------------------------------------------------------------- */
         }
         else
         {

/* -------------------------------------------------------------------------- */
/* Traitement pas remise                                                      */
/* -------------------------------------------------------------------------- */
         }

/* -------------------------------------------------------------------------- */
/* Fin facture                                                                */
/* -------------------------------------------------------------------------- */
         fprintf(edition, "%4s     %6s    %7.2f\n\n", facture.ncli,
                                                      facture.nfac,
                                                      facture.mont);
         printf("%4s     %6s    %7.2f\n\n", facture.ncli,
                                            facture.nfac,
                                            facture.mont);
         fread(&facture, sizeof(FACTURE), 1, fichierFactures);
      }

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
   }

/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
   fclose(fichierFactures);
   fclose(edition);

   return 0;
}

