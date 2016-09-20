/* ========================================================================== */
/* Projet : initStagiaires  --  initialisation du fichier stagiaires          */
/* -------------------------------------------------------------------------- */
/* Cette initialisation est faite a partir du fichier texte stagiaires.txt    */
/* -------------------------------------------------------------------------- */
/* Auteur :                                                                   */
/* ========================================================================== */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "C:\Users\afpa1800\Desktop\evaluation\entetes\stagiaire.h"
#include "C:\Users\afpa1800\Desktop\evaluation\entetes\chaines.h"

/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
   char nomfich[201];

   FILE* fichierTexteStagiaires;
   char ligne [81];

   STAGIAIRE stagiaire;
   FILE* fichierStagiaires;

   char mot[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier texte des stagiaires                                  */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichiers\\stagiaires.txt");

   fichierTexteStagiaires = fopen(nomfich, "rt");

   if (fichierTexteStagiaires == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER TEXTE stagiaires.txt *****\n");
      exit(0);
   }


/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des stagiaires                                        */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichierStagiaire\\stagiaires");

   fichierStagiaires = fopen(nomfich, "rb");

   if (fichierStagiaires == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER stagiaires *****\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Premiere lecture dans le fichier texte des stagiaires                      */
/* -------------------------------------------------------------------------- */
   fgets(ligne, 80, fichierTexteStagiaires);
   //printf (ligne,&ligne);

/* -------------------------------------------------------------------------- */
/* Boucle de lecture des stagiaires (stagiaires.txt) et d'ecriture dans le    */
/* fichier binaire des stagiaires (stagiaires)                                */
/* -------------------------------------------------------------------------- */
   while (!feof(fichierTexteStagiaires))
   {
      isole(ligne, mot);
      stagiaire.numero = atoi(mot);
      isole(ligne, stagiaire.nom);
      isole(ligne, stagiaire.prenom);

      fwrite(&stagiaire, sizeof(STAGIAIRE), 1, fichierStagiaires);
      fgets(ligne, 80, fichierTexteStagiaires);
   }

   fclose(fichierTexteStagiaires);
   fclose(fichierStagiaires);

   return 0;
}
