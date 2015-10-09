#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int m;
	cin >> m;
	while (m--)
	{
		int n;
        cin >> n;
		cout << n * n * (n + 1) * (n + 1) / 4 << endl;
	}
	return 0;
}