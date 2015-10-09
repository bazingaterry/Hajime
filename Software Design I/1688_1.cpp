#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= (n + 1) / 2; ++i)
	{
		for (int j = 1; j <  i; ++j)	//	print -
		{
			cout << '-';
		}

		for (int j =  1; j <= n - 2 * (i - 1) ; ++j)	// print +
		{
			cout << '+';
		}

		for (int j = 1; j <  i; ++j)	//	print -
		{
			cout << '-';
		}

		cout << endl;
	}

	for (int i = (n + 1) / 2 - 1; i >= 1; --i)
	{
		for (int j = 1; j <  i; ++j)	//	print -
		{
			cout << '-';
		}

		for (int j =  1; j <= n - 2 * (i - 1) ; ++j)	// print +
		{
			cout << '+';
		}

		for (int j = 1; j <  i; ++j)	//	print -
		{
			cout << '-';
		}

		cout << endl;
	}
	return 0;
}