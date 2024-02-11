/* Find Maximum and second maximum */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
 
#include <stdlib.h>
int main()
{
    int n, a[20], max = 0, Smax = 0, i, temp, loc;

    printf("\n Enter the size of array");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("Size is not valid");
       
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n enter the elements %d :", i + 1);
        scanf("%d", &a[i]);
    }
    /* Find out the maximum no. */
    for (i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
        loc = i;
    }
    /* Interchange the maximum no. & last position */
    if (loc != n - 1)
    {
        temp = a[loc];
        a[loc] = a[n - 1];
        a[n - 1] = temp;
    }
    for (i = 0; i < n - 2; i++)
    {
        if (Smax < a[i])
            Smax = a[i];
    }
    printf("\n the maximum no. is %d", max);
    printf("\n the second maximum no. is %d", Smax);
    return 0;
}