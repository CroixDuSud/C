/* ========================================================================== */
/* Projet : factures1  --  tests des fichiers d'entree                        */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

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
/* Impression du fichier des commandes                                        */
/* -------------------------------------------------------------------------- */
   printf("FICHIER DES COMMANDES (comm)\n\n");

   fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);

   do
   {
      strcpy(client.noCli, commande.noCli);
      litClient(&client, fichierClients);
      printf("%20s  ", client.nom);

      printf("%6s %4s %4s %4d %14s %7.2f %10s\n",
             commande.noComm,
             commande.noCli,
             commande.noProd,
             commande.quantite,
             commande.desig,
             commande.prix,
             commande.date);

      fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);
   }
   while(!feof(fichierCommandes));


/* -------------------------------------------------------------------------- */
/* Impression du fichier des commandes depannage                              */
/* -------------------------------------------------------------------------- */
   printf("\nFICHIER DES COMMANDES DEPANNAGE (commd)\n\n");

   fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);

   do
   {
      strcpy(client.noCli, commandeDep.noCli);
      litClient(&client, fichierClients);
      printf("%20s  ", client.nom);

      printf("%6s %4s %4s %4d %14s %7.2f %10s\n",
             commandeDep.noComm,
             commandeDep.noCli,
             commandeDep.noProd,
             commandeDep.quantite,
             commandeDep.desig,
             commandeDep.prix,
             commandeDep.date);

      fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);
   }
   while(!feof(fichierCommandesDep));


   fclose(fichierCommandes);
   fclose(fichierCommandesDep);
   fclose(fichierClients);

   return 0;
}
