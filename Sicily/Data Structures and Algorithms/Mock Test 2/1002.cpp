#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
using namespace std;

const int MAXSIZE = 100010;

int main(int argc, char const *argv[])
{
    int T;
    while (cin >> T)
    {
        while (T--)
        {
            int n, m;
            cin >> n >> m;
            vector<int> vec[MAXSIZE];
            int inDegree[MAXSIZE] = {};
            while(m--)
            {
                int u, v;
                cin >> u >> v;
                vec[u].push_back(v);
                inDegree[v]++;
            }
            int count = 0;
            queue<int> q;
            for (int i = 1; i <= n; ++i)
            {
                if (inDegree[i] == 0)
                    q.push(i);
            }
            while (!q.empty())
            {
                const int i = q.front();
                q.pop();
                inDegree[i] = -1;
                for (int j = 0; j < vec[i].size(); ++j)
                {
                    if(--inDegree[vec[i][j]] == 0)
                        q.push(vec[i][j]);
                }
                count++;
            }
            if (count != n)
                cout << "There exists a cycle.\n";
            else
                cout << "It is acyclic.\n";
        }
    }
    return 0;
}