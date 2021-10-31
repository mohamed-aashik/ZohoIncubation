#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int i, j;
    string prev = "1", op = "";
    cout << prev << endl;
    for (i = 1; i < n; i++)
    {
        j = 0;
        while (prev[j])
        {
            int count = 0;
            char c = prev[j];
            while (prev[j] == c)
            {
                count++;
                j++;
            }
            op += (char)(count + 48);
            op += c;
        }
        prev = op;
        op = "";
        cout << prev << endl;
    }

    return 0;
}
