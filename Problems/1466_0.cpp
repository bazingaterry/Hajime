#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >>n;
	int max;
	for (int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		if (t>max||i==1) max=t;
	}
	cout << max << endl;
	return 0;
}
