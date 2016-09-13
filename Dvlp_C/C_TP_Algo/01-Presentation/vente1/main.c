/* ========================================================================== */
/* Projet : vente1 -- Statistique des ventes                                  */
/* -------------------------------------------------------------------------- */
/* Version 1 : structures logiques                                            */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   char nomfich[81];

   VERSEMENT versement;

   char  cr_nosect[3];
   char  cr_norep[4];
   char  cr_nocli[5];

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
/* Debut du programme                                                         */
/* -------------------------------------------------------------------------- */
   fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);

   do
   {

/* -------------------------------------------------------------------------- */
/* Debut secteur                                                              */
/* -------------------------------------------------------------------------- */
      strcpy(cr_nosect, versement.nosect);
      printf("Secteur %s\n", cr_nosect);

      do
      {


/* -------------------------------------------------------------------------- */
/* Debut representant                                                         */
/* -------------------------------------------------------------------------- */
         strcpy(cr_norep, versement.norep);
         printf("   Representant %s\n", cr_norep);

         do
         {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
            strcpy(cr_nocli, versement.nocli);
            printf("      Client %s\n", cr_nocli);

            do
            {

/* -------------------------------------------------------------------------- */
/* Debut versement                                                            */
/* -------------------------------------------------------------------------- */
               printf("         Facture %s\n", versement.nofac);

               if (strcmp(versement.codpays, "") == 0)
               {                                            /* Facture France */
               }
               else
               {                                            /* Facture Export */
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
         }
         while ((!feof(fichierVersements)) &&
               (strcmp(cr_nosect, versement.nosect) == 0) &&
               (strcmp(cr_norep, versement.norep)   == 0));

/* -------------------------------------------------------------------------- */
/* Fin representant                                                           */
/* -------------------------------------------------------------------------- */
      }
      while ((!feof(fichierVersements)) &&
            (strcmp(cr_nosect, versement.nosect) == 0));

/* -------------------------------------------------------------------------- */
/* Fin secteur                                                                */
/* -------------------------------------------------------------------------- */
   }
   while(!feof(fichierVersements));


/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
   printf("\n\n");
   fclose(fichierVersements);

   return 0;
}
