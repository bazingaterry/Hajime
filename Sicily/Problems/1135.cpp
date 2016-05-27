#include "iostream"
#include "queue"
#include "cstring"
using namespace std;

const bool PLAIN = false;
const bool LAKE = true;
const int MAX = 105;

int row, col, dis;
int result;

const int to[4][2] =
{
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool map[MAX][MAX];
int isVis[MAX][MAX][MAX];

class node
{
public:
    int x, y, remainDis;
    int time;
    node(int x, int y, int s, int d)
    {
        this->x = x;
        this->y = y;
        time = s, remainDis = d;
    }
};

inline bool in(const int x, const int y)
{
    return (1 <= x && x <= row) && (1 <= y && y <= col);
}

void read()
{
    cin >> row >> col >> dis;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'P')
                map[i][j] = PLAIN;
            else
                map[i][j] = LAKE;
        }
}

int canGo()
{
    memset(isVis, false, sizeof(isVis));
    queue<node> q;
    q.push(node(1, 1, 0, dis));
    while (!q.empty())
    {
        if (q.front().remainDis == 0)
        {
            for (int j = 0; j < 4; j++)
            {
                int newx = q.front().x + to[j][0];
                int newy = q.front().y + to[j][1];
                if (in(newx, newy) && !isVis[newx][newy][0] && map[newx][newy] == PLAIN)
                {
                    if (newx == row && newy == col)
                    {
                        result = q.front().time + 1;
                        return true;
                    }
                    else
                    {
                        isVis[newx][newy][0] = true;
                        q.push(node(newx, newy, q.front().time + 1, 0));
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= q.front().remainDis; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int newx = q.front().x + to[j][0];
                    int newy = q.front().y + to[j][1];
                    for (int k = 0; k < i - 1; ++k)
                    {
                        newx += to[j][0];
                        newy += to[j][1];
                    }
                    if (in(newx, newy) && !isVis[newx][newy][q.front().remainDis - i] && map[newx][newy] == PLAIN)
                    {
                        if (newx == row && newy == col)
                        {
                            result = q.front().time + 1;
                            return true;
                        }
                        else
                        {
                            isVis[newx][newy][q.front().remainDis - i] = true;
                            q.push(node(newx, newy, q.front().time + 1, q.front().remainDis - i));
                        }
                    }
                }
            }
        }
        q.pop();
    }
    return false;
}

int main(int argc, char const *argv[])
{
    read();
    if (canGo())
        cout << result << endl;
    else
        cout << "impossible\n";

}
