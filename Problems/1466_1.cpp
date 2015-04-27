#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max1,max2;
	
	for (int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		
		if (t>max1||t==1)
		{
			max2=max1;
			max1=t;
		}
		else if (t>max2) max2=t;
	}
	
	cout << max1 <<" "<< max2 << endl;
	return 0;
}
