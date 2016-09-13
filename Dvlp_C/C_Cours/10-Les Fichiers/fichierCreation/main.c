/* ========================================================================== */
/* Projet : fichierCreation -- Creation sequentielle d'un fichier binaire     */
/* -------------------------------------------------------------------------- */
/* Ce fichier va contenir une succession d'enregistrements de type FORMATEUR  */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   int numero;
   char nom[51];
} FORMATEUR;


int main()
{
                          /* ------------------------------------------------ */
   FILE* fichier;         /* Pointeur vers le fichier                         */
                          /*                                                  */
   FORMATEUR tablForm[3]; /* Tableau contenant 3 FORMATEURs a ecrire dans le  */
                          /* fichier                                          */
                          /*                                                  */
   int i;                 /* Indice de parcours du tableau                    */
                          /*                                                  */
   int codeRetour;        /* Variable destin�e � tester les codes retour des  */
                          /* fonctions li�es au fichier. Ce code retour       */
                          /* pourra etre commun � plusieurs fichiers          */
                          /*                                                  */
   char nomFichier[81];   /* Tableau contenant le nom du fichier. On peut se  */
                          /* passer de ce tableau en entrant le nom du        */
                          /* tableau directement dans le fopen(), mais c'est  */
                          /* souvent plus pratique ainsi...                   */
                          /* ------------------------------------------------ */


/* -------------------------------------------------------------------------- */
/* Initialisation du nom du fichier : chemin d'acces                          */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
      "U:\\Bip\\Formateur\\gnmi\\c\\cours_c\\fichiers\\formateurs");

/* -------------------------------------------------------------------------- */
/* Ouverture en ecriture (w) d'un fichier binaire (b)                         */
/* Attention ! Si le fichier existe deja, il est ECRASE !                     */
/* Si fopen retourne 0, l'ouverture s'est "plantee"                           */
/* -------------------------------------------------------------------------- */
   fichier = fopen(nomFichier, "wb");
   if (fichier == 0)
   {
      printf(" *** Erreur d'ouverture du fichier %s ***", nomFichier);
      exit(0);
   }


/* -------------------------------------------------------------------------- */
/* Remplissage du tableau de FORMATEURs                                       */
/* -------------------------------------------------------------------------- */
   tablForm[0].numero = 17;
   strcpy(tablForm[0].nom, "FUMIER INFECT");

   tablForm[1].numero = 19;
   strcpy(tablForm[1].nom, "SALOPARD");

   tablForm[2].numero = 22;
   strcpy(tablForm[2].nom, "CRAPULE ABJECTE");

   for(i = 0; i <= 2; i++)
   {
      codeRetour = fwrite(&tablForm[i], sizeof(FORMATEUR), 1, fichier);

/* -------------------------------------------------------------------------- */
/* codeRetour re�oit le nombre de blocs effectivement �crits.                 */
/* Le nombre de blocs a ecrire est le troisieme parametre du fwrite (ici 1).  */
/* Si codeRetour < 1, il y a eu incident                                      */
/* -------------------------------------------------------------------------- */
      printf("codeRetour = %d\n", codeRetour);

      if (codeRetour < 1)
      {
         printf("Erreur d'ecriture enregistrement %d\n", i);
      }
   }

   printf("Fin de l'enregistrement des formateurs...\n\n");
   fclose(fichier);

   return 0;
}
