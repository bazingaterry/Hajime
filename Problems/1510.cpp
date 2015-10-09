#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        string str;
        int location;
        cin >> location >> str;
        str.erase(location - 1, 1);
        cout << i << " " << str << endl;
    }
    return 0;
}