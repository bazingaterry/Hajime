#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n==1) return 0;
	else
	{
		for (int i=2;i<=sqrt(n);i++)
		{
			if (n%i==0) return 0;
		}
		return 1;
	}
}

int main()
{
	int t;
	cin >> t;
	
	int c=0;
	
	for (int i=1;i<=t;i++)
	{
		long long n;
		cin >> n;
		
		double m=sqrt(n);
		
		if (m==(int)m&&isPrime(m)) c++;
	}
	cout << c <<endl;

	return 0;
}
