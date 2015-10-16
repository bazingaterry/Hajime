#include "iostream"
#include "string"
#include "stack"
using namespace std;

bool isMatch(char c1, char c2)
{
    if (c1 == '(' && c2 ==')')
        return true;
    if (c1 == '[' && c2 ==']')
        return true;
    if (c1 == '{' && c2 =='}')
        return true;
    return false;
}

bool check(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (s.empty() || !isMatch(s.top(), str[i]))
            {
                return false;
            }
            s.pop();
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (check(str))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}                                 