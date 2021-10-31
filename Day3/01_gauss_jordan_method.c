#include <stdio.h>

void solution(int a[20][20], int var)
{
    int x, val;
    for (x = 0; x < var; x++)
    {
        for (int i = 0; i <= var; i++)
        {
            val = a[i][x];
            for (int j = 0; j <= var; j++)
            {
                if (i != x)
                {
                    a[i][j] = (a[x][x] * a[i][j]) - (val * a[x][j]);
                }
            }
        }
    }

    printf("\nSolutions:\nThe Value of (x,y,z) is (");
    for (int i = 0; i < var; i++)
    {
        printf("%.1f,", (float)a[i][var] / (float)a[i][i]);
    }
    printf("\b).");
}

int main()
{

    int a[20][20], var, i, j, k, l, n;
    printf("\nEnter the number of variables:\n");
    scanf("%d", &var);

    for (i = 0; i < var; i++)
    {
        printf("\nEnter the equation%d:\n", i + 1);
        int varName = 'X';

        for (j = 0; j < var; j++)
        {
            printf("Enter the coefficient of  %c%d:\n", varName++, i + 1);
            scanf("%d", &a[i][j]);
        }

        printf("\nEnter the constant:\n");
        scanf("%d", &a[i][var]);
    }

    solution(a, var);
    return 0;
}