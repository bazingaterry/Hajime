#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--)
    {
        int o;
        cin >> o;
        if (o < 0)
            cout << o << ": logic error\n";
        else if (o == 0)
            cout << o << ": runtime error\n";
        else if (o > 10)
            cout << o << ": out of range error\n";
    }
    return 0;
}