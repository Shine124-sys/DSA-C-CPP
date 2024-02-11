/*Insertion at last position */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
#include <stdlib.h>
#define max 20
int main()
{

    int a[max], i, j, n;
    printf("\n Enter limit");
    scanf("%d", &j);
    if (j >= max)
    {
        printf("\n size of limit doesn't match");
        exit(0);
    }
    printf("\n Enter new element");
    for (i = 0; i < j; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Enter Element");
    scanf("%d", &n);
    a[j] = n;
    printf("\n Array after insertion at end is:\n");
    for (i = 0; i <= j; i++)
        printf("%d ,", a[i]);
    return 0;
}
