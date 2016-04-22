#include "iostream"
#include "cstring"
using namespace std;

int N;
int cnt;
bool board[10][10];

bool isSafe(int i, int j)
{
    for (int k = 1; k < N; ++k)
    {
        if (i + k <= N && board[i + k][j]) return false;
        if (j + k <= N && board[i][j + k]) return false;
        if (i - k >= 1 && board[i - k][j]) return false;
        if (j - k >= 1 && board[i][j - k]) return false;
        if (i + k <= N && j + k <= N && board[i + k][j + k]) return false;
        if (i - k >= 1 && j + k <= N && board[i - k][j + k]) return false;
        if (i + k <= N && j - k >= 1 && board[i + k][j - k]) return false;
        if (i - k >= 1 && j - k >= 1 && board[i - k][j - k]) return false;
    }
    return true;
}

void dfs(int x, int y, int step)
{
    if (step == N) cnt++;
    else
    {
        for (int i = x; i <= N; ++i)
            for (int j = y; j <= N; ++j)
            {
                if (!board[i][j] && isSafe(i, j))
                {
                    board[i][j] = true;
                    dfs(i+1, 1, step + 1);
                    board[i][j] = false;
                }
            }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> N)
    {
        memset(board, 0, sizeof(board));
        cnt = 0;
        dfs(1, 1, 0);
        cout << cnt << endl;
    }
    return 0;
}
