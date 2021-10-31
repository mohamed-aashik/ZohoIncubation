#include <iostream>

using namespace std;

int isNum(char c)
{
    if (c >= 48 && c <= 57)
    {
        return 1;
    }
    return 0;
}
int main()
{
    string word = "A1B2C3", op = "";
    int i = 0;

    while (word[i])
    {
        char c = word[i];
        int j = i + 1, num = 0;
        while (isNum(word[j]))
        {
            num = (num * 10) + (word[j] - '0');
            j++;
        }
        for (int k = 0; k < num; k++)
        {
            op += word[i];
        }
        i = j;
    }
    cout << op;

    return 0;
}