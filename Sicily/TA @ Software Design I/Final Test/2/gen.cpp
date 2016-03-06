#include "iostream"
#include "cstdlib"
using namespace std;

int path[100][2];
int m;

int next(int n, int k)	//	gen n to 100
{
	if (k > m)
		k = m;
	int diff = k - n - 1;
	if (diff)
		return rand() % diff + n + 1;
	else
		return k;
}

int main(int argc, char const *argv[])
{
	while (cin >> m)
	{
		for (int i = 1; i < m; ++i)
		{
			path[i][0] = next(i, i + 4);
			path[i][1] = next(i, i + 4);
			if (path[i][0] == path[i][1])
			{
				if (rand() % 2)
					path[i][0] = 0;
				else 
					path[i][1] = 0;
			}
		}
		cout << m << endl;
		for (int i = 1; i <= m; ++i)
		{
			cout << i  << ' ' << path[i][0] << ' '<< path[i][1] << endl;
		}
	}
	return 0;
}