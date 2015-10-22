#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=pow(10,n-1);i<=pow(10,n)-1;i++)
	{
		int sum=0;
		int test=i;
		for (int t=1;t<=n;t++)
		{
			int k=test%10;
			sum=sum+pow(k,n);
			test=test/10;
		}
		if (sum==i) cout << i <<endl;
	}
	
	return 0;
}
