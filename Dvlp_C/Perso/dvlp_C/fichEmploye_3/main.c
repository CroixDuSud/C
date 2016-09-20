#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom [51];
    char prenom [41];
    int numeroAgence;
} EMPLOYE;

int main()
{
    EMPLOYE employe;
    FILE* fichierEmployes;

    AGENCE agence;
    FILE* fichierAgences;

    int numEnregAgence;

    char nomFichier [81];

    // Ouverture du fichier des employes (lecture)

    strcpy(nomFichier, "R:\\C\\fichiers\\fichEmploye");

    fichierEmployes = fopen(nomFichier, "rb");

    if (fichierEmployes == NULL)
    {
        printf("****ERREUR OUVERTURE FICHIER EMPLOYES****\n\n");
        exit(1);
    }

    // Ouverture du fichier des agences (en lecture)

    strcpy(nomFichier,"R:\\C\\fichiers\\agences");

    fichierAgences = fopen(nomFichier, "rb");

    if (fichierAgences == NULL)
    {
        printf("****ERREUR OUVERTURE FICHIER AGENCES****\n\n");
        exit(2);
    }

    // Boucle de lecture et d'affichage des employes

    printf("LISTE DES EMPLOYES\n\n");
    fread(&employe, sizeof(EMPLOYE), 1 , fichierEmployes);

    // Saisie des autres proprietes de l'employe :

    while (!feof(fichierEmployes))
    {
        // Recherche de l'enregistrement de l'agence

        numEnregAgence = chercheAgence (employe.numeroAgence, fichierAgences);

        // Agence existe, on lit l'enregistrement correspondant

        if (numEnregAgence != 1)
        {
            fseek(fichierAgences, numEnregAgence * sizeof (AGENCE), SEEK_SET);
            fread(&agence, sizeof (AGENCE), 1, fichierAgences);
        }

        printf("%3d %s %s (%s)\n"), employe.numero, employe.nom, employe.prenom, employe.numeroAgence);


    // L'agence n'existe pas

        else
        {
            printf("%3d %s %s (%d : agence inconnue)\n", employe.numero, employe.prenom, employe.nom, employe.numeroAgence);
        }

        fread(&employe, sizeof (EMPLOYE), 1, fichierEmployes);
    }

    fclose(fichierEmployes);
    fclose(fichierAgences);

    return 0;
}
