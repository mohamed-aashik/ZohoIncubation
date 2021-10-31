#include <bits/stdc++.h>

using namespace std;

// needed default function

int isFound(int size, int i, int j)
{
    return (i >= 0 && i < size) && (j >= 0 && j < size);
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

//--

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

void printArray(int **arr, int size)
{
    int i, j;
    cout << "      ";
    for (i = 0; i < size; i++)
    {
        cout << setw(3) << i << " ";
    }
    cout << endl
         << "      ";
    for (i = 0; i < size; i++)
    {
        cout << "  | ";
    }
    cout << endl;
    for (i = 0; i < size; i++)
    {
        cout << setw(3) << i << "-> ";
        for (j = 0; j < size; j++)
        {
            if (arr[i][j] == -2)
            {
                cout << setw(3) << (char)254
                     << " ";
            }
            else if (arr[i][j] == -1)
            {
                cout << setw(3) << "f"
                     << " ";
            }
            else
            {
                cout << setw(3) << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
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
void open(int **answerArray, int **playArray, int size, int r, int c)
{
    playArray[r][c] = answerArray[r][c];
    if (playArray[r][c] != 0)
    {
        return;
    }
    for (int i = r - 1; i <= r + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            if (isFound(size, i, j) && (playArray[i][j] == -2) && (answerArray[i][j] == 0))
            {
                open(answerArray, playArray, size, i, j);
            }
            else if (isFound(size, i, j) && (playArray[i][j] == -2) && (answerArray[i][j] != -1))
            {
                playArray[i][j] = answerArray[i][j];
            }
        }
    }
}

void countAdjacent(int **answerArray, int size)
{
    int count = 0, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (answerArray[i][j] != -1)
            {
                count = getCount(answerArray, size, i, j);
                answerArray[i][j] = count;
            }
        }
    }
}

void shuffle(int **answerArray, int size, int r, int c)
{
    int x, y, num = size;
    srand(time(0));
    while (num > 0)
    {
        x = rand() % size;
        y = rand() % size;
        if (isFound(size, x, y) && (answerArray[x][y] == 0) && ((x < r - 1 && y < c - 1) || (x > r + 1 && y > c + 1)))
        {
            answerArray[x][y] = -1;
            num--;
        }
    }
    countAdjacent(answerArray, size);
}

void init(int **answerArray, int **playArray, int size)
{
    int r, c;
    cout << "Enter the start row and column: ";
    cin >> r >> c;
    setDefault(playArray, size, -2);
    shuffle(answerArray, size, r, c);
    open(answerArray, playArray, size, r, c);
}

int play(int **answerArray, int **playArray, int size)
{
    system("cls");
    printArray(playArray, size);

    int r, c, flag = 0;
    cout << "Enter row , column and flag:";
    cin >> r >> c >> flag;
    if (isFound(size, r, c))
    {
        if (flag)
        {
            if (playArray[r][c] == -2)
            {
                playArray[r][c] = -1;
            }
            else if (playArray[r][c] == -1)
            {
                playArray[r][c] = -2;
            }
            else
            {
                _beep(1000, 250);
            }
        }
        else
        {

            if (playArray[r][c] != -1)
            {
                if (answerArray[r][c] == -1)
                {
                    system("cls");
                    make_blast(playArray, answerArray, size);
                    cout << "Wrong Answer";
                    return 0;
                }
                else
                {
                    open(answerArray, playArray, size, r, c);
                    //                    playArray[r][c] = answerArray[r][c];
                    //                    openSurroundZero(answerArray, playArray, size, r, c);
                }
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

int main()
{
    int size, choice, i, **answerArray, **playArray;
    cout << "1.Easy\n2.Medium\n3.Hard\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        size = 8;
        break;
    case 2:
        size = 14;
        break;
    case 3:
        size = 20;
        break;
    default:
        cout << "Wrong choice...!";
        return 0;
    }
    // allocate memory
    answerArray = (int **)calloc(sizeof(int *), size);
    playArray = (int **)calloc(sizeof(int *), size);
    for (i = 0; i < size; i++)
    {
        answerArray[i] = (int *)calloc(sizeof(int), size);
        playArray[i] = (int *)calloc(sizeof(int), size);
    }
    init(answerArray, playArray, size);

    printArray(answerArray, size);
    cout << "-- --" << endl;

    int run = 0;
    do
    {
        run = play(answerArray, playArray, size);
    } while (run);

    return 0;
}