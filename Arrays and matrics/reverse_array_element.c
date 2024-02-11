/* Reverse the order of elements*/
/* Data Structures Using C by Shoriful Shine */

 
#include <stdio.h>
int main ( )
{
int a[5], i;
printf ("\n enter the elements");
for (i=0; i<=4; i++)
scanf ("\n %d", &a[i]);
printf ("\n Reverse order of array is \n");
for (i=4; i>=0; i--)
printf ("\n %d", a[i]);
return 0;
}