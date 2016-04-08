#include "string"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        int lcs[1001][1001] = {};
        for (int i = 1; i < s1.size(); ++i)
        {
            for (int j = 1; j < s2.size(); ++j)
            {
                if (s1[i] == s2[j])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        cout << lcs[s1.size() - 1][s2.size() - 1] << '\n';
    }
    return 0;
}
