#include <bits/stdc++.h>
using namespace std;

void make_blast(int **arr, int **brr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (brr[i][j] == -1)
            {
                _beep(1000, 250);
                cout << setw(10) << (char)157;
            }
            else
            {
                if (arr[i][j] == -2)
                {
                    cout << setw(10) << (char)254;
                }
                else
                {
                    cout << setw(10) << arr[i][j];
                }
            }
        }
        cout << endl;
    }
}
int isFound(int size, int i, int j)
{
    return (i >= 0 && i < size) && (j >= 0 && j < size);
}

void printArray(int **arr, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        cout << "------------------------------" << endl
             << "|";
        for (j = 0; j < size; j++)
        {
            if (arr[i][j] == -2)
            {
                cout << setw(3) << (char)254
                     << " | ";
            }
            else if (arr[i][j] == -1)
            {
                cout << setw(3) << "f"
                     << " | ";
            }
            else
            {
                cout << setw(3) << arr[i][j] << " | ";
            }
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

int getCount(int **arr, int n, int iInd, int jInd)
{
    int count = 0, i, j;
    for (i = iInd - 1; i < (iInd + 2); i++)
    {
        for (j = jInd - 1; j < (jInd + 2); j++)
        {
            if (isFound(n, i, j))
            {
                if (arr[i][j] == -1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int validArray(int **a, int **b, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int play(int **playArray, int **answerArray, int size)
{
    system("cls");
    printArray(playArray, size);
    int r, c, flag = 0;
    cout << "Enter row and column and flag:";
    cin >> r >> c >> flag;

    if (isFound(size, r, c))
    {
        if (!flag)
        {
            if (answerArray[r][c] != -1)
            {
                playArray[r][c] = answerArray[r][c];
            }
            else
            {

                system("cls");
                make_blast(playArray, answerArray, size);
                return 0;
            }
        }
        else
        {

            if (playArray[r][c] == -1)
            {
                playArray[r][c] = -2;
            }
            else if (playArray[r][c] == -2)
            {
                playArray[r][c] = -1;
            }
        }
    }
    else
    {
        cout << "Wrong input!";
    }
    if (validArray(playArray, answerArray, size))
    {
        cout << "Congratulations..";
        return 0;
    }
    return 1;
}

void initOpen(int **playArray, int **answerArray, int size, int a, int b)
{
    int i, j;
    for (i = a - 1; i <= a + 1; i++)
    {
        for (j = b - 1; j <= b + 1; j++)
        {
            if (isFound(size, i, j) && answerArray[i][j] != -1)
            {
                playArray[i][j] = answerArray[i][j];
            }
        }
    }
}

void setDefault(int **arr, int size, int num)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arr[i][j] = num;
        }
    }
}

void printMatrix(int *arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            cout << setw(10) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setgame(int **arr, int size)
{
    srand(time(0));
    int times = size, i, j;
    for (i = 0; i < times; i++)
    {
        int x = rand() % size;
        int y = rand() % size;
        if (arr[x][y] == -1)
        {
            times++;
            continue;
        }
        arr[x][y] = -1;
    }
    int count = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (arr[i][j] != -1)
            {
                count = getCount(arr, size, i, j);
                arr[i][j] = count;
            }
        }
    }
    printMatrix(arr, size);
}

int main()
{
    int n;
    cin >> n;
    int **answerArray, **playArray, i, j;
    // allocate memory
    answerArray = (int **)calloc(sizeof(int *), n);
    playArray = (int **)calloc(sizeof(int *), n);
    for (i = 0; i < n; i++)
    {
        answerArray[i] = (int *)calloc(sizeof(int), n);
        playArray[i] = (int *)calloc(sizeof(int), n);
    }
    // set values
    setgame(answerArray, n);
    // set -2
    setDefault(playArray, n, -2);
    int a = 0, b = 0;
    cout << "Enter start row and column:";
    cin >> a >> b;
    initOpen(playArray, answerArray, n, a, b);
    int choice;
    do
    {
        choice = play(playArray, answerArray, n);
    } while (choice);
    return 0;
}
