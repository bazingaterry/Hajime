#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n==1) 
		return 0;
	else
	{
		for (int i=2;i<=sqrt(n);i++)
		{
			if (n%i==0) return 0;
		}
		return 1;
	}
}

int fx (int x)
{
	if (isPrime(x))
		return 0;

	int fac[7],numoff=0;//find factors
	int mod=2;
	int diffmod=0;
	int cpx=x;
	while (x!=1)
	{
		if (x%mod==0)
		{
			fac[numoff]=mod;
			numoff++;
			x=x/mod;
			if (numoff!=0&&mod!=fac[numoff-2])
				diffmod++;
			mod=1;
		}
		mod++;
	}

	int sum=0;
	for (int i=0;i<numoff;i++)
		sum+=fx(cpx/fac[i]);
	sum+=diffmod;
	return sum;

}



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << fx(n) << endl;



	return 0;
}
