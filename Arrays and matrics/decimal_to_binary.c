/* Convert decimal number to binary equivalent */
/* Data Structures Using C by Shoriful Shine */

#include <stdio.h>

int main()
{

    int d, b[20], i, j;
    printf("\n Input Decimal No: \n");
    scanf("%d", &d);
    i = 0;
    while (d > 0)
    {
        b[i] = d % 2;
        d = d / 2;
        i++;
    }
    printf("Binary Equivalent:\n");
    for (j = i - 1; j >= 0; --j)
        printf("%d", b[j]);
    return 0;
}
