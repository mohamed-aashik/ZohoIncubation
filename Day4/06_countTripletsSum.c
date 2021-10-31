#include <stdio.h>

int main()
{
    int n = 5, sum = 12, count = 0;
    int a[] = {5, 1, 3, 4, 7};
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((a[i] + a[j] + a[k]) < sum)
                {
                    printf("(%d,%d,%d)\n", a[i], a[j], a[k]);
                    count++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}