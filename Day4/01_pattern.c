// #include <stdio.h>

// int main()
// {
//     int n, i, j, val = 1;
//     scanf("%d", &n);

//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= n; j++)
//         {
//             if (i % 2 == 0)
//             {
//                 printf("%d ", val--);
//             }
//             else
//             {
//                 printf("%d ", val++);
//             }
//         }
//         if (i % 2 == 0)
//         {
//             val += (n + 1);
//         }
//         else
//         {
//             val += (n - 1);
//         }
//         printf("\n");
//     }
// }

//code 2

#include <stdio.h>

int main()
{
    int n, i, j, val = 1, diff = 1;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", val);
            val += diff;
        }
        diff *= -1;
        val += (n + diff);
        printf("\n");
    }
}
