#include "iostream"
using namespace std;

const int dir[][2] =
{
    {-1, 1},
    {1, -1},
    {-1, -1},
    {1, 1},
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};


int gameOfEfil(const int n, const int m)
{
    int k;
    cin >> k;
    int target = 0;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        target |= 1 << (x * m + y);
    }
    int result = 0;
    for (int mask = 0; mask < 1 << (n * m); ++mask)
    {
        int newmask = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
        {
            int newBoard = 0;
            for (int k = 0; k < 8; ++k)
            {
                int newi = (i + dir[k][0] + n) % n;
                int newj = (j + dir[k][1] + m) % m;
                newBoard += mask >> (newi * m + newj) & 1;
            }
            if (mask >> (i * m + j) & 1)
            {
                if (newBoard == 2 || newBoard == 3)
                    newmask |= 1 << (i * m + j);
            }
            else
            {
                if (newBoard == 3)
                    newmask |= 1 << (i * m + j);
            }
        }
        if (newmask == target) result++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n, m;
    int cas = 1;
    while (cin >> n >> m && n && m)
    {
        int result = gameOfEfil(n, m);
        cout << "Case " << cas++ << ": ";
        if (result) cout << result << " possible ancestors.\n";
        else cout << "Garden of Eden.\n";
    }
    return 0;
}
