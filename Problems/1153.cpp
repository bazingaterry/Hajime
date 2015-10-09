#include "iostream"
using namespace std;

const int SIZE = 8;

const int WAY = 8;
const int DX[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int DY[] = {2, -2, 1, -1, 2, -2, 1, -1};

int path[SIZE * SIZE][2];

bool hasReached[SIZE][SIZE] = {};

bool check(int x, int y)
{
    if (x < SIZE && y < SIZE && x >= 0 && y >= 0 && hasReached[x][y] == false)
        return true;
    else
        return false;
}

void print()
{
    for (int i = 0; i < SIZE * SIZE; ++i)
    {
        cout << path[i][0] << ',' << path[i][1] << ' ';
    }
}

void dfs(int x, int y, int step)
{
    path[step][0] = x;
    path[step][1] = y;
    hasReached[x][y] = true;
    
    if (step >= SIZE * SIZE - 1)
    {
        print();
        exit(0);
    }
    
    for (int i = 0; i < WAY; ++i)
    {
        if (check(x + DX[i], y + DY[i]) == true)
        {
            dfs(x + DX[i], y + DY[i], step + 1);
            hasReached[x + DX[i]][y + DY[i]] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    dfs(x, y, 0);
    return 0;
}