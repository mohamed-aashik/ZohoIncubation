#include <stdio.h>

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int len_1 = 4, len_2 = 5, i, min, max, len_3 = 0;
    int arr1[] = {1, 5, 10, 12}, arr2[] = {2, 4, 6, 8, 13}, *rem_arr;
    int arr3[100];
    if (len_1 < len_2)
    {
        min = len_1;
        max = len_2;
        rem_arr = arr2;
    }
    else
    {
        min = len_2;
        max = len_1;
        rem_arr = arr1;
    }
    for (i = 0; i < min; i++)
    {
        arr3[len_3++] = arr1[i];
        arr3[len_3++] = arr2[i];
    }
    if (len_1 < len_2)
    {
        arr3[len_3++] = 0;
    }
    for (i = min; i < max; i++)
    {
        arr3[len_3++] = rem_arr[i];
        arr3[len_3++] = 0;
    }
    if (len_1 < len_2)
    {
        len_3--;
    }
    printArray(arr3, len_3);
    return 0;
}