/* ========================================================================== */
/* Projet : factures  --  programme complet                                   */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "R:\C\utilitaires\entetes\chaines.h"
#include "R:\C\utilitaires\entetes\temps.h"
#include "R:\C\utilitaires\entetes\client.h"

void entete(CLIENT client, int numPage, int numFac, FILE* fichierEdition);

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

int main(int argc, char* argv[])
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

   FILE* fichierEdition;

   char nomfich[81];

/* -------------------------------------------------------------------------- */
/* Criteres de reference                                                      */
/* -------------------------------------------------------------------------- */
   char cr_noCli[5];
   char cr_noComm[7];
   char cr_noCommd[7];

/* -------------------------------------------------------------------------- */
/* Lignes d'edition                                                           */
/* -------------------------------------------------------------------------- */
/* Remarque : les lignes le1, le2, le3, le4, le5 sont declarees, remplies et  */
/*            affichees dans la fonction entete()...                          */
/* -------------------------------------------------------------------------- */
   char ld1[101] = "";
   char le6[101] = "";
   char lt1[101] = "";
   char lt2[101] = "";
   char lt3[101] = "";
   char lt4[101] = "";
   char lt4saut[101] = "";

/* -------------------------------------------------------------------------- */
/* Variables de travail                                                       */
/* -------------------------------------------------------------------------- */
   char chaineNum[81];   /* Chaine pour la conversion de valeurs numeriques   */
   char ligne[81];       /* Ligne pour la saisie du premier numero de facture */
   int  numFac;          /* Numero de facture                                 */
   char affDateComm[11]; /* Chaine de travail pour reduire la date en JJMMAA  */

/* -------------------------------------------------------------------------- */
/* Variables pour les sauts de pages                                          */
/* -------------------------------------------------------------------------- */
   int nLig;        /* Nombre de lignes ld1 et le6 deja ecrites               */
   int nLigSaut;    /* Nombre de lignes a sauter pour ecrire le pied de page  */
   int numPage;     /* Numero de la page a imprimer (demarre a 1 par client)  */
   int i;           /* Pour compter les lignes a sauter avant le pied de page */

