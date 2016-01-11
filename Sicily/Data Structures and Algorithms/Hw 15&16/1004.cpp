#include <vector>
#include <cstdio>
#include <set>
using namespace std;

const int SIZE = 100010;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        vector<int> v[SIZE];
        set<int> s;
        int n, m;
        int inDegree[SIZE] = {};
        scanf("%d %d", &n, &m);
        while (m--)
        {
            int i, j;
            scanf("%d %d", &i, &j);
            v[i].push_back(j);
            inDegree[j]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == 0)
               s.insert(i);
        }
        while (!s.empty())
        {
            int task = *s.begin();
            s.erase(s.begin());
            printf("%d ", task);
            int size = v[task].size();
            for (int i = 0; i < size; i++)
            {
                inDegree[v[task][i]]--;
                if (inDegree[v[task][i]] == 0)
                    s.insert(v[task][i]);
            }     
        }
        printf("\n");
    }
    return 0;   
}