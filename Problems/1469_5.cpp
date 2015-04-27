#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long num)
{
	if (num==1) return 0;
	else 
	{
		int i;
		for (i=2;i<=sqrt(num);i++)
		{
			if (num%i==0) return 0;
		}
		return 1;
	}
}


int main()
{
	int n;
	int count=0;
	cin >> n;
	
	for (int p=1;p<=n;p++)
	{
		if (isPrime(pow(2,p)-1)) count++;
	}
	
	cout << count << endl;
	
	return 0;
}

