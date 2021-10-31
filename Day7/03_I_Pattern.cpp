#include <iostream>
using namespace std;

void printArray(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setDefault(int **arr, int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = val;
        }
    }
}

int findICount(int **arr, int size)
{
    int i, j, count = 0;
    for (i = 0; i < size - 2; i++)
    {
        for (j = 0; j < size - 2; j++)
        {
            if (arr[i][j] && arr[i][j + 1] && arr[i][j + 2] && arr[i + 1][j + 1] && arr[i + 2][j] && arr[i + 2][j + 1] && arr[i + 2][j + 2])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n = 4, **arr;
    arr = (int **)calloc(sizeof(int *), n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)calloc(sizeof(int), n);
    }
    setDefault(arr, n, 1);
    arr[1][3] = 0;
    arr[2][3] = 0;
    // printArray(arr, n);
    cout << findICount(arr, n);
    return 0;
}