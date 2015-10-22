#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    while (cin >> N >> K)
    {
        int dis[10010][10010];
        for (int i = 0; i < N - 1; ++i)
        {
            int X, Y, D;
            cin >> X >> Y >> D;
            dis[X][Y] = D;
            dis[Y][X] = D;
        }
        
    }
	return 0;
}