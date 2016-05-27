#include "iostream"
#include "cstdio"
#include "cstring"
#include "queue"

using namespace std;

const int MAX = 25;

bool isVisited[MAX][MAX][MAX][MAX];
int n, m, px, py, hx, hy;
char map[MAX][MAX], pMove[5] = "NSWE", hMove[5];

class State
{
public:
    int px, py;
    int hx, hy;
    int step;
    State(int px, int py, int hx, int hy, int step = 0)
    {
        this->px = px;
        this->py = py;
        this->hx = hx;
        this->hy = hy;
        this->step = step;
    }
    bool isAvail() const
    {
        return px >= 0 && px < n &&  py >= 0 && py < m
            && hx >= 0 && hx < n && hy >= 0 && hy < m
            && map[px][py] == '.' && map[hx][hy] != '!'
            && !isVisited[px][py][hx][hy];
    }
    bool isSafe(const State &s) const
    {
        return (px == s.hx && py == s.hy && hx == s.px && hy == s.py) || (px == hx && py == hy);
    }
    void makeNextPosition(const char dir1, const char dir2)
    {
        switch(dir1)
        {
            case 'N': px--; break;
            case 'S': px++; break;
            case 'W': py--; break;
            case 'E': py++; break;
        }
        int oldx = hx, oldy = hy;
        switch(dir2)
        {
            case 'N': hx--; break;
            case 'S': hx++; break;
            case 'W': hy--; break;
            case 'E': hy++; break;
        }
        if (map[hx][hy] == '#')
        {
            hx = oldx;
            hy = oldy;
        }
        step++;
    }
};
int bfs()
{
    memset(isVisited, false, sizeof(isVisited));
    queue<State> que;
    que.push(State(px, py, hx, hy));
    isVisited[px][py][hx][hy] = true;
    while (!que.empty())
    {
        if (que.front().step > 255) return -1;
        for (int i = 0; i < 4; i ++)
        {
            State next = que.front();
            next.makeNextPosition(pMove[i], hMove[i]);
            if (next.isAvail())
            {
                isVisited[next.px][next.py][next.hx][next.hy] = true;
                if (next.isSafe(que.front())) return next.step;
                else que.push(next);
            }
        }
        que.pop();
    }
    return -1;
}

void readMap()
{
    for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++)
    {
        cin >> map[i][j];
        if (map[i][j] == 'H')
        {
            hx = i;
            hy = j;
            map[i][j] = '.';
        }
        else if (map[i][j] == 'P')
        {
            px = i;
            py = j;
            map[i][j] = '.';
        }
    }
    cin >> hMove;
}

int main(int argc, char const *argv[])
{
    while (cin >> n >> m)
    {
        readMap();
        int result = bfs();
        if (result == -1) cout << "Impossible\n";
        else cout << result << endl;
    }
    return 0;
}
