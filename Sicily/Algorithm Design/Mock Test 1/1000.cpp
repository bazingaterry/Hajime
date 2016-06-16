#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (*s.begin() == '-')
    {
        cout << '-';
        s.erase(s.begin());
    }
    reverse(s.begin(), s.end());
    while (*s.begin() == '0')
        s.erase(s.begin());
    if (s == "")
        cout << 0 << endl;
    else
        cout << s << endl;
    return 0;
}
