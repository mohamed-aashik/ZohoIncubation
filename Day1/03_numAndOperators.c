#include <stdio.h>

int main()
{
    char s[100] = "12345*+-+";
    int st = 0, o = 0, res = 0;
    // scanf("%s", s);

    while (s[o] >= 48 && s[o] <= 57)
    {
        o++;
    }
    res = s[st] - '0';
    st++;
    while (s[o] != '\0')
    {
        switch (s[o])
        {
        case '+':
            res += (s[st++] - '0');
            break;
        case '-':
            res -= (s[st++] - '0');
            break;
        case '*':
            res *= (s[st++] - '0');

            break;
        case '/':
            res /= (s[st++] - '0');
            break;
        }
        o++;
    }
    printf("%d", res);
    return 0;
}