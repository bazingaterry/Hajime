#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        int ch[101], jp[101];
        for (int i = 0; i < n; ++i)
            cin >> ch[i]
        sort(ch, ch + n);
        for (int i = 0; i < n; ++i)
            cin >> jp[i]
        sort(jp, jp + n);
        int chScore = 0, jpScore = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ch[i] > jp[i])
                chScore += 2;
            else if (ch[i] == jp[i])
            {
                chScore++;
                jpScore++
            }
            else
                jpScore += 2;
        }
        cout << chScore << " vs " << jpScore << endl;
    }
}