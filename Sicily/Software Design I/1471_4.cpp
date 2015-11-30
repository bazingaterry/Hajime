#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
	if (n <= 1)
		return false;
	else
	{
		for (long long i = 2; i <= sqrt(n); i++)
			if (n % i == 0) return false;
		return true;
	}
}

int main()
{
	int t;
	cin >> t;
	int count = 0;
	for (int i = 1; i <= t; i++)
	{
		long long n;
		cin >> n;
		double m = sqrt(n);
		if (m == (int)m && isPrime(m))
			count++;
	}
	cout << count << endl;
	return 0;
}
