/* Deletion at last */
/* Data Structures Using C by Shoriful Shine */
#include <stdio.h>
#include <stdlib.h>
#define max 20
int main ( )
{
int a[max], i, j ;

printf ("\n Enter limit");
scanf ("%d", &j);
if (j>=max)
{
printf ("\n size not exit");
exit (0);
}
printf ("\n Enter Elements of Array:\n");
for (i = 0; i<j; i++)
{
scanf ("%d", &a[i]);
}
j--;
printf ("\n Array Elements after deletion at end :\n");
for (i=0; i <j; i++)
{
printf ("%d ", a[i]);
}
return 0;
}
