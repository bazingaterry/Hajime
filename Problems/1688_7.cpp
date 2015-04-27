#include "bits/stdc++.h"
using namespace std;

int jump(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	else if (n == 4)
		return 7;
	else if (n == 5)
		return 13;
	else
		return jump(n - 1) + jump(n - 2) + jump(n - 3);
}

int main(int argc, char const *argv[])
{
	int m;
	cin >> m;
	while (m--)
	{
		int n;
		cin >> n;
		cout << jump(n) << endl;
	}
	

	return 0;
}