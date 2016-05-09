#include "string"
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    while (cin >> input && input != "0")
    {
        cout << input << ": ";
        int result = 0;
        int base = 1;
        for (int i = input.size() - 1; i >= 0; i--)
        {
            if (input[i] > '4') input[i]--;
            result += (input[i] - '0') * base;
            base *= 9;
        }
        cout << result << endl;
    }
    return 0;
}
