/* Update an element */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
int main ( )
{
int a[5], i, j, no;

printf ("\n enter the element");
for (i=0; i<=4; i++)
scanf ("%d", &a[i]);
printf ("\n enter position");
scanf ("%d", &j);
if (j<0 && j>4)
printf ("\n invalid position");
for (i=0; i<=4; i++)
{
if (i==j)
{
printf ("\n enter new element");
scanf ("%d", &no);
a[j]=no;
}
}
printf ("\n Now updated array are :\n ");
for (i=0; i<=4; i++)
printf("\n%d", a[i]);
     return 0;
}