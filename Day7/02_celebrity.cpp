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

int findCelebrity(int **arr, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        int colSum = 0, rowSum = 0;
        for (j = 0; j < size; j++)
        {
            rowSum += arr[i][j];
            colSum += arr[j][i];
        }
        // cout << rowSum << " " << colSum << endl;
        if (rowSum == 0 && colSum == (size - 1))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n = 4, **arr;
    arr = (int **)calloc(sizeof(int *), n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)calloc(sizeof(int), n);
    }
    arr[0][2] = 1;
    arr[1][2] = 1;
    arr[3][2] = 1;

    cout << findCelebrity(arr, n);

    return 0;
}
