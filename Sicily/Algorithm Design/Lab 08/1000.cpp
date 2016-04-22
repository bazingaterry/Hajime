#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

#define mkst(v) (1 << (v))
#define ifin(u, r) (u & (1 << (r)))
#define revf(u, v) (u - (1 << (v)))
#define dis(r, v) sqrt(pow(cities[r].x - cities[v].x, 2) + \
                       pow(cities[r].y - cities[v].y, 2))

struct City
{
    int x, y;
} cities[21];

const double INF = 10e8;
int N;
double dp[1444444][21];
double dis[21][21];

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> cities[i].x >> cities[i].y;
        for (int s = 1; s < mkst(N - 1); ++s)
            for (int i = 1; i <= N; ++i)
                dp[s][i] = INF;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dis[i][j] = dis(i, j);
        for (int i = 1; i <= N; i++)
            dp[1][i] = dis[1][i];
        for (int s = 2; s < mkst(N - 1); ++s)
            for (int i = 2; i <= N; ++i)
                for (int j = 2; j <= N; j++)
                    if (ifin(s, j - 1))
                        dp[s][i] = min(dp[s][i], dp[revf(s, j - 1)][j] + dis[j][i]);
        cout << setprecision(2) << fixed << dp[mkst(N - 1) - 1][N] << endl;
    }
    return 0;
}
