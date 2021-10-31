#include <stdio.h>

int isFound(int *a, int n, int key)
{
    int flag = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void union_of(int *a, int *b, int a_len, int b_len)
{

    int i;
    for (i = 0; i < a_len; i++)
    {
        printf("%d ", a[i]);
    }
    for (i = 0; i < b_len; i++)
    {
        if (!isFound(a, a_len, b[i]))
        {
            printf("%d ", b[i]);
        }
    }
}

void intersection_of(int *a, int *b, int a_len, int b_len)
{
    int i;
    for (i = 0; i < a_len; i++)
    {
        if (isFound(b, b_len, a[i]))
        {
            printf("%d ", a[i]);
        }
    }
}
void subtraction_of(int *a, int *b, int a_len, int b_len)
{
    int i;
    for (i = 0; i < a_len; i++)
    {
        if (!isFound(b, b_len, a[i]))
        {
            printf("%d ", a[i]);
        }
    }
}

void rotation_of(int *a, int a_len, int rotation)
{
    int i, start = a_len - rotation;
    for (i = 0; i < a_len; i++)
    {
        printf("%d ", a[start++ % a_len]);
    }
}
int main()
{
    int a_len, b_len, i;
    printf("Enter the size of a and b:");
    scanf("%d %d", &a_len, &b_len);
    int a[a_len], b[b_len];
    printf("Enter the elements of a:");
    for (i = 0; i < a_len; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements of b:");
    for (i = 0; i < b_len; i++)
    {
        scanf("%d", &b[i]);
    }

    union_of(a, b, a_len, b_len);
    printf("\n");
    intersection_of(a, b, a_len, b_len);
    printf("\n");
    subtraction_of(a, b, a_len, b_len);
    printf("\n");
    subtraction_of(b, a, b_len, a_len);
    printf("\n");
    rotation_of(a, a_len, 2);
    printf("\n");
    rotation_of(b, b_len, 2);

    return 0;
}