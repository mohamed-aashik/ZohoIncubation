#include <stdio.h>

struct out
{
    char vowel;
    int count;
};

int main()
{
    char input[] = "ZOHO CORPORATION";
    int index = 0, size = 0;
    struct out output[5];
    for (int i = 0; i < 5; i++)
    {
        // output[i].vowel = 0;
        output[i].count = 0;
    }

    while (input[index] != '\0')
    {
        int flag = 1;
        switch (input[index])
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            for (int i = 0; i < index; i++)
            {
                if (output[i].vowel == input[index])
                {
                    output[i].count++;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                output[size].vowel = input[index];
                output[size].count++;
                size++;
            }
            break;
        }
        index++;
    }

    // print
    for (int i = 0; i < size; i++)
    {
        printf("%c%d\n", output[i].vowel, output[i].count);
    }

    return 0;
}