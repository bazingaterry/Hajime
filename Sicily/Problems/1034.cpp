#include "iostream"
#include "cstring"
#include "vector"
#include "algorithm"
using namespace std;

const int MAX = 102;

int vertex, edge;
vector<int> edges[MAX];
bool isForest;
bool hasVisited[MAX];
int width[MAX];
int depth, wid;
int inDeg[MAX];

void dfs(int curNode,int level)
{
    if(hasVisited[curNode])
    {
        isForest = false;
        return;
    }
    hasVisited[curNode] = true;
    width[level]++;
    wid = max(wid, width[level]);
    depth = max(depth, level);
    for (int i = 0; i < edges[curNode].size(); ++i)
        dfs(edges[curNode][i], level + 1);
}

void check()
{
    if (isForest)
        for (int i = 1; i <= vertex; ++i)
            if(inDeg[i] == 0) dfs(i, 0);
    for (int i = 1; i <= vertex; ++i)
        if(!hasVisited[i]) isForest = false;
}

void init()
{
    for (int i = 0; i <= vertex; ++i) edges[i].clear();
    memset(hasVisited, false, sizeof(hasVisited));
    memset(width, false, sizeof(width));
    memset(inDeg, false, sizeof(inDeg));
    wid = 0;
    depth = 0;
    isForest = true;
}

int main(int argc, char const *argv[])
{
    while (cin >> vertex >> edge && vertex)
    {
        init();
        for (int i = 0; i < edge; ++i)
        {
            int begin, end;
            cin >> begin >> end;
            edges[begin].push_back(end);
            inDeg[end]++;
            if(inDeg[end] > 1) isForest = false;
        }
        check();
        if (isForest)
            cout << depth << " " << wid <<endl;
        else
            cout << "INVALID\n";
    }
    return 0;
}
