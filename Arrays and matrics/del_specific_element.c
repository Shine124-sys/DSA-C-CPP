/*Deletion of specific element */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
#include <stdlib.h>
#define max 20
int main()
{
    int a[max], k, i, j, n;

    printf("\n Enter Limit:");
    scanf("%d", &j);
    if (j > max)
    {
        printf("\n Array size doesn't exist");
        exit(0);
    }
    printf("\n Enter Elements in Array:\n");
    for (i = 0; i < j; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Enter element which you want to delete:\n ");
    scanf("%d", &n);
    for (i = 0; i < j; i++)
    {
        if (n == a[i])
        {
            for (k = i; k <= j - 2; k++)
            {
                a[k] = a[k + 1];
            }
            j--;
        }
    }
    printf("\n Array Elements after elements are :\n");
    for (i = 0; i < j; i++)
    {
        printf("%d ", a[i]);
        
    }
    return 0;
}