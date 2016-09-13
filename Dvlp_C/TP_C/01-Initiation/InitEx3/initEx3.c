/* ========================================================================== */
/* projet : TP_Initiation                                                     */
/* fichier : initEx3.c                                                        */
/* -------------------------------------------------------------------------- */
/* Saisir des nombres jusqu'a ce que leur total dépasse 100                   */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
    // déclaration des variables
   int n;                     /* Sert a recevoir le nombre tape               */
   int total;                 /* Contient le total des nombres (n) deja tapes */

   printf("Nombre a ajouter : ");
   scanf("%d", &n);
   total = n;

   while (total < 100)
   {
      printf("Total actuel : %d\n\n", total);

      printf("\n\nNombre a ajouter : ");
      scanf("%d", &n);
      total += n;
   }

   printf("\nTotal final : %d\n", total);

   return 0;
}


