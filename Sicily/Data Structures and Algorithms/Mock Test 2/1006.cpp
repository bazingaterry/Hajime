#include "iostream"
#include "vector"
using namespace std;

const int MAXSIZE = 210;
const int INF = 10000 * MAXSIZE * MAXSIZE;

int main(int argc, char const *argv[])
{
    int N, M;
    while (cin >> N >> M)
    {
        int gra[MAXSIZE][MAXSIZE];
        for (int i = 0; i < MAXSIZE; ++i)
        {
            for (int j = 0; j < MAXSIZE; ++j)
            {
                if (i != j) gra[i][j] = INF;
                else gra[i][j] = 0;
            }
        }
        for (int i = 0; i < M; ++i)
        {
            int A, B, X;
            cin >> A >> B >> X;
            gra[A][B] = min(X, gra[A][B]);
            gra[B][A] = min(X, gra[B][A]);
        }
        int S, T;
        cin >> S >> T;
        for (int k = 0; k < N; ++k)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    if (gra[i][j] > gra[i][k] + gra[k][j])
                        gra[i][j] = gra[i][k] + gra[k][j];
                }
            }
        }
        if (gra[S][T] == INF)
            cout << -1 << '\n';
        else
            cout << gra[S][T] << '\n';
    }
    return 0;
}