/* ========================================================================== */
/* projet : tableau de caracteres, fonctions de string.h                      */
/* fichier : chaiStringH.c                                                    */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
   char chaine[81];
   char chaineComplementaire[81];

   strcpy(chaine, "Fumier infect !");

   printf("Chaine initiale --> ");
   puts(chaine);

   printf("\n\nChaine complementaire : ");
   gets(chaineComplementaire);

/* -------------------------------------------------------------------------- */
/* Ajout d'un blanc et de la chaine complementaire a la chaine initiale       */
/* -------------------------------------------------------------------------- */
   strcat(chaine, " ");
   strcat(chaine, chaineComplementaire);

   printf("\n\nChaine completee --> ");
   puts(chaine);

/* -------------------------------------------------------------------------- */
/* Ajout d'un tiret (-) et de la chaine complementaire a la chaine completee  */
/* -------------------------------------------------------------------------- */
/* La valeur de retour de strcat est utilisee pour eviter deux appels         */
/* successifs de strcat                                                       */
/* -------------------------------------------------------------------------- */
   strcat(strcat(chaine, " - "), chaineComplementaire);

   printf("\n\nChaine finale --> ");
   puts(chaine);

   return 0;
}
