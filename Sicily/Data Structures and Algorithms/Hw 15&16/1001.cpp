#include "iostream"
#include "queue"
#include "cstring"
using namespace std;

const int SIZE = 1010;

bool path[SIZE][SIZE];
bool flag[SIZE];
int n;
int cnt = 0;

inline void bfs(int i)
{
    queue<int> q;
    flag[i] = true;
    q.push(i);
    cnt++;
    while(!q.empty())
    {
        int i = q.front();
        for (int j = 1; j <= n; ++j)
        {
            if (path[i][j] && !flag[j])
            {
                flag[j] = true;
                q.push(j);
            }
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> n >> m;
    memset(path, false, sizeof(path));
    memset(flag, false, sizeof(flag));
    while (m--)
    {
        int v, y;
        cin >> v >> y;
        path[v][y] = true;
        path[y][v] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!flag[i]) bfs(i);
    cout << cnt << endl;
    return 0;
}
