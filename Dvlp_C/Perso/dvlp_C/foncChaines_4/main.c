#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    int a;
    i = &a;
    a = 5;
    printf("%d", i);
    return 0;
}
