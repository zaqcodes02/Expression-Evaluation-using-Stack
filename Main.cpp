#include "Stack.h"
using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string conversion(string expression)
{
    Stack<char> s;
    string result;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            result += c;
        }

        else if (c == '(')
        {
            s.push(c);
        }

        else if (c == ')')
        {
            while (s.getTop() != '(')
            {
                result += s.getTop();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.isEmpty() && precedence(c) < precedence(s.getTop()) ||
                   !s.isEmpty() && precedence(c) == precedence(s.getTop()))
            {
                result += s.getTop();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        result += s.getTop();
        s.pop();
    }
    return result;
}

int postfixEvaluation(string expression)
{
    int i = 0;
    Stack<int> stack;
    while (expression[i] != '\0')
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            stack.push(expression[i] - '0');
            i++;
        }
        else
        {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            if (expression[i] == '+')
            {
                stack.push(operand1 + operand2);
            }
            else if (expression[i] == '-')
            {
                stack.push(operand1 - operand2);
            }
            else if (expression[i] == '*')
            {
                stack.push(operand1 * operand2);
            }
            else if (expression[i] == '/')
            {
                stack.push(operand1 / operand2);
            }
            else
            {
                int result = 1;
                for (int i = 0; i < operand2; i++)
                {
                    result *= operand1;
                }
                stack.push(result);
            }
            i++;
        }
    }
    return stack.getTop();
}

int main()
{
    string exp = "3+5*(2-8)";
    int ch = 0, answer;
    string postfixExp;
    do
    {
        cout << "1. Infix to Postfix Cinversion" << endl;
        cout << "2. Infix to Postfix Evaluation" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice:" << endl;
        cin >> ch;
        if (ch == 1)
        {
            postfixExp = conversion(exp);
            cout << "Expression: " << postfixExp << endl;
        }
        else if (ch == 2)
        {
            answer = postfixEvaluation(postfixExp);
            cout << "Evaluation: " << answer << endl;
        }
        cout << "Exit? ";
        cin >> ch;
    } while (ch != 3);

    return 0;
}