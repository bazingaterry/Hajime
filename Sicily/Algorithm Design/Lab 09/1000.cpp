#include "iostream"
#include "queue"
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;

class Point
{
public:
    Point(int x, int y, int step)
    {
        this->x = x;
        this->y = y;
        this->step = step;
    }
    int x;
    int y;
    int step;
};

bool isAvailable(int x, int y, bool isVis[101][101], bool maze[101][101])
{
    return 1 <= x && x <= n && 1 <= y && y <= m && !isVis[x][y] && maze[x][y];
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        bool maze[101][101];
        bool isVis[101][101] = {};
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> maze[i][j];
        int des_x, des_y;
        cin >> des_x >> des_y;
        Point start(1, 1, 0);
        isVis[0][0] = true;
        queue<Point> q;
        q.push(start);
        int result = -1;
        while(!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int step = q.front().step;
            if (x == des_x && y == des_y)
            {
                result = step;
                break;
            }
            else
                for (int i = 0; i < 4; ++i)
                    if (isAvailable(x + dx[i], y + dy[i], isVis, maze))
                    {
                        isVis[x + dx[i]][y + dy[i]] = true;
                        q.push(Point(x + dx[i], y + dy[i], step + 1));
                    }
            q.pop();
        }
        cout << result << endl;
    }
}
