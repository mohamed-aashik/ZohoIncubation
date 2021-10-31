#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define HASHMAX 26

int getCommand(char *input, char *cmd)
{
    int i = 0;
    while (input[i] != '\0' && input[i] != ' ')
    {
        cmd[i] = input[i];
        i++;
    }
    cmd[i] = '\0';
    return i;
}

int add(int *hashmap, char *s, int i)
{
    i++;
    char a, b;
}

int start(int *prevHash)
{
    int hashmap[26];
    do
    {
        char input[MAX], cmd[MAX];
        scanf("%[^\n]%*c", input);
        int size;
        size = getCommand(input, cmd);
        if (!strcmp(cmd, "PRINT"))
        {
            printf("print");
        }
        else if (!strcmp(cmd, "ADD"))
        {
            printf("Add");
        }
        else if (!strcmp(cmd, "SUB"))
        {
            printf("Sub");
        }
        else if (!strcmp(cmd, "RB"))
        {
            printf("RB");
            return 1;
        }
        else if (!strcmp(cmd, "COMMIT"))
        {
            printf("Commit");
            return 2;
        }
        else if (!strcmp(cmd, "END"))
        {
            return 3;
        }
        else if (!strcmp(cmd, "BEGIN"))
        {
            int ch = start();
            if (ch == 2)
            {
                // commit
                return 2;
            }
            else if (ch == 3)
            {
                return 3;
            }
        }

    } while (1);
}

int main()
{
    char s[MAX];
    int hash[HASHMAX] = {0};
    scanf("%[^\n]%*c", s);
    if (!strcmp(s, "BEGIN"))
    {
        start(hash);
    }
    else
    {
        printf("Wrong input");
    }
    return 0;
}