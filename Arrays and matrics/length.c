/* Find length of string */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>
 
#define MAXSIZE 100
int main()
{
    int len = 0;
    char *p, str[MAXSIZE];

    printf("enter the string: \n");
    scanf("%s", str);
    p = str;
    while (*p != '\0')
    {
        p = p + 1;
        len = len + 1;
    }
    printf("The length of the string is %d", len);
    return 0;
}
