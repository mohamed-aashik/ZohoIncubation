#include <stdio.h>

int getNearFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int n1 = 0, n2 = 1, n3 = n1 + n2;
    while (n3 <= n)
    {
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
    }
    return n2;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        int nf = getNearFibonacci(n);
        printf("%d ", nf);
        n = n - nf;
    }

    return 0;
}