#include <stdio.h>
#include <string.h>

void method1(char *s, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", s);

        char t = s[0];
        for (j = 0; j < n - 1; j++)
        {
            s[j] = s[j + 1];
        }
        s[n - 1] = t;
    }
}

void method2(char *s, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < i + n; j++)
        {
            printf("%c", s[j % n]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    char s[100];
    scanf("%s", s);
    n = strlen(s);
    method1(s, n);
    //without changing elements position
    method2(s, n);

    return 0;
}