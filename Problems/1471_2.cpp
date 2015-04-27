#include <iostream>
using namespace std;

int main()
{
	int n,a,b;
	
	cin >> n >> a >> b;	
	
	for (int i=1;i<=n;i++)
	{
		if (i%a==0||i%b==0) cout << i <<endl;
	}
	
	return 0;
}
