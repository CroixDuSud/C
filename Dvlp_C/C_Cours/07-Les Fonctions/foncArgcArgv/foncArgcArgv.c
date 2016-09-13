/* ========================================================================== */
/* projet : affichage d'un texte complete par un parametre lu                 */
/*                     en ligne de commande.                                  */
/* fichier : foncArgcArgv.c                                                   */
/* -------------------------------------------------------------------------- */
/* auteur : Profs CDI Afpa Creteil                                            */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main(int argc, char* argv[])
{
    char* message;

    if(argc > 1)
    {
        message = argv[1];
    }
    else
    {
        message = "gagnant";
    }

    printf("Ce type a une bonne tete de %s.\n", message);

    return 0;
}
