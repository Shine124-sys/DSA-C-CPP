/* Program of two dimension array */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
int main()
{
    int a[4][4], i, j;

    printf("Enter the elements:\n");
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nElements of 2D array are :\n");
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
