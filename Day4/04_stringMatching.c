#include <stdio.h>

int main()
{
    int i, j, n = 5;
    int a[5][5] = {'w', 'e', 'l', 'c', 'o', 'm', 'e', 't', 'o', 'z', 'o', 'h', 'o', 'c', 'o', 'r', 'p', 'o', 'r', 'a', 't', 'i', 'o', 'n'};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 't')
            {
                if ((j + 2 < n) && (a[i][j + 1] == 'o' && a[i][j + 2] == 'o'))
                {
                    printf("Start at <%d,%d> and end at <%d,%d>\n", i, j, i, j + 2);
                }
                if ((i + 2 < n) && (a[i + 1][j] == 'o' && a[i + 2][j] == 'o'))
                {
                    printf("Start at <%d,%d> and end at <%d,%d>\n", i, j, i + 2, j);
                }
            }
            // printf("%c ", a[i][j]);
        }
    }
}