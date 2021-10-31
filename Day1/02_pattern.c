#include <stdio.h>

int main()
{
    int n, var, dec, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        dec = n - 1;
        var = i;
        for (j = 1; j <= i; j++)
        {
            printf("%d ", var);
            var = var + (dec--);
        }
        printf("\n");
    }
    return 0;
}