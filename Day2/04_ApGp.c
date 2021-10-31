#include <stdio.h>
#include <math.h>

int ap(int start, int end, int n)
{
    int diff;
    diff = abs(end - start);
    n = (diff * n) - start;
    return n;
}
int gp(int start, int end, int n)
{
    int diff;
    diff = end / start;
    n = start * (int)pow(diff, n - 1);

    return n;
}
int main()
{
    int start, end, n, choice, total;
    printf("Enter the start and end: ");
    scanf("%d %d", &start, &end);
    printf("Enter the n value: ");
    scanf("%d", &n);
    printf("Enter your choice:");
    scanf("%d", &choice);
    total = ap(start, end, n) * (!choice) + gp(start, end, n) * choice;
    printf("\n%d", total);

    return 0;
}