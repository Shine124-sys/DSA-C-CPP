/* Comparing Two Strings */
/* Data Structures Using C by Shoriful Shine */
#include <stdio.h>

#include <stdlib.h>

int main()
{
   char *c1, *c2, str1[10], str2[10];

   printf("Enter the string no 1:\n");
   scanf("%s", str1);
   printf("Enter the string no 2:\n");
   scanf("%s", str2);
   c1 = str1;
   c2 = str2;
   while (*c1 == *c2 && *c1 != '\0' && *c2 != '\0')
   {
      *c1 = *c1 + 1;
      *c2 = *c2 + 1;
   }
   if (*c1 == '\0' && *c2 == '\0')
      printf("strings are equal\n");
   else
      printf("strings are not equal\n");
   return 0;
}
