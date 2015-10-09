#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int m;
	cin >> m;
	while (m--)
	{
		int result = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			result += i*i;
		}
		cout << result << endl;
	}

	return 0;
}
