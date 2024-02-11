/* Sum of the diagonal elements*/
/* Data Structures Using C by  Shoriful Shine */

#include <stdio.h>
int main()
{
    int a[5][5], sum, r, c;
    sum = 0;
    printf("Enter row and column of matrix is");
    scanf("%d %d", &r, &c);
    printf("Enter elements \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
            if (i == j)
                sum = sum + a[i][j];
        }
    }
    printf("The sum of the diagonal elements = %d", sum);
    return 0;
}
