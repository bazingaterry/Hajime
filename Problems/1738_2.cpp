#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char ch[10][10];
    for (int i = 0; i < n; ++i)
    {
        cin >> ch[i];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%c", ch[j][i]);
        }
        cout << endl;
    }
    return 0;
}