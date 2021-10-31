#include <stdio.h>

struct hashmap
{
    int data;
    int count;
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printHashmap(struct hashmap *hm, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", hm[i].data, hm[i].count);
    }
}

int pop(struct hashmap *hm, int *size, int num)
{
    for (int i = 0; i < *size; i++)
    {
        if (hm[i].data == num)
        {
            if (hm[i].count == 1)
            {
                swap(&hm[i].data, &hm[*size].data);
                swap(&hm[i].count, &hm[*size].count);
                (*size)--;
                return 1;
            }
            else
            {
                hm[i].count -= 1;
            }
        }
    }

    return 1;
}

int push(struct hashmap *hm, int *size, int num)
{
    for (int i = 0; i < *size; i++)
    {
        if (hm[i].data == num)
        {
            hm[i].count += 1;
            return 0;
        }
    }
    hm[*size].data = num;
    hm[*size].count = 1;
    (*size)++;
    return 1;
}

int main()
{
    struct hashmap hm[10];
    int hm_size = 0;

    return 0;
}