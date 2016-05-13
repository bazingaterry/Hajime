#include "iostream"
#include "queue"
#include "cstring"
using namespace std;

const int SIZE = 210;

bool path[SIZE][SIZE];
bool flag[SIZE];

int main(int argc, char const *argv[])
{
	int N;
	while (cin >> N && N)
	{
		memset(path, false, sizeof(path));
		memset(flag, false, sizeof(flag));
		int M;
		cin >> M;
		while (M--)
		{
			int i, j;
			cin >> i >> j;
			path[i][j] = true;
		}
		queue<int> q;
		flag[0] = true;
		q.push(0);
		while(!q.empty())
		{
			int i = q.front();
			for (int j = 0; j < N; ++j)
			{
				if (path[i][j] && !flag[j])
				{
					flag[j] = true;
					q.push(j);
				}
			}
			q.pop();
		}
		if (flag[N - 1])
			cout << "I can post the letter\n";
		else
			cout << "I can't post the letter\n";
	}
	return 0;
}