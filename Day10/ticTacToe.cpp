#include <bits/stdc++.h>

using namespace std;

void upperIndex(int n)
{
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}
void middleLine(int n)
{
    cout << endl
         << "  ";
    for (int j = 0; j < n; j++)
    {
        cout << char(205);
        if (j == n - 1)
        {
            continue;
        }
        cout << char(206);
    }
    cout << endl;
}

// print
void design(char playMatrix[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        for (int j = 0; j < n; j++)
        {
            cout << playMatrix[i][j];
            if (j == n - 1)
            {
                continue;
            }
            cout << char(186);
        }
        if (i == n - 1)
        {
            continue;
        }
        middleLine(n);
    }
}
void displayMatrix(char playMatrix[][3], int n)
{
    upperIndex(n);
    design(playMatrix, n);
}

bool vertical(char playMatrix[][3], int size, char input, int r, int c)
{
    int i = 0;
    bool flag = true;
    while (i < size)
    {
        if (playMatrix[(r + i) % size][c] != input)
        {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

bool horizontal(char playMatrix[][3], int size, char input, int r, int c)
{
    int i = 0;
    bool flag = true;
    while (i < size)
    {
        if (playMatrix[r][(c + i) % size] != input)
        {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

bool diagonal(char playMatrix[][3], int size, char input, int r, int c)
{
    if ((r != c) && (r + c != size - 1))
    {
        return false;
    }
    int flag1, flag2 = true;
    int i = 0;
    while (i < size)
    {
        if (playMatrix[(r + i) % size][(c + i) % size] != input)
        {
            flag1 = false;
        }
        if (playMatrix[(r + size - i) % size][(c + i) % size] != input)
        {
            flag2 = false;
        }

        i++;
    }
    return (flag1 || flag2);
}

bool evaluate(char playMatrix[][3], int size, char input, int r, int c)
{
    return (vertical(playMatrix, size, input, r, c) || horizontal(playMatrix, size, input, r, c) || diagonal(playMatrix, size, input, r, c));
}
int getInput(char playMatrix[][3], int size, int *index, int *count)
{
    char XO[] = {'X', 'O'};
    int r, c;
    cout << endl
         << "Enter the row and column for " << XO[*index] << " :";
    cin >> r >> c;
    char ip = XO[*index];
    if (playMatrix[r][c] == ' ')
    {
        playMatrix[r][c] = XO[*index];
        (*index) ^= 1;
        (*count)++;
    }
    if (evaluate(playMatrix, size, ip, r, c))
    {
        // system("cls");
        design(playMatrix, size);
        cout << "Congratulations " << ip;
        return 0;
    }
    if ((*count) == size * size)
    {
        // system("cls");
        design(playMatrix, size);
        cout << "Match draw";
    }
    return 1;
}
int main()
{
    int size = 3, index, count = 0, flag;
    index = count = flag = 0;

    char playMatrix[][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    do
    {
        system("cls");

        design(playMatrix, size);
        flag = getInput(playMatrix, size, &index, &count);
    } while (flag);

    //   cout << evaluate(playMatrix, size, 'X', r, c);
    return 0;
}