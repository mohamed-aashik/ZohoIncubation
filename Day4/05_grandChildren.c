#include <stdio.h>
#include <string.h>
int count = 0;
void fun(char s[][2][10], char str[10], int n, int size)
{
    if (n == 0)
        return;
    int j = 1;
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(s[i][j], str))
        {
            printf("%s\n", s[i][j]);
            if (n == 1)
            {
                count += 1;
            }
            else
            {
                fun(s, s[i][0], n - 1, size);
            }
        }
    }
}
int main()
{
    char s[4][2][10] = {
        "luke", "shaw",
        "wayne", "rooney",
        "rooney", "ronaldo",
        "shaw", "rooney"};
    fun(s, "ronaldo", 3, 4);
    printf("%d", count);
    return 0;
}