#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int **a, int size)
{
    int i, j;
    printf("----------------------\n");
    for (i = 0; i < size; i++)
    {
        printf("|");
        for (j = 0; j < size; j++)
        {
            printf(" %3d ", a[i][j] % 16);
        }
        printf("|");

        printf("\n");
    }
    printf("----------------------\n");
}

int validArray(int **a, int size)
{
    int val = 1;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] != val++)
            {
                return 0;
            }
        }
    }
    return 1;
}

int isFound(int size, int i, int j)
{
    // if ((i >= 0 && i < size) && (j >= 0 && j < size))
    // {
    //     return 1;
    // }
    // return 0;
    return (i >= 0 && i < size) && (j >= 0 && j < size);
}

int toLeft(int **a, int size, int *i, int *j)
{
    if (isFound(size, *i, *j - 1))
    {
        a[*i][*j] = a[*i][*j - 1];
        a[*i][*j - 1] = size * size;
        *j -= 1;
        return 1;
    }
    return 0;
}

int toRight(int **a, int size, int *i, int *j)
{
    if (isFound(size, *i, *j + 1))
    {
        a[*i][*j] = a[*i][*j + 1];
        a[*i][*j + 1] = size * size;
        *j += 1;
        return 1;
    }
    return 0;
}

int toUp(int **a, int size, int *i, int *j)
{
    if (isFound(size, *i - 1, *j))
    {
        a[*i][*j] = a[*i - 1][*j];
        a[*i - 1][*j] = size * size;
        *i -= 1;
        return 1;
    }
    return 0;
}

int toDown(int **a, int size, int *i, int *j)
{
    if (isFound(size, *i + 1, *j))
    {
        a[*i][*j] = a[*i + 1][*j];
        a[*i + 1][*j] = size * size;
        *i += 1;
        return 1;
    }
    return 0;
}

int go(int **a, int direction, int size, int *i, int *j)
{
    int isGo = 0;
    switch (direction)
    {
    case 1:
        isGo = toLeft(a, size, i, j);
        break;
    case 2:
        isGo = toDown(a, size, i, j);
        break;
    case 3:
        isGo = toRight(a, size, i, j);
        break;
    case 4:
        isGo = toUp(a, size, i, j);
        break;
    }
    return isGo;
}

void play(int **a, int size, int *i, int *j)
{
    system("cls");
    printArray(a, size);
    if (validArray(a, size))
    {
        printf("\n\n Congratulations");
        return;
    }
    int direction = getch() - '0';
    if (direction == 5)
    {
        direction -= 1;
    }
    if (direction > 0 && direction <= 4)
    {
        if (!go(a, direction, size, i, j))
        {
            _beep(750, 250);
        };
        play(a, size, i, j);
    }
}

void shuffle(int **a, int size, int num, int *i, int *j)
{
    int prev = 0, current = 0;
    while (num > 0)
    {
        int flag = 0;
        current = (rand() % 4) + 1;
        printf("Random = %d  => ", current);
        if (abs(prev - current) == 2)
        {

            if (flag = go(a, (prev % size) + 1, size, i, j))
            {
                prev = (prev % size) + 1;
            }
            else
            {
                flag = go(a, (current % size) + 1, size, i, j);
                prev = (current % size) + 1;
            }
        }
        else
        {
            if (flag = go(a, current, size, i, j))
            {
                prev = current;
            }
            else
            {
                int temp = (current + size - 2) % size;
                flag = go(a, temp, size, i, j);
                prev = temp;
            }
        }
        if (flag)
        {
            num--;
        }
    }
}

int main()
{
    int size = 4, i, j, val = 1, cursor_i, cursor_j, type;
    int **a;
    a = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        a[i] = (int *)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[i][j] = val++;
        }
    }
    cursor_i = size - 1;
    cursor_j = size - 1;
    srand(time(0));
    printf("1.Easy\n2.Medium\n3.Hard\nEnter your choice:");
    type = getch() - '0';
    printf("\n");
    if (type > 3)
    {
        printf("Wrong choice");
        return 0;
    }

    shuffle(a, size, type * 4, &cursor_i, &cursor_j);
    play(a, size, &cursor_i, &cursor_j);
    return 0;
}
