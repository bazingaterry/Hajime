#include "iostream"
#include "algorithm"
#include "queue"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
    int N, S, T;
    bool mat[100][100];
    while (cin >> N >> S >> T)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> mat[i][j];
            }
        }

        bool flag[100] = {};
        queue<int> q;
        q.push(S);
        flag[S] = true;
        while (!q.empty())
        {
        	int pre = q.front();
        	q.pop();
        	for (int i = 0; i < N; ++i)
        	{
        		if (mat[pre][i] && !flag[i])
        		{
        			q.push(i);
        			flag[i] = true;
        		}
        	}
        }
        if (flag[T])
        	cout << "yes\n";
        else
        	cout << "no\n";
    }
    return 0;
}