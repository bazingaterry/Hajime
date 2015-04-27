#include <iostream>
using namespace std;

int main()
{
	int n;
	bool isMag=1;
	
	cin >> n;	
	
	for (int i=1;i<=4;i++)
	{
		if (n%10!=8&&n%10!=1) isMag=0;
		n=n/10;
	}
	
	if (isMag) cout << "YES" <<endl;
	else cout << "NO" <<endl;
	
	return 0;
}
