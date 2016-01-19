#include "stack"
#include "iostream"
#include "string"

using namespace std;

inline bool isChar(char ch)
{
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

inline bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

inline bool isBrackets(char ch)
{
    return (ch == '(' || ch == ')');
}

string infix2postfix (string str)
{
    string result;
    stack<char> s;
    for (int i = 0; i < str.size(); ++i)
    {
        if (isChar(str[i]))
        {
            result += str[i];
        }
        else if (isOperator(str[i]))
        {
            if (str[i] == '*' || str[i] =='/')
            {
                s.push(str[i]);
            }
            else if (str[i] == '+' || str[i] =='-')
            {
                while (!s.empty() && !(s.top() == '('))
                {
                    result += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        else if (isBrackets(str[i]))
        {
            if (str[i] == '(')
            {
                s.push('(');
            }
            else if (str[i] == ')')
            {
                while (s.top() != '(')
                {
                    result += s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        cout << infix2postfix(str) << endl;
    }
    return 0;
}