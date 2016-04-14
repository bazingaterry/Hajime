#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

const int SIZE = 10001;

class Road
{
public:
    int next;
    int dis;
    Road(int next, int dis) : next(next), dis(dis) {}
};

int N, K;
vector<Road> map[SIZE];
bool isVis[SIZE];

int dfs(int loc, int dis)
{
    int maxDis = dis;
    for (vector<Road>::iterator it = map[loc].begin(); it != map[loc].end(); ++it)
    {
        if (isVis[it->next]) continue;
        isVis[it->next] = true;
        maxDis = max(maxDis, dfs(it->next, dis + it->dis));
        isVis[it->next] = false;
    }
    return maxDis;
}

int main(int argc, char const *argv[])
{
    while (cin >> N >> K)
    {
        memset(map, 0, sizeof(map));
        memset(isVis, 0, sizeof(isVis));
        for (int i = 0; i < N - 1; ++i)
        {
            int x, y, d;
            cin >> x >> y >> d;
            map[x].push_back(Road(y, d));
            map[y].push_back(Road(x, d));
        }
        isVis[K] = true;
        cout << dfs(K, 0) << endl;
    }
    return 0;
}
