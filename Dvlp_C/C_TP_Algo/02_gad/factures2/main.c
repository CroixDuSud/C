/* ========================================================================== */
/* Projet : factures2  --  tests de la logique                                */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "R:\C\utilitaires\entetes\chaines.h"
#include "R:\C\utilitaires\entetes\client.h"


typedef struct
{
   char  noComm[7];
   char  noCli[5];
   char  noProd[5];
   int   quantite;
   char  desig[21];
   float prix;
   char  date[11];
} COMMANDE;


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{

/* -------------------------------------------------------------------------- */
/* VARIABLES                                                                  */
/* -------------------------------------------------------------------------- */
/* Variables pour l'utilisation des fichiers                                  */
/* -------------------------------------------------------------------------- */
   FILE* fichierCommandes;
   COMMANDE commande;

   FILE* fichierCommandesDep;
   COMMANDE commandeDep;

   FILE* fichierClients;
   CLIENT client;

   char nomfich[81];

   char cr_noCli[5];
   char cr_noComm[7];
   char cr_noCommd[7];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des commandes                                 */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\comm");

   fichierCommandes = fopen(nomfich, "rb");

   if (fichierCommandes == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER comm *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des commandes de depannage                    */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\commd");

   fichierCommandesDep = fopen(nomfich, "rb");

   if (fichierCommandesDep == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER commd *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des clients                                   */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\client");

   fichierClients = fopen(nomfich, "r+b");

   if (fichierClients == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER client *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* DEBUT                                                                      */
/* -------------------------------------------------------------------------- */
   fread(&commande,  sizeof(COMMANDE), 1, fichierCommandes);
   if (feof(fichierCommandes))
      chaine_max(commande.noCli, sizeof(commande.noCli));

   fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);
   if (feof(fichierCommandesDep))
      chaine_max(commandeDep.noCli, sizeof(commandeDep.noCli));

   do
   {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
      strcpy(cr_noCli, commande.noCli);

      strcpy(client.noCli, commande.noCli);
      litClient(&client, fichierClients);
      printf("Client : %15s\n", client.nom);

      do
      {

/* -------------------------------------------------------------------------- */
/* Debut commande                                                             */
/* -------------------------------------------------------------------------- */
         strcpy(cr_noComm, commande.noComm);
         printf("   Commande : %s\n", cr_noComm);

         do
         {

/* -------------------------------------------------------------------------- */
/* Traitement produit                                                         */
/* -------------------------------------------------------------------------- */
            printf("      Produit : %s\n", commande.noProd);

            fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);
            if (feof(fichierCommandes))
               chaine_max(commande.noCli, sizeof(commande.noCli));
         }
         while((strcmp(commande.noCli, cr_noCli)==0) &&
               (strcmp(commande.noComm, cr_noComm) == 0));

/* -------------------------------------------------------------------------- */
/* Fin commande                                                               */
/* -------------------------------------------------------------------------- */
      }
      while(strcmp(commande.noCli, cr_noCli)==0);

/* -------------------------------------------------------------------------- */
/* Inter1 : Y-a-t'il des commandes de dépannage ?                             */
/* -------------------------------------------------------------------------- */
      if(strcmp(commandeDep.noCli, cr_noCli) == 0)
      {

/* -------------------------------------------------------------------------- */
/* Debut groupe commande depannage                                            */
/* -------------------------------------------------------------------------- */
         do
         {

/* -------------------------------------------------------------------------- */
/* Debut commande depannage                                                   */
/* -------------------------------------------------------------------------- */
            strcpy(cr_noCommd, commandeDep.noComm);
            printf("   Commande dep : %s\n", cr_noCommd);

            do
            {

/* -------------------------------------------------------------------------- */
/* Traitement produit depannage                                               */
/* -------------------------------------------------------------------------- */
               printf("      Produit : %s\n", commandeDep.noProd);

               fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);
               if (feof(fichierCommandesDep))
                  chaine_max(commandeDep.noCli, sizeof(commandeDep.noCli));
            }
            while((strcmp(commandeDep.noCli, cr_noCli)==0) &&
                  (strcmp(commandeDep.noComm, cr_noCommd) == 0));

/* -------------------------------------------------------------------------- */
/* Fin commande depannage                                                     */
/* -------------------------------------------------------------------------- */
         }
         while(strcmp(commandeDep.noCli, cr_noCli)==0);

/* -------------------------------------------------------------------------- */
/* Fin groupe commande depannage                                              */
/* -------------------------------------------------------------------------- */
      }

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
   }
   while(!feof(fichierCommandes));


   fclose(fichierCommandes);
   fclose(fichierCommandesDep);
   fclose(fichierClients);

   return 0;
}
