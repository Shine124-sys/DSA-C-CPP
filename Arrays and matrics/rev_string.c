/* Reverse a string */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
#include <stdlib.h>
int main()
{
   char *str1;
   char *ptr1, *ptr2, temp;
   printf("Enter the string:\n");
   scanf("%s", str1);
   ptr1 = str1;
   ptr2 = str1;
   while (*ptr2 != '\0')
      ptr2++;
   ptr2--;
   while (ptr1 < ptr2)
   {
      temp = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = temp;
      ptr1++;
      ptr2--;
   }
   puts(ptr1);
   return 0;
}
