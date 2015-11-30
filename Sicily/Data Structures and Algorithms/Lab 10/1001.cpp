#include "cstdio"
#include "string"
using namespace std;

int n;
bool isSelected[10];

void dfs(int location, string str)
{
    if (location == str.size() - 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!isSelected[i])
            {
                str[location] = i + '0';
                printf("%s\n", str.c_str());
                return;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!isSelected[i])
            {
                str[location] = i + '0';
                isSelected[i] = true;
                dfs(location + 2, str);
                isSelected[i] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    string result;
    result.resize(2 * n - 1, ' ');
    dfs(0, result);
    return 0;
}