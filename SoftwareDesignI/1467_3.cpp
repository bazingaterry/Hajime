#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int p;
	cin >> p;
	if (p!=1) 
	{
		int t;
		for (t=2;t<=p;t++) if (p%t==0) break;
		if (t==p) cout << "Yes" <<endl;
		else cout << "No" <<endl;
	}
	else cout << "No" <<endl;
	return 0;
}
