#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

void horizontalLine(int value)
{
    while (value--)
    {
        cout << (char)205;
    }
}

void smallbox(string ip)
{

    cout << "  " << (char)201;
    char h = 205;
    horizontalLine(34);
    cout << (char)187 << endl
         << "  " << (char)186;

    cout << setw(34) << ip << (char)186 << endl
         << "  " << (char)200;

    horizontalLine(34);
    cout << (char)188;
}
void box(char *value)
{
    cout << "  ";
    for (int i = 0; i < 4; i++)
    {
        cout << "  " << (char)201;
        horizontalLine(3);
        cout << (char)187 << "  ";
    }
    cout << endl
         << "  ";
    for (int i = 0; i < 4; i++)
    {
        cout << "  " << (char)186 << " " << value[i] << " " << (char)186 << "  ";
    }
    cout << endl
         << "  ";
    for (int i = 0; i < 4; i++)
    {
        cout << "  " << (char)200;
        horizontalLine(3);
        cout << (char)188 << "  ";
    }
    cout << endl;
}
void valprint(void)
{
    char *value;
    value = "C<%/";
    box(value);
    value = "789x";
    box(value);
    value = "456-";
    box(value);
    value = "^0.=";
    box(value);
}
void printCalci(string ip, string op)
{
    smallbox(ip);
    cout << endl;
    smallbox(op);
    cout << endl
         << endl;
    valprint();
    cout << endl
         << "press q to exit" << endl;
}
// evaluate
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int performOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int isDigit(char c)
{
    return (c >= 48 && c <= 57);
}
int isOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    }
    return 0;
}

int evaluate(string expression, int length)
{
    int i;

    stack<int> values;

    stack<char> ops;

    for (i = 0; i < length; i++)
    {
        if (expression[i] == ' ')
            continue;

        else if (isDigit(expression[i]))
        {
            int val = 0;
            while (i < expression.length() &&
                   isDigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }

        else
        {
            while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(expression[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(performOperation(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(performOperation(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string ip = "";
    char c;
    do
    {
        system("cls");
        int length = ip.length();
        if (length && isDigit(ip[length - 1]))
        {
            printCalci(ip, to_string(evaluate(ip, length)));
        }
        else if (length)
        {
            printCalci(ip, to_string(evaluate(ip, length - 1)));
        }
        else
        {
            printCalci(ip, "0");
        }
        // input
        c = getch();
        if (isDigit(c))
        {
            ip += c;
        }
        else if (isOperator(c))
        {
            if (isOperator(ip[length - 1]))
            {
                ip[length - 1] = c;
            }
            else
            {
                ip += c;
            }
        }
        else if (c == 8 && length)
        {
            ip.pop_back();
        }
        else if (c == '=')
        {
            ip = to_string(evaluate(ip, length));
        }
    } while (c != 'q');
    return 0;
}