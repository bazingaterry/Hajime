#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int SIZE = 1010;
const int EMPTY = 0;
const int BLACK = 1;
const int WHITE = -1;

int color[SIZE];
bool flag[SIZE];
vector<int> v[SIZE];
int n, m;
queue<int> q;

bool bfs()
{
    memset(color, 0, sizeof(color));
    memset(flag, false, sizeof(flag));
    
    color[1] = 1;
    q.push(1);
    flag[1] = true;
    while (!q.empty())
    {
        int pre = q.front();
        for (int i = 0; i < v[pre].size(); i++)
        {
            if (color[v[pre][i]] == EMPTY)
            {
                color[v[pre][i]] = (color[pre] == BLACK) ? WHITE : BLACK;
                flag[v[pre][i]] = true;
                q.push(v[pre][i]);
            }
            else if (color[pre] == color[v[pre][i]])
                return false;
        }
        q.pop();
    }    
    return true;    
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);    
    }
    if (bfs())
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;    
}