/* -------------------------------------------------------------------------- */
/* Totaux                                                                     */
/* -------------------------------------------------------------------------- */
   float montant;        /* Montant d'un produit                              */
   float sommeMontants;  /* Somme des montants d'une facture                  */

   float z01, z02, z03, z04;

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
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\tp_algo\\fichiers\\editionFactures.doc");

   fichierEdition = fopen(nomfich, "wt");

   if (fichierEdition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER EDITION ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* DEBUT                                                                      */
/* -------------------------------------------------------------------------- */
   if (argc > 1)
   {
      numFac = atoi(argv[1]);
   }
   else
   {
      printf("Entrer le premier numero de facture : ");
      gets(ligne);
      numFac = atoi(ligne);         /* Premier numero de facture (6 chiffres) */
   }

   placeSousChaine(le6, "D E P A N N A G E", 36, 'd');
   placeSousChaine(lt4saut, " ../..", 89, 'g');

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

      sommeMontants = 0;

      strcpy(client.noCli, commande.noCli);
      litClient(&client, fichierClients);

      nLig = 0;
      numPage = 1;
      entete(client, numPage, numFac, fichierEdition);

      do
      {

/* -------------------------------------------------------------------------- */
/* Debut commande                                                             */
/* -------------------------------------------------------------------------- */
         strcpy(cr_noComm, commande.noComm);

         placeSousChaine(ld1, cr_noComm, 4, 'd');
         strcpy(affDateComm, commande.date);
         strcpy(affDateComm + 6, affDateComm + 8);
         placeSousChaine(ld1, affDateComm, 15, 'd');

         do
         {

/* -------------------------------------------------------------------------- */
/* Traitement produit                                                         */
/* -------------------------------------------------------------------------- */
            montant = commande.quantite * commande.prix;
            sommeMontants += montant;

            placeSousChaine(ld1, commande.noProd, 27, 'd');
            placeSousChaine(ld1, commande.desig, 37, 'd');
            intChaine(commande.quantite, 0, chaineNum);
            placeSousChaine(ld1, chaineNum, 63, 'g');
            doubleChaine(commande.prix, 2, 1, ' ', chaineNum);
            placeSousChaine(ld1, chaineNum, 76, 'g');
            doubleChaine(montant, 2, 1, ' ', chaineNum);
            placeSousChaine(ld1, chaineNum, 89, 'g');

            if (nLig > 12)
            {
               nLigSaut = 11 + (13 - nLig) * 2;
               for (i = 1; i <= nLigSaut; i++) fprintf(fichierEdition, "\n");
               fprintf(fichierEdition, "%s", lt4saut);

               numPage++;
               entete(client, numPage, numFac, fichierEdition);
               nLig = 0;

               placeSousChaine(ld1, cr_noComm, 4, 'd');
               placeSousChaine(ld1, affDateComm, 15, 'd');
            }

            fprintf(fichierEdition, "%s\n\n", ld1);
            strcpy(ld1, "");
            nLig++;

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
         if (nLig > 11)
         {
            nLigSaut = 11 + (13 - nLig) * 2;
            for (i = 1; i <= nLigSaut; i++) fprintf(fichierEdition, "\n");
            fprintf(fichierEdition, "%s", lt4saut);

            numPage++;
            entete(client, numPage, numFac, fichierEdition);
            nLig = 0;
         }

         fprintf(fichierEdition, "%s\n\n", le6);
         nLig++;

         do
         {

/* -------------------------------------------------------------------------- */
/* Debut commande depannage                                                   */
/* -------------------------------------------------------------------------- */
            strcpy(cr_noCommd, commandeDep.noComm);

            placeSousChaine(ld1, cr_noCommd, 4, 'd');
            strcpy(affDateComm, commandeDep.date);
            strcpy(affDateComm + 6, affDateComm + 8);
            placeSousChaine(ld1, affDateComm, 15, 'd');

            do
            {

/* -------------------------------------------------------------------------- */
/* Traitement produit depannage                                               */
/* -------------------------------------------------------------------------- */
               montant = commandeDep.quantite * commandeDep.prix;
               sommeMontants += montant;

               placeSousChaine(ld1, commandeDep.noProd, 27, 'd');
               placeSousChaine(ld1, commandeDep.desig, 37, 'd');
               intChaine(commandeDep.quantite, 0, chaineNum);
               placeSousChaine(ld1, chaineNum, 63, 'g');
               doubleChaine(commandeDep.prix, 2, 1, ' ', chaineNum);
               placeSousChaine(ld1, chaineNum, 76, 'g');
               doubleChaine(montant, 2, 1, ' ', chaineNum);
               placeSousChaine(ld1, chaineNum, 89, 'g');

               if (nLig > 12)
               {
                  nLigSaut = 11 + (13 - nLig) * 2;
                  for (i = 1; i <= nLigSaut; i++) fprintf(fichierEdition, "\n");
                  fprintf(fichierEdition, "%s", lt4saut);

                  numPage++;
                  entete(client, numPage, numFac, fichierEdition);
                  nLig = 0;

                  placeSousChaine(ld1, cr_noCommd, 4, 'd');
                  placeSousChaine(ld1, affDateComm, 15, 'd');
               }

               fprintf(fichierEdition, "%s\n\n", ld1);
               strcpy(ld1, "");
               nLig++;

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
      if (sommeMontants > 25000.00f)
      {
         z01 = sommeMontants * 0.02f;
         doubleChaine(z01, 2, 1, ' ', chaineNum);
         placeSousChaine(lt1, chaineNum, 89, 'g');
      }
      else
      {
         z01 = 0.0f;
      }

      z02 = sommeMontants - z01;
      z03 = z02 * 0.196f;
      z04 = z02 + z03;

      nLigSaut = 3 + (13 - nLig) * 2;
      for (i = 1; i <= nLigSaut; i++) fprintf(fichierEdition, "\n");

      fprintf(fichierEdition, "%s\n\n", lt1);
      strcpy(lt1, "");

      doubleChaine(z02, 2, 1, ' ', chaineNum);
      placeSousChaine(lt2, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n\n", lt2);
      strcpy(lt2, "");

      doubleChaine(z03, 2, 1, ' ', chaineNum);
      placeSousChaine(lt3, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n\n\n\n", lt3);
      strcpy(lt3, "");

      doubleChaine(z04, 2, 1, ' ', chaineNum);
      placeSousChaine(lt4, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n", lt4);
      strcpy(lt4, "");

/* -------------------------------------------------------------------------- */
/* Mise a jour du solde du client                                             */
/* -------------------------------------------------------------------------- */
      if(client.codSit == 'D')
      {
         client.solde += z04;
      }
      else
      {
         if (client.solde > z04)
         {
            client.solde = client.solde - z04;
         }
         else
         {
            client.solde = z04 - client.solde;
            client.codSit = 'D';
         }
      }

      ecritClient(&client, fichierClients);

      numFac++;
   }
   while(!feof(fichierCommandes));


   fclose(fichierCommandes);
   fclose(fichierCommandesDep);
   fclose(fichierClients);
   fclose(fichierEdition);

   return 0;
}

/* ========================================================================== */
/* Affichage de l'entete                                                      */
/* ========================================================================== */

void entete(CLIENT client, int numPage, int numFac, FILE* fichierEdition)
{
   char le1[101] = "";
   char le2[101] = "";
   char le3[101] = "";
   char le4[101] = "";
   char le5[101] = "";

   char chaineNum[81];   /* Chaine pour la conversion de valeurs numeriques   */
   char chaineDate[11];  /* Chaine pour la mise en forme de la date systeme   */

   getDateSysteme8(chaineDate);                  /* Date systeme (JJ/MM/AAAA) */

   placeSousChaine(le1, client.noCli, 17, 'd');
   intChaine(numPage, 0, chaineNum);
   placeSousChaine(le1, chaineNum, 33, 'd');

   placeSousChaine(le2, client.nom, 10, 'd');

   placeSousChaine(le3, client.adresse, 10, 'd');

   placeSousChaine(le4, client.cPost, 10, 'd');
   placeSousChaine(le4, client.ville, 16, 'd');

   intChaine(numFac, 0, chaineNum);
   placeSousChaine(le5, chaineNum, 22, 'd');
   placeSousChaine(le5, chaineDate, 36, 'd');
   placeSousChaine(le5, client.codPays, 80, 'd');
   placeSousChaine(le5, client.noRep, 84, 'd');

   fprintf(fichierEdition, "\f%s\n\n\n\n\n\n", le1);
   fprintf(fichierEdition, "%s\n\n", le2);
   fprintf(fichierEdition, "%s\n", le3);
   fprintf(fichierEdition, "%s\n\n\n\n\n\n", le4);
   fprintf(fichierEdition, "%s\n\n\n\n\n\n", le5);
}
