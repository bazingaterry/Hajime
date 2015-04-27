#include <iostream>
using namespace std;

int main()
{
	int n;
	int k=2;
	
	cin >> n;
	
	while(k<n)
	{
		if (n%k!=0) k++;
		else 
		{
			n=n/k;
			cout << k <<endl;
			k=2;
		}	
	}
	cout << k <<endl;
	return 0;
}
