#include "iostream"
#include "cstring"
#include "vector"
#include "algorithm"
using namespace std;

const int SIZEX = 6;
const int SIZEY = 5;

const int dir[][2] = {
    {-2, -1}, {-1, -2}, {2, 1}, {1, 2},
    {-2, 1}, {-1, 2}, {1, -2}, {2, -1}
};

bool map[SIZEX][SIZEY];
int way[SIZEX * SIZEY + 1];
bool isFound;

bool inline inMap(int x, int y)
{
    return 0 <= x && x < SIZEX && 0 <= y && y < SIZEY;
}

class Pos
{
public:
    int x, y, available;
    Pos(int x, int y) : x(x), y(y)
    {
        available = 0;
        for (int i = 0; i < 8; ++i)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if (inMap(newx, newy) && !map[newx][newy]) available++;
        }
    }
    bool operator< (const Pos& p) const
    {
        return this->available < p.available;
    }
};

void init()
{
    memset(map, 0, sizeof(map));
    isFound = false;
}

void dfs(int x, int y, int step)
{
    if (step == SIZEX * SIZEY)
        isFound = true;
    else
    {
        vector<Pos> v;
        for (int i = 0; i < 8; ++i)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if (inMap(newx, newy) && !map[newx][newy])
                v.push_back(Pos(newx, newy));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() && !isFound; ++i)
        {
            int newx = v[i].x;
            int newy = v[i].y;
            map[newx][newy] = true;
            way[step + 1] = newy * SIZEX + newx + 1;
            dfs(newx, newy, step + 1);
            map[newx][newy] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    int start;
    while (cin >> start && start != -1)
    {
        init();
        way[1] = start;
        int y = (start - 1) / SIZEX;
        int x = (start - 1) % SIZEX;
        map[x][y] = true;
        dfs(x, y, 1);
        cout << way[1];
        for (int i = 2; i <= SIZEX * SIZEY; ++i)
            cout << ' ' << way[i];
        cout << endl;
    }
    return 0;
}
