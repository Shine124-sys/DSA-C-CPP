/* Interchange odd and even position element */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[20], temp, i, j;

    printf("\n Enter the size");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("\n Invalid size :");
       
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the numbers");
        scanf("%d", &a[i]);
    }
    /* Print the values of different subscripts */
    for (i = 0; i < n; i++)
        printf("\na[%d]=%d", i, a[i]);
    for (j = 0; j < n - 1; j = j + 2)
    {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
    }
    printf("\n after interchanging");
    printf("\n");
    for (i = 0; i < n; i++)
        printf("\n a[%d] = %d", i, a[i]);
    return 0;
}