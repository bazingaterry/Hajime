#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int rabbit (int n)
{
	if (n <= 2)
		return 2;
	else
		return rabbit(n-1) + rabbit(n - 2);
}


int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n && n != -1)
	{
		cout << rabbit(n) << endl;
	}

	return 0;
}
