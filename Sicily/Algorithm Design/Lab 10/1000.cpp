#include "iostream"
#include "queue"
using namespace std;

struct node
{
    int x, y, step;
    node(const string& s)
    {
        x = s[0] - 'a';
        y = s[1] - '1';
        step = 0;
    }
    node(int x, int y, int step)
    {
        this->x = x;
        this->y = y;
        this->step = step;
    }
    bool operator==(const node& n)
    {
        return this->x == n.x && this->y == n.y;
    }
    bool isSafe(bool isVis[8][8])
    {
        return 0 <= x && x <= 7 && 0 <= y && y <= 7 && !isVis[x][y];
    }
};

int bfs(const node& begin, const node& des)
{
    const int dir[][2] =
    {
        {-2, -1}, {-1, -2}, {2, 1}, {1, 2},
        {-2, 1}, {-1, 2}, {1, -2}, {2, -1}
    };
    bool isVis[8][8] = {};
    isVis[begin.x][begin.y] = true;
    queue<node> q;
    q.push(begin);
    while (!q.empty())
    {
        if (q.front() == des)
            return q.front().step;
        else
        {
            int currX = q.front().x;
            int currY = q.front().y;
            int currStep = q.front().step;
            for (int i = 0; i < 8; ++i)
            {
                node next(currX + dir[i][0], currY + dir[i][1], currStep + 1);
                if (next.isSafe(isVis)) q.push(next);
            }
            q.pop();
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string begin, des;
        cin >> begin >> des;
        cout << "To get from " << begin << " to " << des
        << " takes " << bfs(node(begin), node(des)) << " knight moves.\n";
    }
    return 0;
}
