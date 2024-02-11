/* Program to find the sum of major diagonal elements of the 2D array */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
int main ( )
{

int a [5][5],i,j, sum,r,c;
sum = 0;
printf ("Enter no of rows and columns of matrix is: \n");
scanf ("%d %d", &r, &c);
printf ("Enter elements: \n");
for (i=0; i<r; i++)
{
for (j=0; j<c; j++)
{
scanf ("%d", &a[i][j]);
if (i==j)
sum = sum + a[i][j];
}
}
printf ("The sum of the major diagonal elements = %d", sum);
return 0;
}
