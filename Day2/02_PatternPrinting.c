#include <stdio.h>
int main()
{
    int n, sum, i, j;
    n = 4; // scanf("%d", &n);
    printf("\n");
    sum = n * (n + 1) / 2;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", sum--);
        }
        printf("\n");
    }
    return 0;
}