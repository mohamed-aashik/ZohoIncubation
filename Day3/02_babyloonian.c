#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("%d", n);
        return 0;
    }
    float prev = 1;
    while (prev * prev < n)
    {
        prev++;
    }
    float current = (prev + (float)n / prev) / 2;
    while (prev != current)
    {
        prev = current;
        current = (prev + (float)n / prev) / 2;
    }
    printf("%f", current);
    return 0;
}