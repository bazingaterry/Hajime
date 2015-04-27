#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == d)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}