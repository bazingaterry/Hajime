#include "iostream"
#include "cmath"
#include "cstring"
using namespace std;

int n;

bool isUsed[21];
int queue[21];

bool isPrime(int n)
{
    if (n <= 0)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void dfs(int i)
{
	if (i == n + 1)
	{
		cout << queue[1];
		for (int k = 2; k <= n; ++k)
		{
			cout << " " << queue[k];
		}
		cout << endl;
		return;
	}
	else if (i == n)
	{
		for (int t = 2; t <= n; ++t)
		{
			if (isPrime(queue[i - 1] + t) && !isUsed[t] && isPrime(1 + t))
			{
				queue[i] = t;
				isUsed[t] = true;
				dfs(i + 1);
				isUsed[t] = false;
			}
		}
	}
	else
	{
		for (int t = 2; t <= n; ++t)
		{
			if (isPrime(queue[i - 1] + t) && !isUsed[t])
			{
				queue[i] = t;
				isUsed[t] = true;
				dfs(i + 1);
				isUsed[t] = false;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int c = 1;
	while (cin >> n)
	{
		cout << "Case " << c++ << ":\n";
		memset(isUsed, 0, sizeof(isUsed));
		memset(queue, 0, sizeof(queue));
        queue[1] = 1;
        dfs(2);
        cout << endl;
	}
	return 0;
}