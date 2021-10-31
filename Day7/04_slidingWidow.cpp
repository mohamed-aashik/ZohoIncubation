#include <iostream>
using namespace std;

int countHashSize(int *hash)
{
    int size = 0;
    for (int i = 0; i < 10; i++)
    {
        if (hash[i])
        {
            size++;
        }
    }
    return size;
}
void printDistinct(int *arr, int size, int k)
{
    int hash[10] = {0}, i;
    for (i = 0; i < k; i++)
    {
        hash[arr[i]]++;
    }
    for (i = k; i < size; i++)
    {
    }
}

int main()
{
    int n = 7, k = 4;
    int arr[] = {1, 2, 1, 3, 4, 2, 3};

    return 0;
}