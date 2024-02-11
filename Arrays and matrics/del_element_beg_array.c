/* Deletion at beginning */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
#include <stdlib.h>
#define max 20
int main()
{

    int a[max], i, j;
    printf("\n Enter limit");
    scanf("%d", &j);
    if (j >= max)
    {
        printf("\n Array size doesn't exit");
        exit(0);
    }
    printf("\n Input elements of array");
    for (i = 0; i < j; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Elements of array after deletion at beginning:\n");
    for (i = 0; i <= j - 2; i++)
    {
        a[i] = a[i + 1];
        printf("%d,", a[i]);
    }
    j--;
    return 0;
}
