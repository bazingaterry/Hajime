// Problem#: 15183
// Submission#: 3885791
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "iostream"
#include "string"
#include "stack"
#include "iomanip"
using namespace std;

double calculator(double d1, double d2, char o)
{
    if (o == '+')
    {
        return d1 + d2;
    }
    else if (o == '-')
    {
        return d1 - d2;
    }
    else if (o == '*')
    {
        return d1 * d2;
    }
    else
    {
        return d1 / d2;
    }
}

double postCal(string str)
{
    stack<double> s;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            s.push(str[i] - 'a' + 1);
        }
        else
        {
            double d1 = s.top();
            s.pop();
            double d2 = s.top();
            s.pop();
            s.push(calculator(d1, d2, str[i]));
        }
    }
    return s.top();
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        cout << fixed << setprecision(2) << postCal(str) << endl;
    }
    return 0;
}                                 