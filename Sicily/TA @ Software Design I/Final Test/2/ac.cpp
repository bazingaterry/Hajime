#include "iostream"
using namespace std;

int path[110][2];
int n;

int shortestPath(int i)
{
    if (i == n)
        return 1;
    else if (i == 0)
        return 111;
    else
        return 1 + min(shortestPath(path[i][0]), shortestPath(path[i][1]));
}

int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        for (int j = 1; j <= n; ++j)
        {    
            int i;
            cin >> i;
            cin >> path[i][0] >> path[i][1];
        }
        cout << shortestPath(1) << endl;
    }
    return 0;
}