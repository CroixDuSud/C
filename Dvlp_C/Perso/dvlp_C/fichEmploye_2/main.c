#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom [51];
    char prenom[41];
    int numeroAgence;
} EMPLOYE;

int main()
{
    FILE* fichEmploye;
    FILE* edition;

    EMPLOYE salarie;
    int codeRetour;
    char nomFichier[81];

    // INITIALISATION DU NOM DU FICHIER A LIRE

    strcpy(nomFichier,"C:\\Users\\afpa1800\\Desktop\\fichEmploye");

    // OUVERTURE EN LECTURE (r) DU FICHIER BINAIRE (b)

    fichEmploye = fopen(nomFichier, "rb");
    if (fichEmploye == 0)
    {
        printf(" *** Erreur lors de l'ouverture du fichier %s *** ", nomFichier);
        exit(0);
    }

    // NOM DU FICHIER D EDITION

    strcpy(nomFichier, "C:\\Users\\afpa1800\\Desktop\\EDIT_fichEmploye");


    // OUVERTURE DU FICHIER ET CONTROLE D'ERREUR

    edition = fopen(nomFichier, "wt");
    if(edition == 0)
    {
        printf(" *** ERREUR OUVERTURE FICHIER EDITION *** ");
        exit(1);
    }

    // BOUCLE DE LECTURE ET D'AFFICHAGE DU FICHIER

    printf(" Liste des employes\n\n");
    fprintf(edition, "Liste des employes\n\n");

    codeRetour =  fread(&salarie, sizeof(EMPLOYE), 1, fichEmploye);

    while(!feof(fichEmploye))
    {
        fprintf(edition, "Numero d'employe : %d\n", salarie.numero);
        fprintf(edition, "Nom : %s\n", salarie.nom);
        fprintf(edition, "Prenom : %s\n", salarie.prenom);
        fprintf(edition, "Numero d'agence : %d\n", salarie.numeroAgence);
        codeRetour = fread(&salarie, sizeof(EMPLOYE), 1, fichEmploye);
    }

    fclose(fichEmploye);
    fclose(edition);

    return 0;
}
