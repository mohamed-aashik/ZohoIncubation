#include <stdio.h>

int main()
{
    int n = 4, m = 4, i, j, k = 0;
    int a[] = {1, 2, 3, 4}, b[] = {1, 4, 7, 10}, o[20] = {0};
    i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (k != 0)
            {
                if (o[k - 1] < a[i])
                    o[k++] = a[i++];
                else
                    i++;
            }
            else
            {
                o[k++] = a[i++];
            }
        }
        else
        {
            if (k != 0)
            {
                if (o[k - 1] < b[j])
                    o[k++] = b[j++];
                else
                    j++;
            }
            else
            {
                o[k++] = b[j++];
            }
        }
    }
    while (i < n)
        o[k++] = a[i++];
    while (j < m)
        o[k++] = b[j++];
    i = 0;
    while (o[i])
    {
        printf("%d ", o[i++]);
    }
}