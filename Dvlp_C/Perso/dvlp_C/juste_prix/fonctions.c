




input_random()
{
// INITIALISATION DU TABLEAU

    srand(time(NULL));
    for (i = 0; i < 11; i++)
    {
        tableau [i] = rand() % limite;
        printf("%d\n", tableau [i]);
    }
}



input(unsigned int nombre)
{
    printf("Entrez un nombre : ")
    scanf("%d", nombre);
}
