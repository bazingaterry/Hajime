#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 100010;

int go[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

struct point
{
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    point(const point& p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    int x, y;
    bool operator==(point& p)
    {
        return x == p.x && y == p.y;
    }
};

inline bool inRange(const point& p)
{
    return 1 <= p.x && p.x <= n && 1 <= p.y && p.y <= m;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        bool map[110][110];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> map[i][j];

        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        point start(sx, sy);
        point des(tx, ty);

        bool flag = false;
        queue<point> q;
        q.push(start);
        map[sx][sy] = false;
        while(!q.empty())
        {
            point now = q.front();
            q.pop();
            if (now == des)
            {
                flag = true;
                break;
            }
            else
            {
                for (int i = 0; i < 4; ++i)
                {
                    point p = now;
                    p.x += go[i][0];
                    p.y += go[i][1];
                    if (map[p.x][p.y] && inRange(p))
                    {
                        q.push(p);
                        map[p.x][p.y] = false;
                    }
                }
            }
        }
        cout << flag << endl;
    }
    return 0;   
}