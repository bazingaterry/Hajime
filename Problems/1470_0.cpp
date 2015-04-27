#include <iostream>
using namespace std;

int main()
{
	int n1,n2;
	int gcd=1;//The greatest common divisor
	int divisor=2;
	
	cin >> n1 >> n2;
	
	while (divisor<=n1&&divisor<=n2)
	{
		if (n1%divisor==0&&n2%divisor==0)
		{
			gcd*=divisor;
			n1=n1/divisor;
			n2=n2/divisor;
			divisor=2;
		}
		
		divisor++;
	}
	
	cout << gcd << endl;
	
	return 0;
	
}
