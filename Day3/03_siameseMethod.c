#include <stdio.h>
#include <string.h>

void ap(int *p, int diff)
{
    *p = (*p) + diff;
}
int main()
{
    int n, val, diff;
    printf("Enter the n value:");
    scanf("%d", &n);
    printf("Enter the start number and difference:");
    scanf("%d %d", &val, &diff);
    if (n % 2 == 0)
    {
        printf("Invalid input.");
        return 0;
    }
    int arr[n][n];
    //allocate default zeros
    memset(arr, 0, sizeof(arr));
    //code
    int i = 0, j = (n - 1) / 2;
    arr[i][j] = val;
    ap(&val, diff);
    for (int k = 0; k < (n * n) - 1; k++)
    {
        int r = (i + n - 1) % n, c = (j + 1) % n;
        if (!arr[r][c])
        {
            arr[r][c] = val;
            ap(&val, diff);
            i = r;
            j = c;
        }
        else
        {
            arr[(i + 1) % n][j] = val;
            ap(&val, diff);
            i = (i + 1) % n;
        }
    }

    //end

    //print array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}