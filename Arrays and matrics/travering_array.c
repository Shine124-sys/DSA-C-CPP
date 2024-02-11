/* Traversing of the array */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
int main ( )
{
int n, i, a[20];

printf ("Enter the length of array");
scanf ("%d", &n);
printf ("Enter the elements\n");
for (i=0; i<= n-1; i++)
{
scanf ("%d", &a[i]);
}
printf ("Traversing of the array: \n");
for (i = 0; i<= n-1; i++)
{
printf ("\n%d",a[i]);
}
return 0;
}