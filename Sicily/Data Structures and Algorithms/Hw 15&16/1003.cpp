#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
    cin >> n >> m;
    int gra[110][110] = {};
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        gra[u][v] = 1;
        gra[n+1][v]++;
    }
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (gra[n+1][i] == 0)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (gra[i][j] == 1)
                {
                    gra[i][j] = 0;
                    gra[n+1][j]--;
                }
            }
            gra[n+1][i] = -1;
            i = 0;
            count++;
        }
    }
    if (count == n)
        cout << "1\n";
    else
        cout << "0\n";
	return 0;
}