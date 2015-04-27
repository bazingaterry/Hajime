#include <iostream>
using namespace std;

int main()
{
	int n,t,max;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> t;
		if (t>max||i==1) max=t;
	}
	cout << max <<endl;
	
	return 0;
}
