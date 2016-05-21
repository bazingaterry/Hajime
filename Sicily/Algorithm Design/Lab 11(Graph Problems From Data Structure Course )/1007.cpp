#include <iostream>
using namespace std;

const int MAX = 500;
const int INF = 65537;

int map[MAX][MAX];
int dis[MAX];   //  if it's a binary heap, it will faster
                //  0 means the vertex is already in the tree

int size;

inline int getCloestVertex()
{
    int cloestVertex;
    int cloestDis = INF;
    for (int i = 0; i < size; ++i)
        if (0 < dis[i] && dis[i] < cloestDis)
        {
            cloestVertex = i;
            cloestDis = dis[i];
        }
    return cloestVertex;
}

inline int mst_prim()
{
    // init, start with 0
    for (int i = 0; i < size; i++)
        dis[i] = map[0][i];
    int maxRoad = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        int vertex = getCloestVertex();
        maxRoad = max(maxRoad, dis[vertex]);
        //  add the vertex into the tree
        dis[vertex] = 0;
        //  update distance
        for (int j = 0; j < size; ++j)
            dis[j] = min(dis[j], map[vertex][j]);
    }
    return maxRoad;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> map[i][j];
        cout << mst_prim() << endl;
        if(t) cout << endl;
    }
    return 0;
}
