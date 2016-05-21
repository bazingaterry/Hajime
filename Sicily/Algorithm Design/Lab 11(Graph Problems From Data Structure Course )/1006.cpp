#include "iostream"
#include "cstring"
#include "vector"
using namespace std;

const int staffAmount = 10001;

int n, m;
vector<int> demand[staffAmount];
int inDeg[staffAmount] = {};
int finalBonus[staffAmount] = {};
bool hasVisited[staffAmount] = {};
bool flag = true;

void dfs(int staff, int bonus)
{
    if (hasVisited[staff])
    {
        flag = false;
        return;
    }
    else if (bonus > finalBonus[staff])
    {
        finalBonus[staff] = bonus;
        hasVisited[staff] = true;
        for (int i = 0; i < demand[staff].size() && flag; ++i)
            dfs(demand[staff][i], bonus + 1);
        hasVisited[staff] = false;
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        demand[b].push_back(a);
        inDeg[a]++;
    }
    for (int i = 1; i <= n && flag; ++i)
    {
        if (inDeg[i] == 0)
        {
            memset(hasVisited, false, sizeof(hasVisited));
            dfs(i, 100);
        }
    }
    int total = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (finalBonus[i] == 0)
        {
            flag = false;
            break;
        }
        else
            total += finalBonus[i];
    }
    if (flag)
        cout << total << endl;
    else
        cout << "Poor Xed\n";
    return 0;
}
