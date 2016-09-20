#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, ratio;

    printf("Tapez 2 nombres reels :\n");
    scanf("%f %f", &a, &b);

    while (b == 0.0) //gestion erreur division par 0
    {
        printf("Impossible de diviser par 0 !!!\n Re-tapez un nombre svp :\n");
        scanf("%f", &b);
    }

    ratio = a / b; //division

    printf("La division de %f par %f vaut : %f\n\n", a, b, ratio);

    return 0;
}
