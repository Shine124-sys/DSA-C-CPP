/*Inverse of an array*/
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
int main()
{
    int a[5], i, j, tmp;

    printf("\n Enter Array Element");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i <= 4; i++)
    {
        printf("%d address of %d\n", &a[i], a[i]);
    }
    i = 0;
    j = 4;
    while (i < j)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    printf("\n Inverse of Array is :\n");
    for (i = 0; i <= 4; i++)
    {
        printf("Now %d address of %d\n", &a[i], a[i]);
    }

    return 0;
}