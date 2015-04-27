#include <iostream>
#include "iomanip"
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		double n;
		int m;
		cin >> n >> m;
		double result = 0;
		
		double nc = n;
		for (int i = 1; i <= m; i++)
		{
			result += n;
			n = n / 2;
		}

		cout << fixed << setprecision(1) << result << " " << nc / pow(2, m) << endl;
	}


	return 0;
}
