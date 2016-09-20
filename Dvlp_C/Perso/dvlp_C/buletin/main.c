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
#include <conio.h>
#include <string.h>
#include <time.h>

#include "C:\Users\afpa1800\Desktop\evaluation\entetes\chaines.h"
#include "R:\C\evaluation\entetes\note.h"
#include "R:\C\evaluation\entetes\stagiaire.h"
#include "R:\C\evaluation\entetes\matiere.h"

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
   char nomfich[201];

   FILE* fichierTexteStagiaires;
   FILE* fichierMatieres;
   FILE* fichierNotes;
   FILE* fichierStagiaires;
   FILE* edition;

   char ligne [81];

   STAGIAIRE stagiaire;
   MATIERE matiere;
   NOTE note;


   char mot[81];

    int numStagiaire;
    int numMatiere;
   int aDesNotes;
   int nombreNotes;
   int iNote;

   srand((unsigned)time(NULL));



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
/* Ouverture du fichier des notes                                             */
/* -------------------------------------------------------------------------- */

   strcpy(nomfich,
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichiers\\notes");

   fichierNotes = fopen(nomfich, "wb");

   if (fichierNotes == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER notes ***\n");
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
/* ========================================================================== */
/* Projet : initNotes  --  initialisation du fichier des notes des stagiaires */
/* -------------------------------------------------------------------------- */
/* Auteur :                                                                   */
/* ========================================================================== */
/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "R:\C\evaluation\entetes\note.h"
*/
/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{
   char nomfich[201];

   FILE* fichierNotes;
   NOTE note;

   int numStagiaire;
   int numMatiere;

   int aDesNotes;
   int nombreNotes;
   int iNote;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des notes                                             */
/* -------------------------------------------------------------------------- */

   strcpy(nomfich,
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichiers\\notes");

   fichierNotes = fopen(nomfich, "wb");

   if (fichierNotes == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER notes ***\n");
      exit(0);
   }

   srand((unsigned)time(NULL));

   for (numStagiaire = 1; numStagiaire <= 14; numStagiaire++)
   {
      aDesNotes = rand() % 4;

      if (aDesNotes != 0)
      {
         printf("\n\n====> Stagiaire %d\n\n", numStagiaire);

         note.numStagiaire = numStagiaire;

         for (numMatiere = 1; numMatiere <= 5; numMatiere++)
         {
            nombreNotes = rand() % 4;
            printf("Matiere %d : %d\n", numMatiere, nombreNotes);

            if(nombreNotes > 0)
            {
               note.numMatiere = numMatiere;
               for (iNote = 1; iNote <= nombreNotes; iNote++)
               {
                  note.note = rand() % 21;
                  printf("%d %d %d\n", note.numStagiaire, note.numMatiere, note.note);
                  fwrite(&note, sizeof(NOTE), 1, fichierNotes);
               }
            }
         }
         _getch();
      }
   }

   fclose(fichierNotes);

   return 0;
}


/* ========================================================================== */
/* Projet : lireFichiers  --  Lecture des fichiers de l'evaluation Stagiaires */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "R:\C\evaluation\entetes\stagiaire.h"
#include "R:\C\evaluation\entetes\matiere.h"
*/
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
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichierStagiaire\\stagiaires");

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
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichiers\\notes");

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
      "C:\\Users\\afpa1800\\Desktop\\evaluation\\fichiersEvalStag.txt");

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
