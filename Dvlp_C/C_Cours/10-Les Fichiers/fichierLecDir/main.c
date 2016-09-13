/* ========================================================================== */
/* Projet : fichierLecDir                                                     */
/* -------------------------------------------------------------------------- */
/* Lecture directe et modification d'un fichier binaire                       */
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
                        /* -------------------------------------------------- */
   FILE* fichier;       /* Pointeur vers le fichier "formateurs"              */
                        /*                                                    */
   FORMATEUR form;      /* Variable de type FORMATEUR destinée à la lecture   */
                        /* du fichier                                         */
                        /*                                                    */
   int codeRetour;      /* Variable destinée à tester les codes retour des    */
                        /* fonctions liées au fichier. Ce code retour pourra  */
                        /* être commun à plusieurs fichiers                   */
                        /*                                                    */
   char nomFichier[81]; /* Tableau contenant le nom du fichier. On peut se    */
                        /* passer de ce tableau en entrant le nom du tableau  */
                        /* directement dans le fopen(), mais c'est souvent    */
                        /* plus pratique ainsi...                             */
                        /* -------------------------------------------------- */

   char ligne[81];      /* Tableau pour la saisie d'une ligne au clavier      */
   int numEnreg;        /* Numero de l'enregistrement a lire et modifier      */
                        /* La numerotation commence a 0                       */


/* -------------------------------------------------------------------------- */
/* Nom du fichier d'entree :                                                  */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier,
      "u:\\bip\\formateur\\gnmi\\c\\cours_c\\fichiers\\formateurs");

/* -------------------------------------------------------------------------- */
/* Ouverture en mise a jour (r+) du fichier binaire(b)                        */
/* -------------------------------------------------------------------------- */
   fichier = fopen(nomFichier, "r+b");
   if (fichier == 0)
   {
      printf(" *** ERREUR OUVERTURE FICHIER 'formateurs' ***");
      exit(0);
   }


/* -------------------------------------------------------------------------- */
/* Boucle de lecture et de modification du fichier                            */
/* -------------------------------------------------------------------------- */
   printf("Numero de l'enregistrement a modifier : ");
   gets(ligne);

   while (ligne[0] != 0)
   {
      numEnreg = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Le deuxieme parametre de la fonction fseek est un deplacement en nombre    */
/* d'octets. Pour assurer la portabilite on utilisera sizeof.                 */
/* -------------------------------------------------------------------------- */
/* Le troisieme parametre indique l'origine du deplacement :                  */
/* SEEK_SET (0) : a partir du debut du fichier                                */
/* SEEK_CUR (1) : a partir de le position courante                            */
/* SEEK_END (2) : a partir de la fin de fichier                               */
/* -------------------------------------------------------------------------- */
      codeRetour = fseek(fichier, numEnreg * sizeof(FORMATEUR), SEEK_SET);

/* -------------------------------------------------------------------------- */
/* Si le fseek a echoue (code retour != 0), ne pas lire                       */
/* -------------------------------------------------------------------------- */
/* Un cas de plantage du fseek est celui d'un deplacement negatif. Dans le    */
/* cas d'un deplacement positif, il n'y a pas de probleme... Si on est au     */
/* dela de la fin de fichier, le fread suivant se plantera. Un fwrite par     */
/* contre fonctionnerait !                                                    */
/* -------------------------------------------------------------------------- */
      if (codeRetour != 0)
      {
         printf("Echec du fseek pour l'enregistrement %d !\n\n", numEnreg);
      }
      else
      {
         codeRetour = fread(&form, sizeof(FORMATEUR), 1, fichier);

/* -------------------------------------------------------------------------- */
/* codeRetour contient le nombre de blocs lus (le nombre de blocs est le      */
/* troisieme parametre du fread).                                             */
/* -------------------------------------------------------------------------- */
         if (codeRetour == 1)
         {
            printf("Formateur : %d %s\n", form.numero, form.nom);
            printf("\nNouveau nom de %s : ", form.nom);
            gets(form.nom);


            if(form.nom[0] != 0)
            {
               fseek(fichier, numEnreg * sizeof(FORMATEUR), SEEK_SET);
               fwrite(&form, sizeof(FORMATEUR), 1, fichier);
            }
         }
         else
         {
            printf("L'enregistrement %d n'existe pas !", numEnreg);
         }
         printf("\n\n");
      }

      printf("Numero de l'enregistrement a lire : ");
      gets(ligne);
   }

   printf("\nFin de la saisie...\n\n");

   fclose(fichier);

   return 0;
}
