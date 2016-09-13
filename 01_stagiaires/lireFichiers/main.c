/* ========================================================================== */
/* Projet : lireFichiers  --  Lecture des fichiers de l'evaluation Stagiaires */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\C\evaluation\entetes\stagiaire.h"
#include "R:\C\evaluation\entetes\matiere.h"

/* ========================================================================== */
/* Structure NOTE                                                             */
/*                                                                            */
/* numStagiaire : numero de stagiaire                                         */
/* numMatiere   : numero de matiere                                           */
/* note         : note                                                        */
/* ========================================================================== */

typedef struct
{
   int numStagiaire;
   int numMatiere;
   int note;
} NOTE;


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

   char nomfich[201];

   FILE* fichierStagiaires;
   FILE* fichierMatieres;
   FILE* fichierNotes;
   FILE* edition;

   STAGIAIRE stagiaire;
   MATIERE matiere;
   NOTE note;

/* -------------------------------------------------------------------------- */
/* DEBUT DU PROGRAMME : OUVERTURE DES FICHIERS                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des stagiaires, en lecture                            */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\stagiaires");

   fichierStagiaires = fopen(nomfich, "rb");

   if (fichierStagiaires == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER stagiaires ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des matieres, en lecture                              */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "R:\\C\\evaluation\\fichiers\\matieres");

   fichierMatieres = fopen(nomfich, "rb");

   if (fichierMatieres == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER matieres ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des notes, en lecture                                 */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\notes");

   fichierNotes = fopen(nomfich, "rb");

   if (fichierNotes == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER notes ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition (edition)                                   */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich,
      "U:\\Bip\\Formateur\\gnmi\\c\\evaluations\\fichiers\\fichiersEvalStag.txt");

   edition = fopen(nomfich, "wt");

   if (edition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER fichiersEfmStag.doc ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Impression du fichier des stagiaires                                       */
/* -------------------------------------------------------------------------- */
   fprintf(edition, "\n\nFICHIER DES STAGIAIRES\n\n");

   fread(&stagiaire, sizeof(STAGIAIRE), 1, fichierStagiaires);

   do
   {
      fprintf(edition, "%3d %s %s\n",
                       stagiaire.numero,
                       stagiaire.prenom,
                       stagiaire.nom);

      fread(&stagiaire, sizeof(STAGIAIRE), 1, fichierStagiaires);
   }
   while(!feof(fichierStagiaires));

/* -------------------------------------------------------------------------- */
/* Impression du fichier des matieres                                         */
/* -------------------------------------------------------------------------- */
   fprintf(edition, "\n\nFICHIER DES MATIERES\n\n");

   fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);

   do
   {
      fprintf(edition, "%3d %s\n",
                       matiere.numMatiere,
                       matiere.nomMatiere);

      fread(&matiere, sizeof(MATIERE), 1, fichierMatieres);
   }
   while(!feof(fichierMatieres));

/* -------------------------------------------------------------------------- */
/* Impression du fichier des notes                                            */
/* -------------------------------------------------------------------------- */
   fprintf(edition, "\n\nFICHIER DES NOTES\n\n");

   fread(&note, sizeof(NOTE), 1, fichierNotes);

   do
   {
      fprintf(edition, "%3d %3d %3d\n",
                       note.numStagiaire,
                       note.numMatiere,
                       note.note);

   fread(&note, sizeof(NOTE), 1, fichierNotes);
   }
   while(!feof(fichierNotes));

   fclose(fichierStagiaires);
   fclose(fichierMatieres);
   fclose(fichierNotes);
   fclose(edition);

   return 0;
}
