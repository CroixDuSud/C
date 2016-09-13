/* ========================================================================== */
/* Projet : vente -- Statistique des ventes                                   */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "R:\C\utilitaires\entetes\temps.h"

/* -------------------------------------------------------------------------- */
/* Structure VERSEMENT                                                        */
/* -------------------------------------------------------------------------- */

typedef struct
{
   char   nosect[3];
   char   norep[4];
   char   nocli[5];
   char   nofac[6];
   double mont;
   char   codpays[3];
}VERSEMENT;


int main()
{
   FILE* fichierVersements;
   FILE* edition;

   char nomfich[81];

   VERSEMENT versement;

   char  cr_nosect[3];
   char  cr_norep[4];
   char  cr_nocli[5];

   double z01, z02, z03, z04, z05, z06, z07, z08, z09, z10, z11;

   char ld1_norep[4];

   char chaineDate[9];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des versements                                        */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\versements");

   fichierVersements = fopen(nomfich, "rb");

   if (fichierVersements == NULL)
   {
      printf("\n*** ERREUR OUVERTURE FICHIER VERSEMENTS ***\n");
      exit (0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\stat ventes.doc");

   edition = fopen(nomfich, "wt");

   if (edition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER EDITION ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Debut du programme                                                         */
/* -------------------------------------------------------------------------- */
   getDateSysteme6(chaineDate);

   fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);

   z09 = 0;
   z10 = 0;
   z11 = 0;

   do
   {

/* -------------------------------------------------------------------------- */
/* Debut secteur                                                              */
/* -------------------------------------------------------------------------- */
      strcpy(cr_nosect, versement.nosect);

      z06 = 0;
      z07 = 0;
      z08 = 0;

      fprintf(edition, "\f%s", chaineDate);
      fprintf(edition, "        STATISTIQUE MENSUELLE DES VENTES\n\n");
      fprintf(edition, "                            ");
      fprintf(edition, "SECTEUR %s\n\n", versement.nosect);
      fprintf(edition, "REPRESENTANT  CLIENT   MONTANT FRANCE   ");
      fprintf(edition, "MONTANT EXPORT    PRIME\n\n");
      do
      {

/* -------------------------------------------------------------------------- */
/* Debut representant                                                         */
/* -------------------------------------------------------------------------- */
         strcpy(cr_norep, versement.norep);

         z03 = 0;
         z04 = 0;

         strcpy(ld1_norep, versement.norep);

         do
         {



/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
            strcpy(cr_nocli, versement.nocli);

            z01 = 0;
            z02 = 0;

            do
            {

/* -------------------------------------------------------------------------- */
/* Debut versement                                                            */
/* -------------------------------------------------------------------------- */
               if (strcmp(versement.codpays, "") == 0)
               {                                            /* Facture France */
                  z01+=versement.mont;
               }
               else
               {                                            /* Facture Export */
                  z02+=versement.mont;
               }

/* -------------------------------------------------------------------------- */
/* Fin versement                                                              */
/* -------------------------------------------------------------------------- */
               fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);
            }
            while ((!feof(fichierVersements)) &&
                  (strcmp(cr_nosect, versement.nosect) == 0) &&
                  (strcmp(cr_norep, versement.norep)   == 0) &&
                  (strcmp(cr_nocli, versement.nocli)   == 0));

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
            fprintf(edition, "    %3s        ", ld1_norep);
            fprintf(edition, "%s       ", cr_nocli);
            if (z01 > 0)
               fprintf(edition, "%9.2f       ", z01);
            else
               fprintf(edition, "                ");
            if (z02 > 0)
               fprintf(edition, "%9.2f\n", z02);
            else
               fprintf(edition, "         \n");
            strcpy(ld1_norep, "");

            z03 += z01;
            z04 += z02;
         }
         while ((!feof(fichierVersements)) &&
               (strcmp(cr_nosect, versement.nosect) == 0) &&
               (strcmp(cr_norep, versement.norep)   == 0));







/* -------------------------------------------------------------------------- */
/* Fin representant                                                           */
/* -------------------------------------------------------------------------- */
         z05 = (z03 + z04) * 0.015;
         z06 += z03;
         z07 += z04;
         z08 += z05;

         fprintf(edition, "\nTOTAL REPRESENTANT        ");
         fprintf(edition, "%9.2f       %9.2f     %9.2f\n\n", z03, z04, z05);

      }
      while ((!feof(fichierVersements)) &&
            (strcmp(cr_nosect, versement.nosect) == 0));

/* -------------------------------------------------------------------------- */
/* Fin secteur                                                                */
/* -------------------------------------------------------------------------- */
      z09 += z06;
      z10 += z07;
      z11 += z08;

      fprintf(edition, "TOTAL SECTEUR            ");
      fprintf(edition, "%10.2f      %10.2f    %10.2f\n\n", z06, z07, z08);
   }
   while(!feof(fichierVersements));


/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
   fprintf(edition, "TOTAL GENERAL            ");
   fprintf(edition, "%10.2f      %10.2f    %10.2f\n\n", z09, z10, z11);

   fclose(fichierVersements);
   fclose(edition);

   return 0;
}
