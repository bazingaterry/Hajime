#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long maxX=-1000000000;
	long long minX=1000000000;
	long long maxY=-1000000000;
	long long minY=1000000000;
	while (n--)
	{
		long long x,y;
		cin >> x >> y;
		if (x>maxX) maxX=x;
		if (x<minX) minX=x;
		if (y>maxY) maxY=y;
		if (y<minY) minY=y;
	}
	cout << (maxX-minX)*(maxY-minY) << endl;
	return 0;
}
